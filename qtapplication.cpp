#include "qtapplication.h"
#include <pcl/point_cloud.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>


QtApplication::QtApplication(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	initial();//初始化	
	
	//***** 菜单栏和工具栏信号和槽函数连接 *****/
	// 文件(connect)
	QObject::connect(ui.action_Open, &QAction::triggered, this, &QtApplication::Open);	
	QObject::connect(ui.action_Add, &QAction::triggered, this, &QtApplication::Add);
	QObject::connect(ui.action_Clear, &QAction::triggered, this, &QtApplication::Clear);	
	QObject::connect(ui.action_Save, &QAction::triggered, this, &QtApplication::Save);
	//QObject::connect(ui.action_SaveAs, &QAction::triggered, this, &QtApplication::SaveAsBinary);
	QObject::connect(ui.action_Exit, &QAction::triggered, this, &QtApplication::Exit);
	// 显示(connect)
	QObject::connect(ui.action_RandomColor, &QAction::triggered, this, &QtApplication::RandomColor);
	QObject::connect(ui.action_PointCloudColorChange, &QAction::triggered, this, &QtApplication::PointColorChange);
	QObject::connect(ui.action_BackgroundColorChange, &QAction::triggered, this, &QtApplication::BackgroundColorChange);
	QObject::connect(ui.action_MainView, &QAction::triggered, this, &QtApplication::MainView);
	QObject::connect(ui.action_LeftView, &QAction::triggered, this, &QtApplication::LeftView);
	QObject::connect(ui.action_TopView, &QAction::triggered, this, &QtApplication::TopView);
	// 视图(connect)
	QObject::connect(ui.action_DataManager, &QAction::triggered, this, &QtApplication::HideDataDock);
	QObject::connect(ui.action_PropertiesManager, &QAction::triggered, this, &QtApplication::HidePropertiesDock);
	QObject::connect(ui.action_ConsoleManager, &QAction::triggered, this, &QtApplication::HideConsoleDock);
	QObject::connect(ui.action_RGBManager, &QAction::triggered, this, &QtApplication::HideRGBDock);
	// 处理(connect)
	QObject::connect(ui.action_Surface, &QAction::triggered, this, &QtApplication::Surface);
	QObject::connect(ui.action_Wireframe, &QAction::triggered, this, &QtApplication::Wireframe);
	// 点云简化(connect)
	QObject::connect(ui.action_Simplify, &QAction::triggered, this, &QtApplication::Simplify);
	// 特征提取(connect)
	QObject::connect(ui.action_Boundary, &QAction::triggered, this, &QtApplication::Boundary);
	// 帮助(connect)
	QObject::connect(ui.action_Help, &QAction::triggered, this, &QtApplication::Help);
	QObject::connect(ui.action_About,&QAction::triggered, this, &QtApplication::About);

	// 工具栏（connect）
	QObject::connect(ui.actionOpen, &QAction::triggered, this, &QtApplication::Open);
	QObject::connect(ui.actionAdd, &QAction::triggered,this,&QtApplication::Add);
	QObject::connect(ui.actionClear, &QAction::triggered, this, &QtApplication::Clear);
	QObject::connect(ui.actionSave, &QAction::triggered, this, &QtApplication::Save);
	//QObject::connect(ui.actionSaveAs, &QAction::triggered, this, &QtApplication::SaveAsBinary);
	QObject::connect(ui.actionRandomColor,&QAction::triggered,this,&QtApplication::RandomColor);
	QObject::connect(ui.actionPointCloudColorChange, &QAction::triggered, this, &QtApplication::PointColorChange);
	QObject::connect(ui.actionBackgroundColorChange, &QAction::triggered, this, &QtApplication::BackgroundColorChange);
	QObject::connect(ui.actionSurface,&QAction::triggered,this,&QtApplication::Surface);
	QObject::connect(ui.actionWireframe, &QAction::triggered, this, &QtApplication::Wireframe);
	QObject::connect(ui.actionHelp, &QAction::triggered, this, &QtApplication::Help);
	QObject::connect(ui.actionAbout, &QAction::triggered, this, &QtApplication::About);
	
	//


	/***** 颜色管理窗口信号和槽函数连接 *****/
	// RGB颜色设置(connect)
	connect(ui.Red_Slider, SIGNAL(valueChanged(int)), this, SLOT(Red_SliderChanged(int)));
	connect(ui.Green_Slider, SIGNAL(valueChanged(int)), this, SLOT(Green_SliderChanged(int)));
	connect(ui.Blue_Slider, SIGNAL(valueChanged(int)), this, SLOT(Blue_SliderChanged(int)));
	connect(ui.Red_Slider, SIGNAL(sliderReleased()), this, SLOT(RGBsliderReleased()));
	connect(ui.Green_Slider, SIGNAL(sliderReleased()), this, SLOT(RGBsliderReleased()));
	connect(ui.Blue_Slider, SIGNAL(sliderReleased()), this, SLOT(RGBsliderReleased()));
	// 点云大小设置(connect)
	connect(ui.PointSize_Slider, SIGNAL(valueChanged(int)), this, SLOT(PointSize_SliderChanged(int)));
	connect(ui.PointSize_Slider, SIGNAL(sliderReleased()), this, SLOT(PointSize_SliderReleased()));
	//坐标系和背景颜色设置(connect)
	connect(ui.Cordinate, SIGNAL(stateChanged(int)), this, SLOT(CordinateChecked(int)));
	connect(ui.Background, SIGNAL(stateChanged(int)), this, SLOT(BackgroundChecked(int)));

	/***** 点云文件管理窗口信号和槽函数连接 *****/
	// 左键单击点云文件(connect)
	connect(ui.tree_PointCloud, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(dataSelected(QTreeWidgetItem*, int)));
	// 右键单击点云文件，右键响应菜单 (connect)
	connect(ui.tree_PointCloud, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(popMenu_DataTree(const QPoint&)));
	
	/***** 操作记录管理窗口信号和槽函数连接 *****/
	connect(ui.table_Console, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(popMenu_Console(const QPoint&)));
}

QtApplication::~QtApplication()
{

}



/*****  一些实用方法实现 *****/

//初始化
void QtApplication::initial()
{
	//界面初始化
	setWindowIcon(QIcon(tr(":/Icon/Resources/Icon/Icon.png")));
	setWindowTitle(tr("My Graduate Design"));

	//点云初始化
	mycloud.cloud.reset(new PointCloudT);
	mycloud.cloud->resize(1);//RGBA点云初始化长宽，height=1无序点云
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	viewer->addPointCloud(mycloud.cloud, "cloud");


	cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
	cloud_xyz->resize(1);
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	viewer->addPointCloud(cloud_xyz, "cloud");

	ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
	ui.qvtkWidget->update();
	
	//窗口控件初始化
	ui.table_Properties->setSelectionMode(QAbstractItemView::NoSelection); // 禁止点击属性管理器的 item
	ui.table_Console->setSelectionMode(QAbstractItemView::NoSelection);  // 禁止点击输出窗口的 item
	ui.tree_PointCloud->setSelectionMode(QAbstractItemView::ExtendedSelection); // 允许 dataTree 进行多选

	setPropertyTable(0, 0, 0, " ");
	//setPropertyTable();//初始化属性管理窗口
	setConsoleTable();//初始化操作记录窗口

	// 输出窗口
	consoleLog(QString::fromLocal8Bit("开始"), "My Graduate Design", "Welcome to My Graduate Design", "DMY");


	// 设置背景颜色为 dark
	viewer->setBackgroundColor(30 / 255.0, 30 / 255.0, 30 / 255.0);
}

//显示点云，不重置相机角度
void QtApplication::showPointcloud()
{
	for (int i = 0; i != mycloud_vec.size(); i++)
	{
		viewer->updatePointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
	}
	//viewer->resetCamera();
	ui.qvtkWidget->update();
}

//添加点云到viewer,并显示点云
void QtApplication::showPointcloudAdd()
{
	for (int i = 0; i != mycloud_vec.size(); i++)
	{
		viewer->addPointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
		viewer->updatePointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
	}
	viewer->resetCamera();//重置相机角度
	ui.qvtkWidget->update();
}

//打开点云文件时，设置点云颜色
void QtApplication::setCloudColor(unsigned int r, unsigned int g, unsigned int b)
{
	// Set the new color
	for (size_t i = 0; i < mycloud.cloud->size(); i++)
	{
		mycloud.cloud->points[i].r = r;
		mycloud.cloud->points[i].g = g;
		mycloud.cloud->points[i].b = b;
		mycloud.cloud->points[i].a = 255;
	}
}

//打开点云文件时，设置点云透明度
void QtApplication::setA(unsigned int a)
{
	for (size_t i = 0; i < mycloud.cloud->size(); i++)
	{
		mycloud.cloud->points[i].a = a;
	}
}

