#ifndef QTAPPLICATION_H
#define QTAPPLICATION_H

#include <vtkAutoInit.h> 
#include <vtkRenderWindow.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);



#include "MyCloud.h"
#include "ui_qtapplication.h"
#include "Tools.h"
#include "AboutWin.h"
#include "SimplifyWin.h"
#include "PointSelected.h"

//标准C++头文件引用格式
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include <boost/concept_check.hpp>
#include <pcl/ModelCoefficients.h>

#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/io/obj_io.h>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/common/common.h>
//#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/common/common.h>
#include <pcl/visualization/point_picking_event.h>

#include <pcl/filters/extract_indices.h>
#include <pcl/filters/voxel_grid.h>

#include <pcl/features/normal_3d.h>
#include <pcl/features/boundary.h>

#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/search/kdtree.h>
//#include <pcl/octree/octree_pointcloud.h>
//#include <pcl/octree/octree.h>

#include <pcl/surface/gp3.h>

#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>

#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/segmentation/extract_clusters.h>


#include <QtWidgets/QMainWindow>//contains UI elements
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QFileDialog>
#include <QColorDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "QVTKWidget.h"
#include <QTextEdit>
#include <QTime>
#include <QMouseEvent> 
#include <QDesktopServices> 
#include <QUrl>


//improves readabily
typedef pcl::PointXYZRGBA PointT;
//brief A point structure representing Euclidean xyz coordinates, and the RGBA color
typedef pcl::PointCloud<PointT> PointCloudT;
//brief PointCloud represents the base class in PCL for storing collections of 3D points




class QtApplication : public QMainWindow
{
	Q_OBJECT

public:
	QtApplication(QWidget *parent = 0);
	~QtApplication();
	static void SelectPoint_callback(const pcl::visualization::PointPickingEvent& event, void* args);//静态回调函数
	static QtApplication *pThis;//静态对象指针
	void PointPickingShow(pcl::PointXYZRGBA current_point);
	boost::mutex cloud_mutex;
	struct callback_args		// 用于将参数传递给回调函数的结构
	{
		PointCloudT::Ptr clicked_points_3d;
		pcl::visualization::PCLVisualizer::Ptr viewerPtr;
	};
private:
	Ui::QtApplicationClass ui;

	// Mutex: //


	//点云数据存储
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz;//只有XYZ坐标的点的点云
	
	MyCloud mycloud;//PointXZYRGBA类型的点云
	std::vector<MyCloud> mycloud_vec;  //点云容器
	
	//pcl::visualization::PCLVisualizer::Ptr viewer = new pcl::visualization::PCLVisualizer("viewer");
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
	//pcl::visualization::PCLVisualizer::Ptr viewer;

	long total_points = 0;//保存所有点云总点数

	unsigned int red = 255;
	unsigned int green = 255;
	unsigned int blue = 255;
	unsigned int point_size = 2;
	std::vector<int> randomcolor;
	std::vector<int> bgcolor;
	
	QTime timer;//计时器,记录某个动操作执行的时间
	bool enable_console = true; // 操作记录的可用状态
	
	//子窗口实例化
	AboutWin *aboutwin = new AboutWin(this);
	SimplifyWin *simplifywin = new SimplifyWin(this);
	PointSelected *pointselected = new PointSelected(this);


	/***** 一些需要的有用的方法 ***/
	void initial();//初始化vtk部件
	void showPointcloud();  //显示点云
	void showPointcloudAdd();  //添加给viewer，显示点云

	void setCloudColor(unsigned int r, unsigned int g, unsigned int b);//设置点云颜色
	void setA(unsigned int a);//设置点云透明度
	
	void setPropertyTable(int clouds,int points,int totalpoints,QString RGB);//设置属性管理窗口
	void setConsoleTable();//设置操作记录管理窗口
	void setRGBDock();//设置RGBDock窗口
	void consoleLog(QString operation, QString subname, QString filename, QString note);//操作记录填写函数
	
	pcl::PointCloud<pcl::PointXYZ>::Ptr transformPointCloud(MyCloud cloud_RGBA);//将MyCloud(PointCloud_RGBA)转换成PointCloud_XYZ
	void saveResult(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_result);
	


private slots:

	/***** 以下槽函数与UI界面上菜单动作连接 *****/
	// 文件菜单槽
	void Open();
	void Add();
	void Save();
	void Savemulti(QString savename);
	void Clear();
	void Exit();
	// 视图菜单槽
	void HideDataDock();
	void HidePropertiesDock();
	void HideConsoleDock();
	void HideRGBDock();		
	// 显示菜单槽
	void RandomColor();
	void PointColorChange();
	void BackgroundColorChange();
	void MainView();//主视图
	void LeftView();//左视图
	void TopView();//俯视图
	//三维图形菜单槽
	void CreateSphere();//绘制一个三维球面

	// 点云简化菜单槽
	void Simplify();
	void ReceiveData(QString rate);
	void Simplify2(int cloud_id,int rate);
	void BoundingBox();
	// 特征提取菜单槽
	void SelectPoint();
	void Boundary();
    // 三维重建菜单槽
	void Surface();//法线估计、曲面重建、网格面片显示
	void Wireframe();//法线估计、曲面重建、网格线框显示
	// 帮助菜单槽
	void Help();
	void About();

	//工具栏菜单槽
	//void Cordinate();


	/***** 颜色管理窗口 *****/
	// 设置点云颜色及大小
	//void radomcolorBtnPressed();
	void RGBsliderReleased();
	void PointSize_SliderReleased();
	void PointSize_SliderChanged(int value);
	void Red_SliderChanged(int value);
	void Green_SliderChanged(int value);
	void Blue_SliderChanged(int value);

	// 坐标系及背景颜色复选框
	void CordinateChecked(int value);
	void BackgroundChecked(int value);
	
	
	/***** 点云文件管理窗口 *****/
	// 左键单击点云文件
	void dataSelected(QTreeWidgetItem*, int);
	// 右键单击点云文件，右键响应菜单
	void popMenu_DataTree(const QPoint&);
	void dataHide();
	void dataShow();
	void dataDelete();
	void dataColorChange();
	
	/***** 操作记录管理窗口 *****/
	//右键响应菜单
	void popMenu_Console(const QPoint&);
	void clearConsole();//清空操作记录
	void enableConsole();
	void disableConsole();

};

#endif // QTAPPLICATION_H
