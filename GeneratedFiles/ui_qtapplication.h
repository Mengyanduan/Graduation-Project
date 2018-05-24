/********************************************************************************
** Form generated from reading UI file 'qtapplication.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTAPPLICATION_H
#define UI_QTAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_QtApplicationClass
{
public:
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Exit;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *action_Clear;
    QAction *action_Add;
    QAction *action_SaveAs;
    QAction *actionAdd;
    QAction *actionSaveAs;
    QAction *actionClear;
    QAction *action_DataManager;
    QAction *action_PropertiesManager;
    QAction *action_ConsoleManager;
    QAction *action_RGBManager;
    QAction *action_PointCloudColorChange;
    QAction *action_BackgroundColorChange;
    QAction *action_MainView;
    QAction *action_LeftView;
    QAction *action_TopView;
    QAction *action_Surface;
    QAction *action_Wireframe;
    QAction *actionPointCloudColorChange;
    QAction *actionBackgroundColorChange;
    QAction *actionMainView;
    QAction *actionLeftView;
    QAction *actionTopView;
    QAction *actionSurface;
    QAction *actionWireframe;
    QAction *action_Help;
    QAction *action_About;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionRandomColor;
    QAction *action_RandomColor;
    QAction *action_Simplify;
    QAction *action_Boundary;
    QAction *action_simplify2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVTKWidget *qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_View;
    QMenu *menu_Display;
    QMenu *menu_AngleView;
    QMenu *menu_Generate;
    QMenu *menu_Simplification;
    QMenu *menu_Feature_extraction;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dock_datatree;
    QWidget *dock_PointCloud;
    QGridLayout *gridLayout_2;
    QTreeWidget *tree_PointCloud;
    QDockWidget *dock_rgbcolor;
    QWidget *dock_RGB_Color;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_5;
    QLCDNumber *Red_lcdNumber;
    QLabel *Red_Label;
    QSlider *Red_Slider;
    QGridLayout *gridLayout_6;
    QLCDNumber *Green_lcdNumber;
    QSlider *Green_Slider;
    QLabel *Green_Label;
    QGridLayout *gridLayout_7;
    QLCDNumber *Blue_lcdNumber;
    QLabel *Blue_Label;
    QSlider *Blue_Slider;
    QGridLayout *gridLayout_9;
    QCheckBox *Cordinate;
    QCheckBox *Background;
    QGridLayout *gridLayout_8;
    QLCDNumber *PointSize_lcdNumber;
    QLabel *PointSize_label;
    QSlider *PointSize_Slider;
    QDockWidget *dock_properties;
    QWidget *dock_Properties;
    QGridLayout *gridLayout_3;
    QTableWidget *table_Properties;
    QDockWidget *dock_console;
    QWidget *dock_Console;
    QGridLayout *gridLayout_4;
    QTableWidget *table_Console;

    void setupUi(QMainWindow *QtApplicationClass)
    {
        if (QtApplicationClass->objectName().isEmpty())
            QtApplicationClass->setObjectName(QStringLiteral("QtApplicationClass"));
        QtApplicationClass->resize(1200, 681);
        QtApplicationClass->setMinimumSize(QSize(1200, 680));
        action_Open = new QAction(QtApplicationClass);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icon/Resources/Icon/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon);
        action_Save = new QAction(QtApplicationClass);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icon/Resources/Icon/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon1);
        action_Exit = new QAction(QtApplicationClass);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icon/Resources/Icon/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon2);
        actionOpen = new QAction(QtApplicationClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setIcon(icon);
        actionSave = new QAction(QtApplicationClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setIcon(icon1);
        action_Clear = new QAction(QtApplicationClass);
        action_Clear->setObjectName(QStringLiteral("action_Clear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icon/Resources/Icon/Clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Clear->setIcon(icon3);
        action_Add = new QAction(QtApplicationClass);
        action_Add->setObjectName(QStringLiteral("action_Add"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icon/Resources/Icon/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Add->setIcon(icon4);
        action_SaveAs = new QAction(QtApplicationClass);
        action_SaveAs->setObjectName(QStringLiteral("action_SaveAs"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icon/Resources/Icon/Save as.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SaveAs->setIcon(icon5);
        actionAdd = new QAction(QtApplicationClass);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionAdd->setIcon(icon4);
        actionSaveAs = new QAction(QtApplicationClass);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionSaveAs->setIcon(icon5);
        actionClear = new QAction(QtApplicationClass);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionClear->setIcon(icon3);
        action_DataManager = new QAction(QtApplicationClass);
        action_DataManager->setObjectName(QStringLiteral("action_DataManager"));
        action_DataManager->setCheckable(true);
        action_DataManager->setChecked(true);
        action_PropertiesManager = new QAction(QtApplicationClass);
        action_PropertiesManager->setObjectName(QStringLiteral("action_PropertiesManager"));
        action_PropertiesManager->setCheckable(true);
        action_PropertiesManager->setChecked(true);
        action_ConsoleManager = new QAction(QtApplicationClass);
        action_ConsoleManager->setObjectName(QStringLiteral("action_ConsoleManager"));
        action_ConsoleManager->setCheckable(true);
        action_ConsoleManager->setChecked(true);
        action_RGBManager = new QAction(QtApplicationClass);
        action_RGBManager->setObjectName(QStringLiteral("action_RGBManager"));
        action_RGBManager->setCheckable(true);
        action_RGBManager->setChecked(true);
        action_PointCloudColorChange = new QAction(QtApplicationClass);
        action_PointCloudColorChange->setObjectName(QStringLiteral("action_PointCloudColorChange"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icon/Resources/Icon/Pcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_PointCloudColorChange->setIcon(icon6);
        action_BackgroundColorChange = new QAction(QtApplicationClass);
        action_BackgroundColorChange->setObjectName(QStringLiteral("action_BackgroundColorChange"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Icon/Resources/Icon/Bcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_BackgroundColorChange->setIcon(icon7);
        action_MainView = new QAction(QtApplicationClass);
        action_MainView->setObjectName(QStringLiteral("action_MainView"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Icon/Resources/Icon/Main.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_MainView->setIcon(icon8);
        action_LeftView = new QAction(QtApplicationClass);
        action_LeftView->setObjectName(QStringLiteral("action_LeftView"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Icon/Resources/Icon/Left.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_LeftView->setIcon(icon9);
        action_TopView = new QAction(QtApplicationClass);
        action_TopView->setObjectName(QStringLiteral("action_TopView"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Icon/Resources/Icon/Top.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_TopView->setIcon(icon10);
        action_Surface = new QAction(QtApplicationClass);
        action_Surface->setObjectName(QStringLiteral("action_Surface"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Icon/Resources/Icon/Surface.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Surface->setIcon(icon11);
        action_Wireframe = new QAction(QtApplicationClass);
        action_Wireframe->setObjectName(QStringLiteral("action_Wireframe"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Icon/Resources/Icon/Wirefame.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Wireframe->setIcon(icon12);
        actionPointCloudColorChange = new QAction(QtApplicationClass);
        actionPointCloudColorChange->setObjectName(QStringLiteral("actionPointCloudColorChange"));
        actionPointCloudColorChange->setIcon(icon6);
        actionBackgroundColorChange = new QAction(QtApplicationClass);
        actionBackgroundColorChange->setObjectName(QStringLiteral("actionBackgroundColorChange"));
        actionBackgroundColorChange->setIcon(icon7);
        actionMainView = new QAction(QtApplicationClass);
        actionMainView->setObjectName(QStringLiteral("actionMainView"));
        actionMainView->setIcon(icon8);
        actionLeftView = new QAction(QtApplicationClass);
        actionLeftView->setObjectName(QStringLiteral("actionLeftView"));
        actionLeftView->setIcon(icon9);
        actionTopView = new QAction(QtApplicationClass);
        actionTopView->setObjectName(QStringLiteral("actionTopView"));
        actionTopView->setIcon(icon10);
        actionSurface = new QAction(QtApplicationClass);
        actionSurface->setObjectName(QStringLiteral("actionSurface"));
        actionSurface->setIcon(icon11);
        actionWireframe = new QAction(QtApplicationClass);
        actionWireframe->setObjectName(QStringLiteral("actionWireframe"));
        actionWireframe->setIcon(icon12);
        action_Help = new QAction(QtApplicationClass);
        action_Help->setObjectName(QStringLiteral("action_Help"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Icon/Resources/Icon/Help.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Help->setIcon(icon13);
        action_About = new QAction(QtApplicationClass);
        action_About->setObjectName(QStringLiteral("action_About"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Icon/Resources/Icon/Info.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_About->setIcon(icon14);
        actionHelp = new QAction(QtApplicationClass);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionHelp->setIcon(icon13);
        actionAbout = new QAction(QtApplicationClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout->setIcon(icon14);
        actionRandomColor = new QAction(QtApplicationClass);
        actionRandomColor->setObjectName(QStringLiteral("actionRandomColor"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Icon/Resources/Icon/Color.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRandomColor->setIcon(icon15);
        action_RandomColor = new QAction(QtApplicationClass);
        action_RandomColor->setObjectName(QStringLiteral("action_RandomColor"));
        action_RandomColor->setIcon(icon15);
        action_Simplify = new QAction(QtApplicationClass);
        action_Simplify->setObjectName(QStringLiteral("action_Simplify"));
        action_Boundary = new QAction(QtApplicationClass);
        action_Boundary->setObjectName(QStringLiteral("action_Boundary"));
        action_simplify2 = new QAction(QtApplicationClass);
        action_simplify2->setObjectName(QStringLiteral("action_simplify2"));
        centralWidget = new QWidget(QtApplicationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(qvtkWidget, 0, 0, 1, 1);

        QtApplicationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtApplicationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        menu_Display = new QMenu(menuBar);
        menu_Display->setObjectName(QStringLiteral("menu_Display"));
        menu_AngleView = new QMenu(menu_Display);
        menu_AngleView->setObjectName(QStringLiteral("menu_AngleView"));
        menu_Generate = new QMenu(menuBar);
        menu_Generate->setObjectName(QStringLiteral("menu_Generate"));
        menu_Simplification = new QMenu(menuBar);
        menu_Simplification->setObjectName(QStringLiteral("menu_Simplification"));
        menu_Feature_extraction = new QMenu(menuBar);
        menu_Feature_extraction->setObjectName(QStringLiteral("menu_Feature_extraction"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        QtApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtApplicationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtApplicationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtApplicationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtApplicationClass->setStatusBar(statusBar);
        dock_datatree = new QDockWidget(QtApplicationClass);
        dock_datatree->setObjectName(QStringLiteral("dock_datatree"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dock_datatree->sizePolicy().hasHeightForWidth());
        dock_datatree->setSizePolicy(sizePolicy);
        dock_datatree->setMinimumSize(QSize(230, 233));
        dock_datatree->setMaximumSize(QSize(400, 524287));
        dock_datatree->setFloating(false);
        dock_PointCloud = new QWidget();
        dock_PointCloud->setObjectName(QStringLiteral("dock_PointCloud"));
        gridLayout_2 = new QGridLayout(dock_PointCloud);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tree_PointCloud = new QTreeWidget(dock_PointCloud);
        tree_PointCloud->setObjectName(QStringLiteral("tree_PointCloud"));
        tree_PointCloud->setMinimumSize(QSize(0, 0));
        tree_PointCloud->setContextMenuPolicy(Qt::CustomContextMenu);
        tree_PointCloud->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tree_PointCloud->setColumnCount(1);
        tree_PointCloud->header()->setVisible(true);

        gridLayout_2->addWidget(tree_PointCloud, 0, 0, 1, 1);

        dock_datatree->setWidget(dock_PointCloud);
        QtApplicationClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dock_datatree);
        dock_rgbcolor = new QDockWidget(QtApplicationClass);
        dock_rgbcolor->setObjectName(QStringLiteral("dock_rgbcolor"));
        dock_rgbcolor->setMinimumSize(QSize(220, 400));
        dock_rgbcolor->setMaximumSize(QSize(500, 524287));
        dock_rgbcolor->setFloating(false);
        dock_rgbcolor->setAllowedAreas(Qt::AllDockWidgetAreas);
        dock_RGB_Color = new QWidget();
        dock_RGB_Color->setObjectName(QStringLiteral("dock_RGB_Color"));
        gridLayout_10 = new QGridLayout(dock_RGB_Color);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        Red_lcdNumber = new QLCDNumber(dock_RGB_Color);
        Red_lcdNumber->setObjectName(QStringLiteral("Red_lcdNumber"));
        Red_lcdNumber->setDigitCount(3);
        Red_lcdNumber->setMode(QLCDNumber::Dec);
        Red_lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        Red_lcdNumber->setProperty("value", QVariant(255));

        gridLayout_5->addWidget(Red_lcdNumber, 3, 1, 1, 1);

        Red_Label = new QLabel(dock_RGB_Color);
        Red_Label->setObjectName(QStringLiteral("Red_Label"));
        Red_Label->setTextFormat(Qt::AutoText);
        Red_Label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(Red_Label, 3, 0, 1, 1);

        Red_Slider = new QSlider(dock_RGB_Color);
        Red_Slider->setObjectName(QStringLiteral("Red_Slider"));
        Red_Slider->setMinimumSize(QSize(132, 0));
        Red_Slider->setMaximum(255);
        Red_Slider->setPageStep(10);
        Red_Slider->setSliderPosition(255);
        Red_Slider->setOrientation(Qt::Horizontal);
        Red_Slider->setTickInterval(0);

        gridLayout_5->addWidget(Red_Slider, 5, 0, 1, 2);


        gridLayout_10->addLayout(gridLayout_5, 1, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        Green_lcdNumber = new QLCDNumber(dock_RGB_Color);
        Green_lcdNumber->setObjectName(QStringLiteral("Green_lcdNumber"));
        Green_lcdNumber->setDigitCount(3);
        Green_lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        Green_lcdNumber->setProperty("value", QVariant(255));

        gridLayout_6->addWidget(Green_lcdNumber, 2, 1, 1, 1);

        Green_Slider = new QSlider(dock_RGB_Color);
        Green_Slider->setObjectName(QStringLiteral("Green_Slider"));
        Green_Slider->setMinimumSize(QSize(132, 0));
        Green_Slider->setMaximum(255);
        Green_Slider->setPageStep(10);
        Green_Slider->setSliderPosition(255);
        Green_Slider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(Green_Slider, 3, 0, 1, 2);

        Green_Label = new QLabel(dock_RGB_Color);
        Green_Label->setObjectName(QStringLiteral("Green_Label"));
        Green_Label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(Green_Label, 2, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_6, 3, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        Blue_lcdNumber = new QLCDNumber(dock_RGB_Color);
        Blue_lcdNumber->setObjectName(QStringLiteral("Blue_lcdNumber"));
        Blue_lcdNumber->setMinimumSize(QSize(0, 0));
        Blue_lcdNumber->setFrameShape(QFrame::Box);
        Blue_lcdNumber->setDigitCount(3);
        Blue_lcdNumber->setProperty("value", QVariant(255));
        Blue_lcdNumber->setProperty("intValue", QVariant(255));

        gridLayout_7->addWidget(Blue_lcdNumber, 1, 1, 1, 1);

        Blue_Label = new QLabel(dock_RGB_Color);
        Blue_Label->setObjectName(QStringLiteral("Blue_Label"));
        Blue_Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(Blue_Label, 1, 0, 1, 1);

        Blue_Slider = new QSlider(dock_RGB_Color);
        Blue_Slider->setObjectName(QStringLiteral("Blue_Slider"));
        Blue_Slider->setMinimumSize(QSize(132, 0));
        Blue_Slider->setMaximum(255);
        Blue_Slider->setPageStep(10);
        Blue_Slider->setSliderPosition(255);
        Blue_Slider->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(Blue_Slider, 2, 0, 1, 2);


        gridLayout_10->addLayout(gridLayout_7, 4, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        Cordinate = new QCheckBox(dock_RGB_Color);
        Cordinate->setObjectName(QStringLiteral("Cordinate"));

        gridLayout_9->addWidget(Cordinate, 0, 0, 1, 1);

        Background = new QCheckBox(dock_RGB_Color);
        Background->setObjectName(QStringLiteral("Background"));

        gridLayout_9->addWidget(Background, 1, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 6, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        PointSize_lcdNumber = new QLCDNumber(dock_RGB_Color);
        PointSize_lcdNumber->setObjectName(QStringLiteral("PointSize_lcdNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PointSize_lcdNumber->sizePolicy().hasHeightForWidth());
        PointSize_lcdNumber->setSizePolicy(sizePolicy1);
        PointSize_lcdNumber->setFrameShape(QFrame::Panel);
        PointSize_lcdNumber->setFrameShadow(QFrame::Raised);
        PointSize_lcdNumber->setDigitCount(1);
        PointSize_lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        PointSize_lcdNumber->setProperty("value", QVariant(1));

        gridLayout_8->addWidget(PointSize_lcdNumber, 0, 1, 1, 1);

        PointSize_label = new QLabel(dock_RGB_Color);
        PointSize_label->setObjectName(QStringLiteral("PointSize_label"));
        PointSize_label->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(PointSize_label, 0, 0, 1, 1);

        PointSize_Slider = new QSlider(dock_RGB_Color);
        PointSize_Slider->setObjectName(QStringLiteral("PointSize_Slider"));
        PointSize_Slider->setMinimumSize(QSize(132, 0));
        PointSize_Slider->setMinimum(1);
        PointSize_Slider->setMaximum(9);
        PointSize_Slider->setPageStep(10);
        PointSize_Slider->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(PointSize_Slider, 1, 0, 1, 2);


        gridLayout_10->addLayout(gridLayout_8, 5, 0, 1, 1);

        dock_rgbcolor->setWidget(dock_RGB_Color);
        QtApplicationClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_rgbcolor);
        dock_properties = new QDockWidget(QtApplicationClass);
        dock_properties->setObjectName(QStringLiteral("dock_properties"));
        sizePolicy.setHeightForWidth(dock_properties->sizePolicy().hasHeightForWidth());
        dock_properties->setSizePolicy(sizePolicy);
        dock_properties->setMinimumSize(QSize(230, 232));
        dock_properties->setMaximumSize(QSize(400, 524287));
        dock_Properties = new QWidget();
        dock_Properties->setObjectName(QStringLiteral("dock_Properties"));
        gridLayout_3 = new QGridLayout(dock_Properties);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        table_Properties = new QTableWidget(dock_Properties);
        if (table_Properties->columnCount() < 2)
            table_Properties->setColumnCount(2);
        if (table_Properties->rowCount() < 4)
            table_Properties->setRowCount(4);
        table_Properties->setObjectName(QStringLiteral("table_Properties"));
        table_Properties->setMinimumSize(QSize(0, 0));
        table_Properties->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_Properties->setShowGrid(false);
        table_Properties->setRowCount(4);
        table_Properties->setColumnCount(2);
        table_Properties->horizontalHeader()->setDefaultSectionSize(100);
        table_Properties->horizontalHeader()->setStretchLastSection(true);
        table_Properties->verticalHeader()->setVisible(false);

        gridLayout_3->addWidget(table_Properties, 0, 0, 1, 1);

        dock_properties->setWidget(dock_Properties);
        QtApplicationClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dock_properties);
        dock_console = new QDockWidget(QtApplicationClass);
        dock_console->setObjectName(QStringLiteral("dock_console"));
        dock_console->setMinimumSize(QSize(1000, 140));
        dock_console->setMaximumSize(QSize(524287, 524287));
        dock_Console = new QWidget();
        dock_Console->setObjectName(QStringLiteral("dock_Console"));
        gridLayout_4 = new QGridLayout(dock_Console);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        table_Console = new QTableWidget(dock_Console);
        if (table_Console->columnCount() < 5)
            table_Console->setColumnCount(5);
        table_Console->setObjectName(QStringLiteral("table_Console"));
        table_Console->setMinimumSize(QSize(300, 100));
        table_Console->setMaximumSize(QSize(524287, 524287));
        table_Console->setContextMenuPolicy(Qt::DefaultContextMenu);
        table_Console->setFrameShadow(QFrame::Plain);
        table_Console->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_Console->setShowGrid(false);
        table_Console->setColumnCount(5);
        table_Console->horizontalHeader()->setDefaultSectionSize(180);
        table_Console->horizontalHeader()->setStretchLastSection(true);
        table_Console->verticalHeader()->setVisible(false);

        gridLayout_4->addWidget(table_Console, 0, 0, 1, 1);

        dock_console->setWidget(dock_Console);
        QtApplicationClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dock_console);
        dock_datatree->raise();

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Display->menuAction());
        menuBar->addAction(menu_Feature_extraction->menuAction());
        menuBar->addAction(menu_Simplification->menuAction());
        menuBar->addAction(menu_Generate->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Add);
        menu_File->addAction(action_Save);
        menu_File->addAction(action_SaveAs);
        menu_File->addAction(action_Clear);
        menu_File->addAction(action_Exit);
        menu_View->addAction(action_DataManager);
        menu_View->addAction(action_PropertiesManager);
        menu_View->addAction(action_ConsoleManager);
        menu_View->addAction(action_RGBManager);
        menu_Display->addAction(action_RandomColor);
        menu_Display->addAction(action_PointCloudColorChange);
        menu_Display->addAction(action_BackgroundColorChange);
        menu_Display->addAction(menu_AngleView->menuAction());
        menu_AngleView->addAction(action_MainView);
        menu_AngleView->addAction(action_LeftView);
        menu_AngleView->addAction(action_TopView);
        menu_Generate->addAction(action_Surface);
        menu_Generate->addAction(action_Wireframe);
        menu_Simplification->addAction(action_Simplify);
        menu_Simplification->addAction(action_simplify2);
        menu_Feature_extraction->addAction(action_Boundary);
        menu_Help->addAction(action_Help);
        menu_Help->addAction(action_About);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionClear);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSaveAs);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRandomColor);
        mainToolBar->addAction(actionPointCloudColorChange);
        mainToolBar->addAction(actionBackgroundColorChange);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionMainView);
        mainToolBar->addAction(actionLeftView);
        mainToolBar->addAction(actionTopView);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSurface);
        mainToolBar->addAction(actionWireframe);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionHelp);
        mainToolBar->addAction(actionAbout);

        retranslateUi(QtApplicationClass);

        QMetaObject::connectSlotsByName(QtApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtApplicationClass)
    {
        QtApplicationClass->setWindowTitle(QApplication::translate("QtApplicationClass", "QtApplication", 0));
        action_Open->setText(QApplication::translate("QtApplicationClass", "\346\211\223\345\274\200", 0));
#ifndef QT_NO_TOOLTIP
        action_Open->setToolTip(QApplication::translate("QtApplicationClass", "\346\211\223\345\274\200", 0));
#endif // QT_NO_TOOLTIP
        action_Open->setShortcut(QApplication::translate("QtApplicationClass", "Ctrl+O", 0));
        action_Save->setText(QApplication::translate("QtApplicationClass", "\344\277\235\345\255\230", 0));
#ifndef QT_NO_TOOLTIP
        action_Save->setToolTip(QApplication::translate("QtApplicationClass", "\344\277\235\345\255\230", 0));
#endif // QT_NO_TOOLTIP
        action_Save->setShortcut(QApplication::translate("QtApplicationClass", "Ctrl+S", 0));
        action_Exit->setText(QApplication::translate("QtApplicationClass", "\351\200\200\345\207\272", 0));
        action_Exit->setShortcut(QApplication::translate("QtApplicationClass", "Ctrl+Q", 0));
        actionOpen->setText(QApplication::translate("QtApplicationClass", "\346\211\223\345\274\200", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("QtApplicationClass", "\346\211\223\345\274\200", 0));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("QtApplicationClass", "\344\277\235\345\255\230", 0));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("QtApplicationClass", "\344\277\235\345\255\230", 0));
#endif // QT_NO_TOOLTIP
        action_Clear->setText(QApplication::translate("QtApplicationClass", "\346\270\205\347\251\272", 0));
#ifndef QT_NO_TOOLTIP
        action_Clear->setToolTip(QApplication::translate("QtApplicationClass", "\346\270\205\347\251\272", 0));
#endif // QT_NO_TOOLTIP
        action_Clear->setShortcut(QApplication::translate("QtApplicationClass", "Ctrl+C", 0));
        action_Add->setText(QApplication::translate("QtApplicationClass", "\346\267\273\345\212\240", 0));
#ifndef QT_NO_TOOLTIP
        action_Add->setToolTip(QApplication::translate("QtApplicationClass", "\346\267\273\345\212\240", 0));
#endif // QT_NO_TOOLTIP
        action_SaveAs->setText(QApplication::translate("QtApplicationClass", "\345\217\246\345\255\230\344\270\272", 0));
#ifndef QT_NO_TOOLTIP
        action_SaveAs->setToolTip(QApplication::translate("QtApplicationClass", "\345\217\246\345\255\230\344\270\272", 0));
#endif // QT_NO_TOOLTIP
        actionAdd->setText(QApplication::translate("QtApplicationClass", "\346\267\273\345\212\240", 0));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("QtApplicationClass", "\346\267\273\345\212\240", 0));
#endif // QT_NO_TOOLTIP
        actionSaveAs->setText(QApplication::translate("QtApplicationClass", "\345\217\246\345\255\230\344\270\272", 0));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("QtApplicationClass", "\345\217\246\345\255\230\344\270\272", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setText(QApplication::translate("QtApplicationClass", "\346\270\205\347\251\272", 0));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("QtApplicationClass", "\346\270\205\347\251\272", 0));
#endif // QT_NO_TOOLTIP
        action_DataManager->setText(QApplication::translate("QtApplicationClass", "\347\202\271\344\272\221\346\226\207\344\273\266\347\256\241\347\220\206\347\252\227\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        action_DataManager->setToolTip(QApplication::translate("QtApplicationClass", "\347\202\271\344\272\221\346\226\207\344\273\266\347\256\241\347\220\206\345\231\250", 0));
#endif // QT_NO_TOOLTIP
        action_PropertiesManager->setText(QApplication::translate("QtApplicationClass", "\345\261\236\346\200\247\347\252\227\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        action_PropertiesManager->setToolTip(QApplication::translate("QtApplicationClass", "\345\261\236\346\200\247\347\252\227\345\217\243", 0));
#endif // QT_NO_TOOLTIP
        action_ConsoleManager->setText(QApplication::translate("QtApplicationClass", "\346\223\215\344\275\234\350\256\260\345\275\225\347\252\227\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        action_ConsoleManager->setToolTip(QApplication::translate("QtApplicationClass", "\346\223\215\344\275\234\350\256\260\345\275\225\347\252\227\345\217\243", 0));
#endif // QT_NO_TOOLTIP
        action_RGBManager->setText(QApplication::translate("QtApplicationClass", "\346\230\276\347\244\272\347\256\241\347\220\206\347\252\227\345\217\243", 0));
        action_PointCloudColorChange->setText(QApplication::translate("QtApplicationClass", "\346\233\264\346\224\271\347\202\271\344\272\221\351\242\234\350\211\262", 0));
#ifndef QT_NO_TOOLTIP
        action_PointCloudColorChange->setToolTip(QApplication::translate("QtApplicationClass", "\346\233\264\346\224\271\347\202\271\344\272\221\351\242\234\350\211\262", 0));
#endif // QT_NO_TOOLTIP
        action_BackgroundColorChange->setText(QApplication::translate("QtApplicationClass", "\346\233\264\346\224\271\350\203\214\346\231\257\351\242\234\350\211\262", 0));
#ifndef QT_NO_TOOLTIP
        action_BackgroundColorChange->setToolTip(QApplication::translate("QtApplicationClass", "\346\233\264\346\224\271\350\203\214\346\231\257\351\242\234\350\211\262", 0));
#endif // QT_NO_TOOLTIP
        action_MainView->setText(QApplication::translate("QtApplicationClass", "\344\270\273\350\247\206\345\233\276", 0));
        action_LeftView->setText(QApplication::translate("QtApplicationClass", "\345\267\246\350\247\206\345\233\276", 0));
        action_TopView->setText(QApplication::translate("QtApplicationClass", "\351\241\266\350\247\206\345\233\276", 0));
        action_Surface->setText(QApplication::translate("QtApplicationClass", "\347\275\221\346\240\274\351\235\242\347\211\207", 0));
        action_Wireframe->setText(QApplication::translate("QtApplicationClass", "\347\275\221\346\240\274\347\272\277\346\241\206", 0));
        actionPointCloudColorChange->setText(QApplication::translate("QtApplicationClass", "\344\277\256\346\224\271\347\202\271\344\272\221\351\242\234\350\211\262", 0));
        actionBackgroundColorChange->setText(QApplication::translate("QtApplicationClass", "\344\277\256\346\224\271\350\203\214\346\231\257\351\242\234\350\211\262", 0));
        actionMainView->setText(QApplication::translate("QtApplicationClass", "\344\270\273\350\247\206\345\233\276", 0));
        actionLeftView->setText(QApplication::translate("QtApplicationClass", "\345\267\246\350\247\206\345\233\276", 0));
        actionTopView->setText(QApplication::translate("QtApplicationClass", "\344\277\257\350\247\206\345\233\276", 0));
        actionSurface->setText(QApplication::translate("QtApplicationClass", "\347\275\221\346\240\274\351\235\242\347\211\207", 0));
        actionWireframe->setText(QApplication::translate("QtApplicationClass", "\347\275\221\346\240\274\347\272\277\346\241\206", 0));
        action_Help->setText(QApplication::translate("QtApplicationClass", "PCL\347\202\271\344\272\221\345\272\223\345\256\230\347\275\221", 0));
        action_About->setText(QApplication::translate("QtApplicationClass", "\345\205\263\344\272\216", 0));
        actionHelp->setText(QApplication::translate("QtApplicationClass", "PCL\347\202\271\344\272\221\345\272\223\345\256\230\347\275\221", 0));
        actionAbout->setText(QApplication::translate("QtApplicationClass", "\345\205\263\344\272\216", 0));
        actionRandomColor->setText(QApplication::translate("QtApplicationClass", "\351\232\217\346\234\272\347\235\200\350\211\262", 0));
#ifndef QT_NO_TOOLTIP
        actionRandomColor->setToolTip(QApplication::translate("QtApplicationClass", "\347\202\271\344\272\221\351\232\217\346\234\272\347\235\200\350\211\262", 0));
#endif // QT_NO_TOOLTIP
        action_RandomColor->setText(QApplication::translate("QtApplicationClass", "\347\202\271\344\272\221\351\232\217\346\234\272\347\235\200\350\211\262", 0));
        action_Simplify->setText(QApplication::translate("QtApplicationClass", "\347\256\200\345\214\226", 0));
#ifndef QT_NO_TOOLTIP
        action_Simplify->setToolTip(QApplication::translate("QtApplicationClass", "\347\202\271\344\272\221\347\256\200\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        action_Boundary->setText(QApplication::translate("QtApplicationClass", "\346\217\220\345\217\226\350\276\271\347\225\214", 0));
#ifndef QT_NO_TOOLTIP
        action_Boundary->setToolTip(QApplication::translate("QtApplicationClass", "\346\217\220\345\217\226\345\271\263\351\235\242\347\202\271\344\272\221\350\276\271\347\225\214", 0));
#endif // QT_NO_TOOLTIP
        action_simplify2->setText(QApplication::translate("QtApplicationClass", "\347\256\200\345\214\2262", 0));
        menu_File->setTitle(QApplication::translate("QtApplicationClass", "\346\226\207\344\273\266", 0));
        menu_View->setTitle(QApplication::translate("QtApplicationClass", "\350\247\206\345\233\276", 0));
        menu_Display->setTitle(QApplication::translate("QtApplicationClass", "\346\230\276\347\244\272", 0));
        menu_AngleView->setTitle(QApplication::translate("QtApplicationClass", "\350\247\206\350\247\222", 0));
        menu_Generate->setTitle(QApplication::translate("QtApplicationClass", "\344\270\211\347\273\264\351\207\215\345\273\272", 0));
        menu_Simplification->setTitle(QApplication::translate("QtApplicationClass", "\347\202\271\344\272\221\347\256\200\345\214\226", 0));
        menu_Feature_extraction->setTitle(QApplication::translate("QtApplicationClass", "\347\211\271\345\276\201\346\217\220\345\217\226", 0));
        menu_Help->setTitle(QApplication::translate("QtApplicationClass", "\345\270\256\345\212\251", 0));
        dock_datatree->setWindowTitle(QApplication::translate("QtApplicationClass", "\347\202\271\344\272\221\346\226\207\344\273\266\347\256\241\347\220\206\347\252\227\345\217\243", 0));
        QTreeWidgetItem *___qtreewidgetitem = tree_PointCloud->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("QtApplicationClass", "Point Cloud", 0));
        dock_rgbcolor->setWindowTitle(QApplication::translate("QtApplicationClass", "\346\230\276\347\244\272\347\256\241\347\220\206\347\252\227\345\217\243", 0));
        Red_Label->setText(QApplication::translate("QtApplicationClass", "<html><head/><body><p>\347\272\242</p></body></html>", 0));
        Green_Label->setText(QApplication::translate("QtApplicationClass", "<html><head/><body><p>\347\273\277</p></body></html>", 0));
        Blue_Label->setText(QApplication::translate("QtApplicationClass", "<html><head/><body><p>\350\223\235</p></body></html>", 0));
        Cordinate->setText(QApplication::translate("QtApplicationClass", "\345\235\220\346\240\207\347\263\273", 0));
        Background->setText(QApplication::translate("QtApplicationClass", "\350\203\214\346\231\257\351\242\234\350\211\262\357\274\232\346\232\227/\344\272\256", 0));
        PointSize_label->setText(QApplication::translate("QtApplicationClass", "<html><head/><body><p>Size</p></body></html>", 0));
        dock_properties->setWindowTitle(QApplication::translate("QtApplicationClass", "\345\261\236\346\200\247\347\252\227\345\217\243", 0));
        dock_console->setWindowTitle(QApplication::translate("QtApplicationClass", "\346\223\215\344\275\234\350\256\260\345\275\225\347\252\227\345\217\243", 0));
    } // retranslateUi

};

namespace Ui {
    class QtApplicationClass: public Ui_QtApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTAPPLICATION_H