//设置属性管理窗口
void QtApplication::setPropertyTable(int clouds, int points, int totalpoints, QString RGB)
{

	QStringList header;
	header << QString::fromLocal8Bit("属性") << QString::fromLocal8Bit("值");
	ui.table_Properties->setHorizontalHeaderLabels(header);
	ui.table_Properties->setItem(0, 0, new QTableWidgetItem(QString::fromLocal8Bit("点云数")));
	ui.table_Properties->setItem(1, 0, new QTableWidgetItem(QString::fromLocal8Bit("点数")));
	ui.table_Properties->setItem(2, 0, new QTableWidgetItem(QString::fromLocal8Bit("总点数")));
	ui.table_Properties->setItem(3, 0, new QTableWidgetItem(QString::fromLocal8Bit("颜色")));


	ui.table_Properties->setItem(0, 1, new QTableWidgetItem(QString::number(clouds)));
	ui.table_Properties->setItem(1, 1, new QTableWidgetItem(QString::number(points)));
	ui.table_Properties->setItem(2, 1, new QTableWidgetItem(QString::number(totalpoints)));
	ui.table_Properties->setItem(3, 1, new QTableWidgetItem(RGB));

}

//初始化设置操作记录管理窗口
void QtApplication::setConsoleTable(){
	// 设置输出窗口
	QStringList header2;
	header2 << QString::fromLocal8Bit("时间") << QString::fromLocal8Bit("操作") << QString::fromLocal8Bit("操作对象") << QString::fromLocal8Bit("详细") << QString::fromLocal8Bit("备注");
	ui.table_Console->setHorizontalHeaderLabels(header2);
	ui.table_Console->setColumnWidth(0, 140);
	ui.table_Console->setColumnWidth(1, 180);
	ui.table_Console->setColumnWidth(2, 180);
	ui.table_Console->setColumnWidth(3, 280);

	ui.table_Console->verticalHeader()->setDefaultSectionSize(22); //设置行距

	ui.table_Console->setContextMenuPolicy(Qt::CustomContextMenu);

}

//设置RGBDock窗口
void QtApplication::setRGBDock()
{
	ui.Red_lcdNumber->setProperty("value", QVariant(255));
	ui.Red_Slider->setSliderPosition(255);
	ui.Green_lcdNumber->setProperty("value", QVariant(255));
	ui.Green_Slider->setSliderPosition(255);
	ui.Blue_lcdNumber->setProperty("value", QVariant(255));
	ui.Blue_Slider->setSliderPosition(255);
	ui.PointSize_lcdNumber->setProperty("value", QVariant(1));
	ui.PointSize_Slider->setSliderPosition(1);
	ui.Cordinate->setCheckState(Qt::CheckState::Unchecked);
	viewer->removeCoordinateSystem();
	ui.Background->setCheckState(Qt::CheckState::Unchecked);
	viewer->setBackgroundColor(30 / 255.0, 30 / 255.0, 30 / 255.0);
}

//记录操作显示在控制台
void QtApplication::consoleLog(QString operation, QString subname, QString filename, QString note)
{
	if (enable_console == false){
		return;
	}
	int rows = ui.table_Console->rowCount();
	ui.table_Console->setRowCount(++rows);
	QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
	QString time_str = time.toString("MM-dd hh:mm:ss"); //设置显示格式
	ui.table_Console->setItem(rows - 1, 0, new QTableWidgetItem(time_str));
	ui.table_Console->setItem(rows - 1, 1, new QTableWidgetItem(operation));
	ui.table_Console->setItem(rows - 1, 2, new QTableWidgetItem(subname));
	ui.table_Console->setItem(rows - 1, 3, new QTableWidgetItem(filename));
	ui.table_Console->setItem(rows - 1, 4, new QTableWidgetItem(note));

	ui.table_Console->scrollToBottom(); // 滑动自动滚到最底部
}



/*****    文件菜单函数实现   *****/

