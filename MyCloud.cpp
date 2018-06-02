#include "MyCloud.h"


MyCloud::MyCloud()
{
}


MyCloud::~MyCloud()
{
}

void MyCloud::initial()
{
	cloud.reset(new PointCloudT);
	cloud->resize(0);//RGBA点云初始化长宽，height=0无序点云
	filename = "";
	subname = "";
	dirname = "E:\\Date\\PointCloud\\";
}