//打开点云文件，支持批量打开.pcd 、.ply 和.obj等三种格式点云文件
void QtApplication::Open()
{
	QStringList filenames = QFileDialog::getOpenFileNames(
		this, 
		QString::fromLocal8Bit("打开点云文件"), //标题
		QString::fromLocal8Bit(mycloud.dirname.c_str()), //路径
		QString::fromLocal8Bit("点云文件(*.pcd *.ply *.obj);;全部文件(*.*)"));//过滤器，筛选
	//Return if filenames is empty
	if (filenames.isEmpty())  return;
	mycloud_vec.clear();
	total_points = 0;
	ui.tree_PointCloud->clear();
	viewer->removeAllPointClouds();

	// 批量打开点云文件
	for (int i = 0; i != filenames.size(); i++)
	{
		timer.restart();//开始计时
		mycloud.cloud.reset(new PointCloudT); // Reset cloud
		QString filename = filenames[i];
		std::string file_name = filename.toStdString();
		std::string subname = getFileName(file_name);  //提取全路径中的文件名（带后缀）
		
		int status = -1;
		if (filename.endsWith(".pcd", Qt::CaseInsensitive))
		{
			status = pcl::io::loadPCDFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else if (filename.endsWith(".ply", Qt::CaseInsensitive))
		{
			status = pcl::io::loadPLYFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else if (filename.endsWith(".obj", Qt::CaseInsensitive))
		{
			status = pcl::io::loadOBJFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else
		{
			//提示：无法读取除了.ply .pcd .obj以外的文件
			QMessageBox::information(this, 
				QString::fromLocal8Bit("文件格式错误"),
				QString::fromLocal8Bit("无法打开除.ply .pcd .obj外格式的文件。"));
			return;
		}
		//提示：后缀没问题，但文件内容无法读取
		if (status != 0)
		{
			QMessageBox::critical(this, 
				QString::fromLocal8Bit("打开文件错误"),
				QString::fromLocal8Bit("无法打开该文件！"));
			return;
		}
		setA(255);  //设置点云为不透明		
		// 最后一个点云的信息
		mycloud.filename = file_name;
		mycloud.subname = subname;
		mycloud.dirname = file_name.substr(0, file_name.size() - subname.size());
		mycloud_vec.push_back(mycloud);  //将点云导入点云容器
		
		// time off
		//time_action = timer.elapsed();
		// 输出窗口
		consoleLog(QString::fromLocal8Bit("打开"), 
			QString::fromLocal8Bit(mycloud.subname.c_str()), 
			QString::fromLocal8Bit(mycloud.filename.c_str()), 
			QString::fromLocal8Bit("Time cost: ") + QString("%1s").arg(timer.elapsed()/1000.0)+ QString::fromLocal8Bit(" , Points: ") + QString::number(mycloud.cloud->points.size()));


		//更新资源管理树
		QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList()<< QString::fromLocal8Bit(subname.c_str()));
		cloudName->setIcon(0, QIcon(":/Icon/Resources/Icon/Icon.png"));//设置资源树图标
		ui.tree_PointCloud->addTopLevelItem(cloudName);


		//setWindowTitle(filename + " - CloudViewer"); //更新标题

		total_points += mycloud.cloud->points.size();
	}
	//添加属性窗口信息：当前点云个数；点云总点数；点云默认颜色（255 255 255）；

	if (mycloud_vec.size() == 1)
	{
		setPropertyTable(mycloud_vec.size(), mycloud_vec[0].cloud->points.size(), total_points, "255 255 255");
	}
	else
	{
		setPropertyTable(mycloud_vec.size(), 0, total_points, "255 255 255");
	}

	ui.statusBar->showMessage(QString::fromLocal8Bit("打开"));
	showPointcloudAdd();  //更新视图窗口

}

//添加点云文件，
void QtApplication::Add()
{
	QStringList filenames = QFileDialog::getOpenFileNames(this, 
		QString::fromLocal8Bit("添加点云文件"), //标题
		QString::fromLocal8Bit(mycloud.dirname.c_str()), //路径
		QString::fromLocal8Bit("点云文件(*.pcd *.ply *.obj);;全部文件(*.*)"));//过滤器，筛选);
	if (filenames.isEmpty())  return;//
	// 批量打开点云文件
	for (int i = 0; i != filenames.size(); i++)
	{
		timer.restart();//开始计时
		mycloud.cloud.reset(new PointCloudT); // Reset cloud
		QString filename = filenames[i];
		std::string file_name = filename.toStdString();
		std::string subname = getFileName(file_name);  //提取全路径中的文件名（带后缀）

		int status = -1;
		if (filename.endsWith(".pcd", Qt::CaseInsensitive))
		{
			status = pcl::io::loadPCDFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else if (filename.endsWith(".ply", Qt::CaseInsensitive))
		{
			status = pcl::io::loadPLYFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else if (filename.endsWith(".obj", Qt::CaseInsensitive))
		{
			status = pcl::io::loadOBJFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else
		{
			//提示：无法读取除了.ply .pcd .obj以外的文件
			QMessageBox::information(this,
				QString::fromLocal8Bit("文件格式错误"),
				QString::fromLocal8Bit("无法添加除.ply .pcd .obj外格式的文件。"));
			return;
		}
		//提示：后缀没问题，但文件内容无法读取
		if (status != 0)
		{
			QMessageBox::critical(this,
				QString::fromLocal8Bit("添加文件错误"),
				QString::fromLocal8Bit("无法添加该文件！"));
			return;
		}
		setA(255);  //设置点云为不透明		
		// 最后一个点云的信息
		mycloud.filename = file_name;
		mycloud.subname = subname;
		mycloud.dirname = file_name.substr(0, file_name.size() - subname.size());
		mycloud_vec.push_back(mycloud);  //将点云导入点云容器

		// 输出窗口
		consoleLog(QString::fromLocal8Bit("添加"),
			QString::fromLocal8Bit(mycloud.subname.c_str()),
			QString::fromLocal8Bit(mycloud.filename.c_str()),
			QString::fromLocal8Bit("Time cost: ") + QString("%1s").arg(timer.elapsed() / 1000.0) + QString::fromLocal8Bit(" , Points: ") + QString::number(mycloud.cloud->points.size()));


		//更新资源管理树
		QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(subname.c_str()));
		cloudName->setIcon(0, QIcon(":/Icon/Resources/Icon/Icon.png"));//设置资源树图标
		ui.tree_PointCloud->addTopLevelItem(cloudName);


		//setWindowTitle(filename + " - CloudViewer"); //更新标题

		total_points += mycloud.cloud->points.size();
	}
	setPropertyTable(mycloud_vec.size(), 0, total_points, "255 255 255");
	ui.statusBar->showMessage(QString::fromLocal8Bit("添加"));
	showPointcloudAdd();  //更新视图窗口
}

//保存点云文件，支持.pcd 和.ply两种格式点云文件
void QtApplication::Save()
{
	QString save_filename = QFileDialog::getSaveFileName(this,
		QString::fromLocal8Bit("保存点云文件"),
		QString::fromLocal8Bit(mycloud.dirname.c_str()), 
		QString::fromLocal8Bit("点云文件(*.pcd *.ply);;全部文件(*.*)"));
	

	//文件名为空直接返回
	if (save_filename.isEmpty())
		return;
	else
	{	
		std::string file_name = save_filename.toStdString();
		std::string subname = getFileName(file_name);
		QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
		int selected_item_count = ui.tree_PointCloud->selectedItems().size();
		// 如果未选中任何点云，则对视图窗口中的所有点云修改大小
		if (mycloud_vec.size()==1||selected_item_count == 1)
		{
			//判断文件保存类型
			int status = -1;
			if (save_filename.endsWith(".pcd", Qt::CaseInsensitive))//CaseInsensitive(不区分大小写)
			{
				status = pcl::io::savePCDFile(file_name, *(mycloud.cloud));
			}
			else if (save_filename.endsWith(".ply", Qt::CaseInsensitive))
			{
				status = pcl::io::savePLYFile(file_name, *(mycloud.cloud));
			}
			else //提示：无法保存为除了.ply .pcd以外的文件
			{
				QMessageBox::information(this,
					QString::fromLocal8Bit("文件格式错误"),
					QString::fromLocal8Bit("无法保存为除.ply .pcd外格式的文件"));
				return;
			}
			consoleLog(QString::fromLocal8Bit("保存"), QString::fromStdString(subname), QString::fromLocal8Bit("保存点云文件"), "");

		}
		else
		{
			Savemulti(save_filename);
		}	
		QMessageBox::information(this,
			QString::fromLocal8Bit("保存点云文件"),
			QString::fromLocal8Bit(("保存" + subname + "成功！").c_str()));
	}
	ui.statusBar->showMessage(QString::fromLocal8Bit("保存"));
}

//多个点云数据保存为一个文件
void QtApplication::Savemulti(QString savename)
{
	std::string subname = getFileName(savename.toStdString());
	PointCloudT::Ptr multi_cloud;
	multi_cloud.reset(new PointCloudT);
	multi_cloud->height = 1;//无序点云
	int sum = 0;
	for (auto c : mycloud_vec)
	{
		sum += c.cloud->points.size();
	}
	multi_cloud->width = sum;
	multi_cloud->resize(multi_cloud->height * multi_cloud->width);
	int k = 0;
	for (int i = 0; i != mycloud_vec.size(); i++)//点云数
	{
		//注意cloudvec[i]->points.size()和cloudvec[i]->size()的区别
		for (int j = 0; j != mycloud_vec[i].cloud->points.size(); j++)    //点云总点数     
		{
			multi_cloud->points[k].x = mycloud_vec[i].cloud->points[j].x;
			multi_cloud->points[k].y = mycloud_vec[i].cloud->points[j].y;
			multi_cloud->points[k].z = mycloud_vec[i].cloud->points[j].z;
			multi_cloud->points[k].r = mycloud_vec[i].cloud->points[j].r;
			multi_cloud->points[k].g = mycloud_vec[i].cloud->points[j].g;
			multi_cloud->points[k].b = mycloud_vec[i].cloud->points[j].b;
			k++;
		}
	}
	//保存multi_cloud
	int status = -1;
	if (savename.endsWith(".pcd", Qt::CaseInsensitive))
	{
		status = pcl::io::savePCDFile(savename.toStdString(), *multi_cloud);
	}
	else if (savename.endsWith(".ply", Qt::CaseInsensitive))
	{
		status = pcl::io::savePLYFile(savename.toStdString(), *multi_cloud);
	}
	else //提示：无法保存为除了.ply .pcd以外的文件
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("文件格式错误"),
			QString::fromLocal8Bit("无法保存为除.ply .pcd外格式的文件"));
		return;
	}
	// 输出窗口
	consoleLog(QString::fromLocal8Bit("保存"), QString::fromLocal8Bit(subname.c_str()), savename, QString::fromLocal8Bit("多个点云数据保存为一个文件"));

	//将保存后的 multi_cloud 设置为当前 mycloud,以便保存之后直接进行操作
	mycloud.cloud = multi_cloud;
	mycloud.filename = savename.toStdString();
	mycloud.subname = subname;
}

//清空点云
void QtApplication::Clear()
{
	if (mycloud_vec.size())
	{
	    mycloud_vec.clear();//清空点云容器
		viewer->removeAllPointClouds();//从Viewer中移除所有点云;
		viewer->removeAllShapes();//清空更彻底，移除所有
		ui.tree_PointCloud->clear();  //将dataTree清空

		total_points = 0;
		setPropertyTable(0,0,0," ");//设置属性管理窗口
		setRGBDock();//设置RGBDock窗口
		// 输出窗口	
		consoleLog(QString::fromLocal8Bit("清空"), QString::fromLocal8Bit("所有点云"), "", "DMY");
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("已清空所有点云!"));		
		showPointcloud();  //更新显示
	}
	else
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("当前未加载任何点云文件！"));
		return;
	}
}

//退出程序
void QtApplication::Exit()
{
	this->close();
}




/*****    显示菜单函数实现   *****/
//显示菜单给点云随机着色
void QtApplication::RandomColor()
{
	if (mycloud_vec.size())////当前有点云文件，进行随机着色
	{
		QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
		int selected_item_count = ui.tree_PointCloud->selectedItems().size();

		// 如果未选中任何点云，则对视图窗口中的所有点云进行着色
		if (selected_item_count == 0)
		{
			for (int i = 0; i != mycloud_vec.size(); i++){
				for (int j = 0; j != mycloud_vec[i].cloud->points.size(); j++){
					mycloud_vec[i].cloud->points[j].r = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
					mycloud_vec[i].cloud->points[j].g = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
					mycloud_vec[i].cloud->points[j].b = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
				}
			}

			// 输出窗口
			consoleLog(QString::fromLocal8Bit("设置点云颜色"),
				QString::fromLocal8Bit("所有点云"),
				QString::fromLocal8Bit("随机设置点云颜色"), "DMY");
		}
		else
		{
			for (int i = 0; i != selected_item_count; i++)
			{
				int cloud_id = ui.tree_PointCloud->indexOfTopLevelItem(itemList[i]);
				for (int j = 0; j != mycloud_vec[cloud_id].cloud->size(); j++){
					mycloud_vec[cloud_id].cloud->points[j].r = red;
					mycloud_vec[cloud_id].cloud->points[j].g = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
					mycloud_vec[cloud_id].cloud->points[j].b = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
				}
			}
			// 输出窗口
			consoleLog(QString::fromLocal8Bit("设置点云颜色"),
				QString::fromLocal8Bit("被选中点云"),
				QString::fromLocal8Bit("随机设置点云颜色"), "DMY");

		}
		showPointcloud();
		ui.table_Properties->setItem(3, 1, new QTableWidgetItem(QString::fromLocal8Bit("随机颜色")));


	}
	else//当前未加载点云文件
	{
		//提示：请添加点云文件
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("当前未加载任何点云文件！"));
		return;
	}

}

//显示菜单通过颜色对话框修改点云颜色
void QtApplication::PointColorChange()
{
	if (mycloud_vec.size())//当前有点云文件，进行着色
	{
		QColor color_select = QColorDialog::getColor(Qt::white, this, QString::fromLocal8Bit("选择点云颜色"));
		if (color_select.isValid())//判断所选的颜色是否有效
		{
			QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
			int selected_item_count = ui.tree_PointCloud->selectedItems().size();
			// 如果未选中任何点云，则对视图窗口中的所有点云进行着色
			if (selected_item_count == 0)
			{
				for (int i = 0; i != mycloud_vec.size(); i++)
				{
					for (int j = 0; j != mycloud_vec[i].cloud->points.size(); j++)
					{
						mycloud_vec[i].cloud->points[j].r = color_select.red();
						mycloud_vec[i].cloud->points[j].g = color_select.green();
						mycloud_vec[i].cloud->points[j].b = color_select.blue();
					}
				}
				// 输出窗口
				consoleLog(QString::fromLocal8Bit("设置点云颜色"), QString::fromLocal8Bit("所有点云"), QString::number(color_select.red()) + " " + QString::number(color_select.green()) + " " + QString::number(color_select.blue()), "");
			}
			else
			{
				for (int i = 0; i != selected_item_count; i++)
				{
					int cloud_id = ui.tree_PointCloud->indexOfTopLevelItem(itemList[i]);
					for (int j = 0; j != mycloud_vec[cloud_id].cloud->size(); j++)
					{
						mycloud_vec[cloud_id].cloud->points[j].r = color_select.red();
						mycloud_vec[cloud_id].cloud->points[j].g = color_select.green();
						mycloud_vec[cloud_id].cloud->points[j].b = color_select.blue();
					}
				}
				// 输出窗口
				consoleLog(QString::fromLocal8Bit("设置点云颜色"), QString::fromLocal8Bit("被选中点云"), QString::number(color_select.red()) + " " + QString::number(color_select.green()) + " " + QString::number(color_select.blue()), "");
			}
			showPointcloud();
			//属性窗口颜色改变
			ui.table_Properties->setItem(3, 1, new QTableWidgetItem(QString::number(color_select.red()) + " " + QString::number(color_select.green()) + " " + QString::number(color_select.blue())));
			//颜色的改变同步至RGB颜色管理窗口
			ui.Red_Slider->setValue(color_select.red());
			ui.Green_Slider->setValue(color_select.green());
			ui.Blue_Slider->setValue(color_select.blue());
		}
	}
	else  //当前未加载点云文件
	{
		ui.Red_Slider->setValue(255);
		ui.Green_Slider->setValue(255);
		ui.Blue_Slider->setValue(255);
		//提示：请添加点云文件
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("当前未加载任何点云文件！"));
		return;
	}
}

//显示菜单通过颜色对话框修改背景颜色
void QtApplication::BackgroundColorChange()
{
	QColor color_select = QColorDialog::getColor(Qt::white, this, QString::fromLocal8Bit("选择背景颜色"));
	if (color_select.isValid())//判断所选的颜色是否有效
	{
		viewer->setBackgroundColor(color_select.red() / 255.0, color_select.green() / 255.0, color_select.blue() / 255.0);
		// 输出窗口
		consoleLog(QString::fromLocal8Bit("改变背景颜色"), QString::fromLocal8Bit("背景颜色"), QString::number(color_select.red()) + " " + QString::number(color_select.green()) + " " + QString::number(color_select.blue()), "");
		ui.qvtkWidget->update();
		//showPointcloud();
	}
}

//主视角；左视角；俯视角
void QtApplication::MainView()
{
	viewer->setCameraPosition(0, -1, 0, 0.5, 0.5, 0.5, 0, 0, 1);
	ui.qvtkWidget->update();
}

void QtApplication::LeftView()
{
	viewer->setCameraPosition(-1, 0, 0, 0, 0, 0, 0, 0, 1);
	ui.qvtkWidget->update();
}

void QtApplication::TopView()
{
	viewer->setCameraPosition(0, 0, 1, 0, 0, 0, 0, 1, 0);
	ui.qvtkWidget->update();
}



/*****    视图菜单函数实现   *****/
//设置停靠窗口的显示与隐藏
void QtApplication::HideDataDock()
{
	if (ui.action_DataManager->isChecked())
	{
		ui.dock_datatree->setVisible(true);
	}
	else
	{
		ui.dock_datatree->setVisible(false);
	}
}

void QtApplication::HidePropertiesDock()
{
	if (ui.action_PropertiesManager->isChecked())
	{
		ui.dock_properties->setVisible(true);
	}
	else
	{
		ui.dock_properties->setVisible(false);
	}
}

void QtApplication::HideConsoleDock()
{
	if (ui.action_ConsoleManager->isChecked())
	{
		ui.dock_console->setVisible(true);
	}
	else
	{
		ui.dock_console->setVisible(false);
	}
}

void QtApplication::HideRGBDock()
{
	if (ui.action_RGBManager->isChecked())
	{
		ui.dock_rgbcolor->setVisible(true);
	}
	else
	{
		ui.dock_rgbcolor->setVisible(false);
	}
}


/*****    处理菜单函数实现   *****/

//生成网格面片
void QtApplication::Surface()
{

	QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
	int selected_item_count = ui.tree_PointCloud->selectedItems().size();
	if (selected_item_count == 0)
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("请选择一个点云文件"));
		return;
	}
	else
	{
		for (int i = 0; i != selected_item_count; i++)
		{
			int cloud_id = ui.tree_PointCloud->indexOfTopLevelItem(itemList[i]);
			/* 问题
			好像该方法只能处理PointXYZ的点云，用PointXZYRGBA的点云编译会报错
			调用boost::this_thread::sleep好像也会编译出错
			因此先进行点云类型转换
			*/
			pcl::PointXYZ point;
			cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
			timer.restart();//开始计时
			//把mycloud.cloud（包含XYZRGBA的点云）转换成cloud_xyz（只包含XYZ的点云）
			//int number = mycloud_vec[cloud_id].cloud->size();
			for (size_t i = 0; i != mycloud_vec[cloud_id].cloud->size(); i++)
			{
				point.x = mycloud_vec[cloud_id].cloud->points[i].x;
				point.y = mycloud_vec[cloud_id].cloud->points[i].y;
				point.z = mycloud_vec[cloud_id].cloud->points[i].z;
				cloud_xyz->push_back(point);//把这个点添加进cloud_xyz点云中
			}
			if (!cloud_xyz)
			{
				return;
			}
			/****** 法向估计模块 ******/
			//创建法线估计对象 n
			////Normal结构体表示给定点所在样本曲面上的法线方向，以及对应曲率的测量值
			pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
			//创建法向数据指针 normals
			pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
			//创建kdtree用于法向计算时临近搜索
			pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZ>);
			kdtree->setInputCloud(cloud_xyz);//为kdtree输入点云
			n.setInputCloud(cloud_xyz);//为法向估计对象输入点云
			n.setSearchMethod(kdtree);//设置法向估计时所采取的搜索方式kdtree
			n.setKSearch(20);//K近邻搜索点数
			n.compute(*normals);

			//QMessageBox::information(this, QString::fromLocal8Bit("提示信息"), QString::fromLocal8Bit("法线估计已完成"));

			/****** 点云数据与法向数据拼接 ******/
			//创建同时包含点和法线的数据结构的指针
			//PointNormal是存储XYZ数据的point结构体，并且包括了采样点的法线和曲率
			pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals(new pcl::PointCloud<pcl::PointNormal>);
			//将已获得的点云数据和法向数据连接//这里编译出错，与cloud的类型有关？改成PointXYZ的点云就没有报错了
			pcl::concatenateFields(*cloud_xyz, *normals, *cloud_with_normals);
			//创建另一个kdtree用于重建
			pcl::search::KdTree<pcl::PointNormal>::Ptr kdtree2(new pcl::search::KdTree<pcl::PointNormal>);
			//为kdtree2输入点云,，该点云数据类型为点和法向
			kdtree2->setInputCloud(cloud_with_normals);

			/****** 曲面重建模块 ******/
			//创建贪婪三角形投影重建对象
			pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
			//创建多边形网格对象，用来存储重建结果
			pcl::PolygonMesh mesh;
			//设置参数
			gp3.setSearchRadius(25);//设置连接点之间最大距离，用于确定k近邻的球半径
			gp3.setMu(2.5);//设置最近邻距离的乘子，已得到每个点的最终搜索半径
			gp3.setMaximumNearestNeighbors(100);//设置搜索的最邻近点的最大数量
			gp3.setMaximumSurfaceAngle(M_PI / 2);//45度，最大平面角
			gp3.setMinimumAngle(M_PI / 18);//10度，每个三角的最小角度
			gp3.setMaximumAngle(2 * M_PI / 3);//120度,每个三角的最大角度
			gp3.setNormalConsistency(false);//若法向量一致，设为true
			//设置点云数据和搜索方式
			gp3.setInputCloud(cloud_with_normals);
			gp3.setSearchMethod(kdtree2);
			gp3.reconstruct(mesh);
			//QMessageBox::information(this, "informaiton", "Reconstruction finished");
			//将重建结果保存到硬盘文件中，重建结果以VTK格式存储
			pcl::io::saveVTKFile("mymesh.vtk", mesh);

			/****** 图形显示模块 ******/
			//QMessageBox::information(this, "information", "Start to show");
			viewer->addPolygonMesh(mesh, "my");//设置要显示的网格对象
			//设置网格模型显示模式
			//viewer->setRepresentationToPointsForAllActors();//网格模型以点形式显示
			viewer->setRepresentationToSurfaceForAllActors();//网格模型以面片形式显示
			//viewer->setRepresentationToWireframeForAllActors();//网格模型以线框图模式显示

			//输出窗口
			consoleLog(QString::fromLocal8Bit("生成网格面片"),
				QString::fromLocal8Bit(mycloud_vec[cloud_id].subname.c_str()),
				QString::fromLocal8Bit(mycloud_vec[cloud_id].filename.c_str()),
				QString::fromLocal8Bit("Time cost: ") + QString("%1s").arg(timer.elapsed() / 1000.0) + QString::fromLocal8Bit(" , Points: ") + QString::number(mycloud_vec[cloud_id].cloud->size()));
			//viewer->removeAllShapes();
			while (!viewer->wasStopped())
			{
				viewer->spinOnce(100);
				//boost::this_thread::sleep(boost::posix_time::microseconds(100000));
			}
			QMessageBox::information(this,
				QString::fromLocal8Bit("提示信息"),
				QString::fromLocal8Bit(mycloud_vec[cloud_id].subname.c_str()) + QString::fromLocal8Bit("三角格网化已完成!")
				);
		}
	}
}

//生成网格线框	
void QtApplication::Wireframe()
{

	QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
	int selected_item_count = ui.tree_PointCloud->selectedItems().size();
	if (selected_item_count == 0)
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("请选择一个点云文件"));
		return;
	}
	else
	{
		for (int i = 0; i != selected_item_count; i++)
		{
			int cloud_id = ui.tree_PointCloud->indexOfTopLevelItem(itemList[i]);
			/* 问题
			好像该方法只能处理PointXYZ的点云，用PointXZYRGBA的点云编译会报错
			调用boost::this_thread::sleep好像也会编译出错
			因此先进行点云类型转换
			*/
			pcl::PointXYZ point;
			cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
			timer.restart();//开始计时
			//把mycloud.cloud（包含XYZRGBA的点云）转换成cloud_xyz（只包含XYZ的点云）
			//int number = mycloud_vec[cloud_id].cloud->size();
			for (size_t i = 0; i != mycloud_vec[cloud_id].cloud->size(); i++)
			{
				point.x = mycloud_vec[cloud_id].cloud->points[i].x;
				point.y = mycloud_vec[cloud_id].cloud->points[i].y;
				point.z = mycloud_vec[cloud_id].cloud->points[i].z;
				cloud_xyz->push_back(point);//把这个点添加进cloud_xyz点云中
			}
			if (!cloud_xyz)
			{
				return;
			}
			/****** 法向估计模块 ******/
			//创建法线估计对象 n
			////Normal结构体表示给定点所在样本曲面上的法线方向，以及对应曲率的测量值
			pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
			//创建法向数据指针 normals
			pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
			//创建kdtree用于法向计算时临近搜索
			pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZ>);
			kdtree->setInputCloud(cloud_xyz);//为kdtree输入点云
			n.setInputCloud(cloud_xyz);//为法向估计对象输入点云
			n.setSearchMethod(kdtree);//设置法向估计时所采取的搜索方式kdtree
			n.setKSearch(20);//K近邻搜索点数
			n.compute(*normals);

			//QMessageBox::information(this, QString::fromLocal8Bit("提示信息"), QString::fromLocal8Bit("法线估计已完成"));

			/****** 点云数据与法向数据拼接 ******/
			//创建同时包含点和法线的数据结构的指针
			//PointNormal是存储XYZ数据的point结构体，并且包括了采样点的法线和曲率
			pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals(new pcl::PointCloud<pcl::PointNormal>);
			//将已获得的点云数据和法向数据连接//这里编译出错，与cloud的类型有关？改成PointXYZ的点云就没有报错了
			pcl::concatenateFields(*cloud_xyz, *normals, *cloud_with_normals);
			//创建另一个kdtree用于重建
			pcl::search::KdTree<pcl::PointNormal>::Ptr kdtree2(new pcl::search::KdTree<pcl::PointNormal>);
			//为kdtree2输入点云,，该点云数据类型为点和法向
			kdtree2->setInputCloud(cloud_with_normals);

			/****** 曲面重建模块 ******/
			//创建贪婪三角形投影重建对象
			pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
			//创建多边形网格对象，用来存储重建结果
			pcl::PolygonMesh mesh;
			//设置参数
			gp3.setSearchRadius(25);//设置连接点之间最大距离，用于确定k近邻的球半径
			gp3.setMu(2.5);//设置最近邻距离的乘子，已得到每个点的最终搜索半径
			gp3.setMaximumNearestNeighbors(100);//设置搜索的最邻近点的最大数量
			gp3.setMaximumSurfaceAngle(M_PI / 2);//45度，最大平面角
			gp3.setMinimumAngle(M_PI / 18);//10度，每个三角的最小角度
			gp3.setMaximumAngle(2 * M_PI / 3);//120度,每个三角的最大角度
			gp3.setNormalConsistency(false);//若法向量一致，设为true
			//设置点云数据和搜索方式
			gp3.setInputCloud(cloud_with_normals);
			gp3.setSearchMethod(kdtree2);
			gp3.reconstruct(mesh);
			//QMessageBox::information(this, "informaiton", "Reconstruction finished");
			//将重建结果保存到硬盘文件中，重建结果以VTK格式存储
			pcl::io::saveVTKFile("mymesh.vtk", mesh);

			/****** 图形显示模块 ******/
			//QMessageBox::information(this, "information", "Start to show");
			viewer->addPolygonMesh(mesh, "my");//设置要显示的网格对象
			//设置网格模型显示模式
			//viewer->setRepresentationToPointsForAllActors();//网格模型以点形式显示
			//viewer->setRepresentationToSurfaceForAllActors();//网格模型以面片形式显示
			viewer->setRepresentationToWireframeForAllActors();//网格模型以线框图模式显示

			//输出窗口
			consoleLog(QString::fromLocal8Bit("生成网格线框"),
				QString::fromLocal8Bit(mycloud_vec[cloud_id].subname.c_str()),
				QString::fromLocal8Bit(mycloud_vec[cloud_id].filename.c_str()),
				QString::fromLocal8Bit("Time cost: ") + QString("%1s").arg(timer.elapsed() / 1000.0) + QString::fromLocal8Bit(" , Points: ") + QString::number(mycloud_vec[cloud_id].cloud->size()));
			viewer->removeAllShapes();
			while (!viewer->wasStopped())
			{
				viewer->spinOnce(100);
				//boost::this_thread::sleep(boost::posix_time::microseconds(100000));
			}
			QMessageBox::information(this, 
				QString::fromLocal8Bit("提示信息"),
				QString::fromLocal8Bit(mycloud_vec[cloud_id].subname.c_str()) + QString::fromLocal8Bit("三角格网化已完成!")
				);
		}
	}
}




/*****    点云简化菜单函数实现   *****/
void QtApplication::Simplify()
{
	QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
	int selected_item_count = ui.tree_PointCloud->selectedItems().size();
	if (selected_item_count == 0)
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("请选择一个点云文件"));
		return;
	}
	else
	{

		for (int i = 0; i != selected_item_count; i++)
		{
			timer.restart();//开始计时
			int cloud_id = ui.tree_PointCloud->indexOfTopLevelItem(itemList[i]);
			/* 问题
			好像该方法只能处理PointXYZ的点云，用PointXZYRGBA的点云编译会报错
			调用boost::this_thread::sleep好像也会编译出错
			因此先进行点云类型转换
			*/
			pcl::PointXYZ point;
			cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
			timer.restart();//开始计时
			//把mycloud.cloud（包含XYZRGBA的点云）转换成cloud_xyz（只包含XYZ的点云）
			//int number = mycloud_vec[cloud_id].cloud->size();
			for (size_t i = 0; i != mycloud_vec[cloud_id].cloud->size(); i++)
			{
				point.x = mycloud_vec[cloud_id].cloud->points[i].x;
				point.y = mycloud_vec[cloud_id].cloud->points[i].y;
				point.z = mycloud_vec[cloud_id].cloud->points[i].z;
				cloud_xyz->push_back(point);//把这个点添加进cloud_xyz点云中
			}
			if (!cloud_xyz)
			{
				return;
			}

			srand(time(0));
			// Read in the cloud data
			pcl::PCDReader reader;
			//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
			pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_f(new pcl::PointCloud<pcl::PointXYZ>);
			//reader.read("table_scene_lms400.pcd", *cloud_filtered);
			//cloud_filtered
			//std::cout << "PointCloud has: " << cloud_filtered->points.size() << " data points." << std::endl; //*


			QMessageBox::information(this,
				QString::fromLocal8Bit("提示信息"),
				QString::fromLocal8Bit("一共有：") + QString::number(cloud_xyz->points.size(), 10) + QString::fromLocal8Bit("个点"));
			//输出
			ofstream fout("E:\\Date\\PointCloud\\temp\\plane.txt");
			int point_num = 0;
			// Create the segmentation object for the planar model and set all the parameters
			pcl::SACSegmentation<pcl::PointXYZ> seg;
			pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
			pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
			pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane(new pcl::PointCloud<pcl::PointXYZ>());
			pcl::PCDWriter writer;
			seg.setOptimizeCoefficients(true);
			seg.setModelType(pcl::SACMODEL_PLANE);
			seg.setMethodType(pcl::SAC_RANSAC);
			seg.setMaxIterations(100);
			seg.setDistanceThreshold(0.02);    //此处可以自己修改，一般保持默认即可

			int i = 0, nr_points = (int)cloud_xyz->points.size();
			while (cloud_xyz->points.size() > 0.3 * nr_points)    //此处的0.3可以修改，一般保持默认即可
			{
				// Segment the largest planar component from the remaining cloud
				seg.setInputCloud(cloud_xyz);
				seg.segment(*inliers, *coefficients);
				if (inliers->indices.size() == 0)
				{
					//std::cout << "Could not estimate a planar model for the given dataset." << std::endl;
					
					QMessageBox::information(this,
						QString::fromLocal8Bit("提示信息"),
						"Could not estimate a planar model for the given dataset.");
					break;
				}

				// Extract the planar inliers from the input cloud
				pcl::ExtractIndices<pcl::PointXYZ> extract;
				extract.setInputCloud(cloud_xyz);
				extract.setIndices(inliers);
				extract.setNegative(false);

				// Get the points associated with the planar surface
				extract.filter(*cloud_plane);
				//std::cout << "PointCloud representing the planar component: " << cloud_plane->points.size() << " data points." << std::endl;
			   /* QMessageBox::information(this,
					QString::fromLocal8Bit("提示信息"),
					"PointCloud representing the planar component: " + QString::number(cloud_plane->points.size(),10) +" data points.");
				*/
				for (int i = 0; i <cloud_plane->points.size(); i++)
				{

					/*QMessageBox::information(this,
						QString::fromLocal8Bit("提示信息"),
						QString::fromLocal8Bit("写点云数据"));
*/
					if (rand() % 100 < 30)            //平面简化率为70%
					{
						fout << cloud_plane->points[i].x << " " << cloud_plane->points[i].y << " " << cloud_plane->points[i].z << endl;
						point_num++;
					}
				}

				// Remove the planar inliers, extract the rest
				extract.setNegative(true);
				extract.filter(*cloud_f);
				*cloud_xyz = *cloud_f;
			}
			for (int i = 0; i <cloud_xyz->points.size(); i++)
			{

				/*QMessageBox::information(this,
					QString::fromLocal8Bit("提示信息"),
					QString::fromLocal8Bit("又一次写点云数据"));*/
				if (rand() % 100 < 70)            //简化率为30%
				{
					fout << cloud_xyz->points[i].x << " " << cloud_xyz->points[i].y << " " << cloud_xyz->points[i].z << endl;
					point_num++;
				}
			}
			fout << point_num<<"个点"<<endl;
			fout.close();
			consoleLog(QString::fromLocal8Bit("简化"),
				QString::fromLocal8Bit(mycloud_vec[cloud_id].subname.c_str()),
				QString::fromLocal8Bit(mycloud_vec[cloud_id].filename.c_str()),
				QString::fromLocal8Bit("Time cost: ") + QString("%1s").arg(timer.elapsed() / 1000.0) + QString::fromLocal8Bit(" , Points: ") + QString::number(mycloud.cloud->points.size()));
		}
	}
}



/*****    特征提取菜单函数实现   *****/

void QtApplication::Boundary()
{
	QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
	int selected_item_count = ui.tree_PointCloud->selectedItems().size();
	if (selected_item_count == 0)
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("请选择一个点云文件"));
		return;
	}
	else
	{

		for (int i = 0; i != selected_item_count; i++)
		{
			timer.restart();//开始计时
			int cloud_id = ui.tree_PointCloud->indexOfTopLevelItem(itemList[i]);
			
			pcl::PointXYZ point;
			cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
			timer.restart();//开始计时
			//把mycloud.cloud（包含XYZRGBA的点云）转换成cloud_xyz（只包含XYZ的点云）
			//int number = mycloud_vec[cloud_id].cloud->size();
			for (size_t i = 0; i != mycloud_vec[cloud_id].cloud->size(); i++)
			{
				point.x = mycloud_vec[cloud_id].cloud->points[i].x;
				point.y = mycloud_vec[cloud_id].cloud->points[i].y;
				point.z = mycloud_vec[cloud_id].cloud->points[i].z;
				cloud_xyz->push_back(point);//把这个点添加进cloud_xyz点云中
			}
			if (!cloud_xyz)
			{
				return;
			}

			pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_b(new pcl::PointCloud<pcl::PointXYZ>);
			//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
			//cloud = mycloud_vec[cloud_id].cloud;
			//pcl::io::loadPCDFile("D:\\12.pcd", *cloud);
			//计算法线
			pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normEst;
			pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
			pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
			pcl::search::KdTree<pcl::PointXYZ>::Ptr tree2(new pcl::search::KdTree<pcl::PointXYZ>);
			tree->setInputCloud(cloud_xyz);
			normEst.setInputCloud(cloud_xyz);
			normEst.setSearchMethod(tree);
			normEst.setKSearch(20);
			normEst.compute(*normals);
			//判断边缘点
			pcl::PointCloud<pcl::Boundary> boundaries;
			pcl::BoundaryEstimation<pcl::PointXYZ, pcl::Normal, pcl::Boundary> boundEst;
			tree2->setInputCloud(cloud_xyz);
			boundEst.setInputCloud(cloud_xyz);
			boundEst.setInputNormals(normals);
			boundEst.setSearchMethod(tree2);
			boundEst.setKSearch(20);
			boundEst.setAngleThreshold(M_PI / 2);
			boundEst.compute(boundaries);
			//提取边缘点重组点云
			cloud_b->width = (int)cloud_xyz->points.size();
			cloud_b->height = 1;
			cloud_b->points.resize(cloud_b->width*cloud_b->height);
			int j = 0;
			for (int i = 0; i < cloud_xyz->points.size(); i++)
			{
				if (boundaries.points[i].boundary_point != 0)
				{
					cloud_b->points[j].x = cloud_xyz->points[i].x;
					cloud_b->points[j].y = cloud_xyz->points[i].y;
					cloud_b->points[j].z = cloud_xyz->points[i].z;
					j++;
				}
				//else if (rand() % 100 < 50)            //简化率为50%
				//{
				//	cloud_b->points[j].x = cloud->points[i].x;
				//	cloud_b->points[j].y = cloud->points[i].y;
				//	cloud_b->points[j].z = cloud->points[i].z;
				//	j++;
				//}
				continue;
			}
			cloud_b->width = j;
			cloud_b->points.resize(cloud_b->width*cloud_b->height);
			
			pcl::io::savePCDFile(mycloud_vec[cloud_id].dirname + "boundary.pcd", *cloud_b);
			
			
			
					
			mycloud.cloud.reset(new PointCloudT); // Reset cloud
			pcl::copyPointCloud(*cloud_b, *mycloud.cloud);//转换点云格式	
			mycloud.filename = mycloud_vec[cloud_id].dirname + "boundary.pcd";
			mycloud.dirname  = mycloud_vec[cloud_id].dirname;
			mycloud.subname  = "boundary.pcd";
			setCloudColor(255,255,0);
			//pcl::io::loadOBJFile(mycloud_vec[cloud_id].dirname + "boundary.pcd", *(mycloud.cloud));
			
			mycloud_vec.push_back(mycloud);


			consoleLog(QString::fromLocal8Bit("提取特征边界"),
				QString::fromLocal8Bit(mycloud_vec[cloud_id].subname.c_str()),
				QString::fromLocal8Bit(mycloud_vec[cloud_id].filename.c_str()),
				QString::fromLocal8Bit("Time cost: ") + QString("%1s").arg(timer.elapsed() / 1000.0) + QString::fromLocal8Bit(" , Points: ") + QString::number(mycloud.cloud->points.size()));


			//更新资源管理树
			QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(mycloud.subname.c_str()));
			cloudName->setIcon(0, QIcon(":/Icon/Resources/Icon/Icon.png"));//设置资源树图标
			ui.tree_PointCloud->addTopLevelItem(cloudName);


			//setWindowTitle(filename + " - CloudViewer"); //更新标题

			total_points += mycloud.cloud->points.size();		
		}
		setPropertyTable(mycloud_vec.size(), 0, total_points, "255 255 255");
		showPointcloudAdd();  //更新视图窗口
	}

}

/*****    帮助菜单函数实现   *****/

//帮助，打开PCL点云库官网
void QtApplication::Help()
{
	QDesktopServices::openUrl(QUrl(QLatin1String("http://pointclouds.org/")));

	// 输出窗口
	consoleLog(QString::fromLocal8Bit("帮助"), QString::fromLocal8Bit("PCL点云库官网"), "http://pointclouds.org/", "");
}

//关于，打开关于介绍
void QtApplication::About()
{
	
	aboutwin->setModal(true);
	aboutwin->show();

	 //输出窗口
	//consoleLog(QString::fromLocal8Bit("关于"), "My Graduate Design", "", "DMY");

}



/*****    颜色管理窗口函数实现   *****/

//RGB颜色及点云大小设置
void QtApplication::PointSize_SliderReleased()
{
	if (mycloud_vec.size())//当前有点云文件，修改点云尺寸
	{
		QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
		int selected_item_count = ui.tree_PointCloud->selectedItems().size();
		// 如果未选中任何点云，则对视图窗口中的所有点云修改大小
		if (selected_item_count == 0){
			for (int i = 0; i != mycloud_vec.size(); i++){
				viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
					point_size, "cloud" + QString::number(i).toStdString());
			}

			// 输出窗口
			consoleLog(QString::fromLocal8Bit("设置点云大小"), QString::fromLocal8Bit("所有点云"), "Size: " + QString::number(point_size), "");
		}
		else{
			for (int i = 0; i != selected_item_count; i++){
				int cloud_id = ui.tree_PointCloud->indexOfTopLevelItem(itemList[i]);
				viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
					point_size, "cloud" + QString::number(cloud_id).toStdString());
			}
			// 输出窗口
			consoleLog(QString::fromLocal8Bit("设置点云大小"), QString::fromLocal8Bit("被选中点云"), "Size: " + QString::number(point_size), "");
		}
		ui.qvtkWidget->update();
	}
	else//当前未加载点云文件
	{
		ui.PointSize_Slider->setValue(1);
		//提示：请添加点云文件
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("当前未加载任何点云文件！"));		
		return;
		
	}
	

}

void QtApplication::RGBsliderReleased()
{
	if (mycloud_vec.size())//当前有点云文件，进行着色
	{
		QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
		int selected_item_count = ui.tree_PointCloud->selectedItems().size();
		// 如果未选中任何点云，则对视图窗口中的所有点云进行着色
		if (selected_item_count == 0)
		{
			for (int i = 0; i != mycloud_vec.size(); i++)
			{
				for (int j = 0; j != mycloud_vec[i].cloud->points.size(); j++)
				{
					mycloud_vec[i].cloud->points[j].r = red;
					mycloud_vec[i].cloud->points[j].g = green;
					mycloud_vec[i].cloud->points[j].b = blue;
				}
			}
			// 输出窗口
			consoleLog(QString::fromLocal8Bit("设置点云颜色"), QString::fromLocal8Bit("所有点云"), QString::number(red) + " " + QString::number(green) + " " + QString::number(blue), "");

		}
		else
		{
			for (int i = 0; i != selected_item_count; i++)
			{
				int cloud_id = ui.tree_PointCloud->indexOfTopLevelItem(itemList[i]);
				for (int j = 0; j != mycloud_vec[cloud_id].cloud->size(); j++)
				{
					mycloud_vec[cloud_id].cloud->points[j].r = red;
					mycloud_vec[cloud_id].cloud->points[j].g = green;
					mycloud_vec[cloud_id].cloud->points[j].b = blue;
				}
			}
			// 输出窗口
			consoleLog(QString::fromLocal8Bit("设置点云颜色"), QString::fromLocal8Bit("被选中点云"), QString::number(red) + " " + QString::number(green) + " " + QString::number(blue), "");
		}
		showPointcloud();
		//颜色属性窗口改变
		ui.table_Properties->setItem(3, 1, new QTableWidgetItem(QString::number(red) + " " + QString::number(green) + " " + QString::number(blue)));
		
	}
	else  //当前未加载点云文件
	{
		ui.Red_Slider->setValue(255);	
		ui.Green_Slider->setValue(255);		
		ui.Blue_Slider->setValue(255);
		//提示：请添加点云文件
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("当前未加载任何点云文件！"));	
		return;
		
	}	
}

void QtApplication::PointSize_SliderChanged(int value)
{
	point_size = value;
	ui.PointSize_lcdNumber->display(value);

}

void QtApplication::Red_SliderChanged(int value)
{
	red = value;
	ui.Red_lcdNumber->display(value);
}

void QtApplication::Green_SliderChanged(int value)
{
	green = value;
	ui.Green_lcdNumber->display(value);
}

void QtApplication::Blue_SliderChanged(int value)
{
	blue = value;
	ui.Blue_lcdNumber->display(value);
}

//坐标系显示函数
void QtApplication::CordinateChecked(int value)
{
	switch (value)
	{
	case 0:
		viewer->removeCoordinateSystem();  //移除坐标系
		// 输出窗口
		consoleLog(QString::fromLocal8Bit("移除坐标系"), QString::fromLocal8Bit("移除"), "", "");
		break;
	case 2:
		viewer->addCoordinateSystem();  //添加坐标系
		// 输出窗口
		consoleLog(QString::fromLocal8Bit("添加坐标系"), QString::fromLocal8Bit("添加"), "", "");
		break;
	}
	ui.qvtkWidget->update();
}

//背景颜色设置函数
void QtApplication::BackgroundChecked(int value)
{
	switch (value)
	{
	case 0:
		viewer->setBackgroundColor(30 / 255.0, 30 / 255.0, 30 / 255.0);
		// 输出窗口
		consoleLog(QString::fromLocal8Bit("改变背景颜色"), QString::fromLocal8Bit("背景颜色"), "30 30 30", "");
		break;
	case 2:
		//！注意：setBackgroundColor()接收的是0-1的double型参数
		viewer->setBackgroundColor(240 / 255.0, 240 / 255.0, 240 / 255.0);
		// 输出窗口
		consoleLog(QString::fromLocal8Bit("改变背景颜色"), QString::fromLocal8Bit("背景颜色"), "240 240 240", "");
		break;
	}
	ui.qvtkWidget->update();
}



/*****    点云文件管理窗口函数实现   *****/

//左键单击点云文件响应函数
void QtApplication::dataSelected(QTreeWidgetItem* item, int count)
{
	count = ui.tree_PointCloud->indexOfTopLevelItem(item);  //获取item的行号

	//首先将所有点云大小设为1
	for (int i = 0; i != mycloud_vec.size(); i++)
	{
		viewer->updatePointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
		viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud" + QString::number(i).toStdString());
	}

	//提取当前点云的RGB,点云数量等信息
	//int cloud_size = mycloud_vec[count].cloud->points.size();
	QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
	int selected_item_count = ui.tree_PointCloud->selectedItems().size();
	long pointsnumber =0;//记录被选中点云总点数
	// 如果选中多个点云，属性窗口点数项显示选中的点云个数和;选中点云尺寸变大
	for (int i = 0; i != selected_item_count; i++)
	{
		int cloud_id = ui.tree_PointCloud->indexOfTopLevelItem(itemList[i]);
		viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
			2, "cloud" + QString::number(cloud_id).toStdString());//选中点云尺寸变大
		pointsnumber += mycloud_vec[cloud_id].cloud->points.size();
	}
	unsigned int cloud_r = mycloud_vec[count].cloud->points[0].r;
	unsigned int cloud_g = mycloud_vec[count].cloud->points[0].g;
	unsigned int cloud_b = mycloud_vec[count].cloud->points[0].b;
	//判断点云单色多色的条件（不是很严谨）
	//bool multi_color = true;
	//unsigned int endpoint = mycloud_vec[count].cloud->points.size();
	//unsigned int bred = mycloud_vec[count].cloud->points[0].r;
	//unsigned int ered = mycloud_vec[count].cloud->points[endpoint - 1].r;
	//if ( bred == ered)
	//	multi_color = false;
	
	//更新属性窗口信息
	setPropertyTable(mycloud_vec.size(), pointsnumber, total_points, QString::number(cloud_r) + " " + QString::number(cloud_g) + " " + QString::number(cloud_b));
	
	ui.qvtkWidget->update();
}
//右键单击点云文件，右键响应菜单
void QtApplication::popMenu_DataTree(const QPoint&)
{

	QTreeWidgetItem* curItem = ui.tree_PointCloud->currentItem();//获取当前右击的点云
	if (curItem == NULL)
	{
		return;//在空白位置右击
	}
	else
	{
		QString curName = curItem->text(0);
		int id = ui.tree_PointCloud->indexOfTopLevelItem(curItem);
		string cloud_id = "cloud" + QString::number(id).toStdString();

		QAction DataHide(QString::fromLocal8Bit("隐藏"), this);
		QAction DataShow(QString::fromLocal8Bit("显示"), this);
		QAction DataDelete(QString::fromLocal8Bit("删除"), this);
		QAction ColorChange(QString::fromLocal8Bit("修改点云颜色"), this);

		connect(&DataHide, &QAction::triggered, this, &QtApplication::dataHide);
		connect(&DataShow, &QAction::triggered, this, &QtApplication::dataShow);
		connect(&DataDelete, &QAction::triggered, this, &QtApplication::dataDelete);
		connect(&ColorChange, &QAction::triggered, this, &QtApplication::dataColorChange);

		QPoint pos;
		QMenu *popMenu = new QMenu(this);		
		popMenu->addAction(&DataHide);
		popMenu->addAction(&DataShow);
		popMenu->addAction(&DataDelete);
		popMenu->addAction(&ColorChange);

		if (mycloud_vec[id].visible == true)
		{
			popMenu->actions()[0]->setVisible(true);
			popMenu->actions()[1]->setVisible(false);
		}
		else
		{
			popMenu->actions()[0]->setVisible(false);
			popMenu->actions()[1]->setVisible(true);
		}
		popMenu->exec(QCursor::pos()); //在当前鼠标位置显示
	}
	

}
//隐藏点云文件
void QtApplication::dataHide()
{
	if (ui.tree_PointCloud->selectedItems().size())
	{
		QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
		for (int i = 0; i != ui.tree_PointCloud->selectedItems().size(); i++)
		{
			QTreeWidgetItem* curItem = itemList[i];
			QString name = curItem->text(0);
			int id = ui.tree_PointCloud->indexOfTopLevelItem(curItem);
			string cloud_id = "cloud" + QString::number(id).toStdString();
			//QMessageBox::information(this, "cloud_id", QString::fromLocal8Bit(cloud_id.c_str()));
			// 将cloud_id所对应的点云设置成透明
			viewer->setPointCloudRenderingProperties(pcl::visualization::RenderingProperties::PCL_VISUALIZER_OPACITY, 0.0, cloud_id, 0);
			QColor item_color = QColor(112, 122, 132, 255);
			curItem->setTextColor(0, item_color);
			mycloud_vec[id].visible = false;
		}
		consoleLog(QString::fromLocal8Bit("隐藏点云"), QString::fromLocal8Bit("被选中点云"), "", "");
		ui.qvtkWidget->update(); //刷新视图窗口，不能省略
	}
	else
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("未选中任何点云！"));
		return;
	}
}
//显示点云文件
void QtApplication::dataShow()
{
	if (ui.tree_PointCloud->selectedItems().size())
	{
		QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
		for (int i = 0; i != ui.tree_PointCloud->selectedItems().size(); i++){
			//QTreeWidgetItem* curItem = ui.dataTree->currentItem();
			QTreeWidgetItem* curItem = itemList[i];
			QString name = curItem->text(0);
			int id = ui.tree_PointCloud->indexOfTopLevelItem(curItem);
			string cloud_id = "cloud" + QString::number(id).toStdString();
			// 将cloud_id所对应的点云设置成透明
			viewer->setPointCloudRenderingProperties(pcl::visualization::RenderingProperties::PCL_VISUALIZER_OPACITY, 1.0, cloud_id, 0);
			QColor item_color;
			item_color = QColor(0, 0, 0, 255);
			curItem->setTextColor(0, item_color);
			mycloud_vec[id].visible = true;
		}

		// 输出窗口
		consoleLog(QString::fromLocal8Bit("显示点云"), 
			QString::fromLocal8Bit("被选中点云"), "", "");
		ui.qvtkWidget->update(); //刷新视图窗口，不能省略

	}
	else
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("未选中任何点云！"));
		return;

	}

}
//移除点云文件
void QtApplication::dataDelete()
{
	if (ui.tree_PointCloud->selectedItems().size())
	{
		QList<QTreeWidgetItem*> itemList = ui.tree_PointCloud->selectedItems();
		//随着迭代次数而改变，因此循环条件要设置为固定大小的 selected_item_count
		int selected_item_count = ui.tree_PointCloud->selectedItems().size();
		for (int i = 0; i != selected_item_count; i++){
			QTreeWidgetItem* curItem = itemList[i];
			QString name = curItem->text(0);
			int id = ui.tree_PointCloud->indexOfTopLevelItem(curItem);
			auto it = mycloud_vec.begin() + ui.tree_PointCloud->indexOfTopLevelItem(curItem);
			// 删除点云之前，将其点的数目保存
			int delete_points = (*it).cloud->points.size();
			it = mycloud_vec.erase(it);
			total_points -= delete_points;

			if (mycloud_vec.size()==1)
			{			
				unsigned int r = mycloud_vec[0].cloud->points[0].r;
				unsigned int g = mycloud_vec[0].cloud->points[0].g;
				unsigned int b = mycloud_vec[0].cloud->points[0].b;
				QString RGB_value = QString::number(r) + " " + QString::number(g) + " " + QString::number(b);
				setPropertyTable(mycloud_vec.size(), mycloud_vec[0].cloud->points.size(), total_points, RGB_value);
			}
			else
			{
				setPropertyTable(mycloud_vec.size(),0, total_points," ");
			}
			

			ui.tree_PointCloud->takeTopLevelItem(ui.tree_PointCloud->indexOfTopLevelItem(curItem));
		}

		// 移除之后再添加，避免 id 和点云树行号不一致的情况
		viewer->removeAllPointClouds();
		for (int i = 0; i != mycloud_vec.size(); i++)
		{
			viewer->addPointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
			viewer->updatePointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
		}
		// 输出窗口
		consoleLog(QString::fromLocal8Bit("删除点云"), QString::fromLocal8Bit("被选中点云"), "", "");
		viewer->resetCamera();//重置相机角度
		ui.qvtkWidget->update();
	}
	else
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("未选中任何点云！"));
		return;
	}

}
//右键修改点云颜色
void QtApplication::dataColorChange()
{
	if (ui.tree_PointCloud->selectedItems().size())
	{
		PointColorChange();
	}
	else
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("提示信息"),
			QString::fromLocal8Bit("未选中任何点云！"));
		return;
	}
}



/*****    操作记录管理窗口函数实现   *****/

//操作记录窗口的右击响应菜单
void QtApplication::popMenu_Console(const QPoint&)
{
	QAction ClearConsoleTable(QString::fromLocal8Bit("清空操作记录"), this);
	QAction EnableConsoleTable(QString::fromLocal8Bit("启用操作记录"), this);
	QAction DisableConsoleTable(QString::fromLocal8Bit("禁用操作记录"), this);

	connect(&ClearConsoleTable, &QAction::triggered, this, &QtApplication::clearConsole);
	connect(&EnableConsoleTable, &QAction::triggered, this, &QtApplication::enableConsole);
	connect(&DisableConsoleTable, &QAction::triggered, this, &QtApplication::disableConsole);

	QPoint pos;
	QMenu *popMenu = new QMenu(this);//定义一个右键弹出菜单
	//QMenu popMenu(ui.table_Console);
	popMenu->addAction(&ClearConsoleTable);
	popMenu->addAction(&EnableConsoleTable);
	popMenu->addAction(&DisableConsoleTable);

	if (enable_console == true)
	{ 
		popMenu->actions()[1]->setVisible(false);
		popMenu->actions()[2]->setVisible(true);
	}
	else
	{
		popMenu->actions()[1]->setVisible(true);
		popMenu->actions()[2]->setVisible(false);

	}
	popMenu->exec(QCursor::pos()); //在当前鼠标位置显示
}
// 清空操作记录
void QtApplication::clearConsole(){
	ui.table_Console->clearContents();
	ui.table_Console->setRowCount(0);
}
// 启用操作记录
void QtApplication::enableConsole(){
	
	enable_console = true;
}
// 禁用操作记录
void QtApplication::disableConsole(){
	clearConsole();//操作记录禁用前清空操作记录
	enable_console = false;
}



