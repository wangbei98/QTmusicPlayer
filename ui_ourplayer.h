/********************************************************************************
** Form generated from reading UI file 'ourplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OURPLAYER_H
#define UI_OURPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ourplayer
{
public:
    QAction *actionAdd_files;
    QAction *actionRemove_File;
    QAction *actionAdd_to_Queue;
    QAction *actionPlay_Selected;
    QAction *actionClear_all;
    QAction *actiononline_remove_item;
    QAction *actionremoveall_online;
    QWidget *centralWidget;
    QTableWidget *tableWidget_local;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lblTimeElsp;
    QSlider *SeekSlider;
    QLabel *lblTimeRemaining_2;
    QPushButton *btn_shuffle;
    QPushButton *btn_repeat;
    QLabel *lblTimeRemaining;
    QSlider *volumeSlider;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_pre;
    QPushButton *btn_play;
    QPushButton *btn_next;
    QTabWidget *table;
    QWidget *tab_3;
    QTableWidget *tableWidget_schRes_2;
    QWidget *tab;
    QTableWidget *tableWidget_schRes;
    QLineEdit *input_key;
    QWidget *tab_2;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QPushButton *yuzhong_yueyu;
    QPushButton *xinqing_huankuai;
    QPushButton *fengge_xiaoqingxin;
    QPushButton *shiguang_lvxing;
    QPushButton *shiguang_90hou;
    QPushButton *tuijian_wangluo;
    QPushButton *xinqing_qingge;
    QPushButton *tuijian_suibiantingting;
    QPushButton *fengge_yaogun;
    QPushButton *yuzhong_riyu;
    QPushButton *yuzhong_huayu;
    QPushButton *btn_billboard;
    QLabel *label_4;
    QLabel *picture;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ourplayer)
    {
        if (ourplayer->objectName().isEmpty())
            ourplayer->setObjectName(QStringLiteral("ourplayer"));
        ourplayer->resize(902, 655);
        ourplayer->setStyleSheet(QStringLiteral(""));
        actionAdd_files = new QAction(ourplayer);
        actionAdd_files->setObjectName(QStringLiteral("actionAdd_files"));
        actionRemove_File = new QAction(ourplayer);
        actionRemove_File->setObjectName(QStringLiteral("actionRemove_File"));
        actionAdd_to_Queue = new QAction(ourplayer);
        actionAdd_to_Queue->setObjectName(QStringLiteral("actionAdd_to_Queue"));
        actionPlay_Selected = new QAction(ourplayer);
        actionPlay_Selected->setObjectName(QStringLiteral("actionPlay_Selected"));
        actionClear_all = new QAction(ourplayer);
        actionClear_all->setObjectName(QStringLiteral("actionClear_all"));
        actiononline_remove_item = new QAction(ourplayer);
        actiononline_remove_item->setObjectName(QStringLiteral("actiononline_remove_item"));
        actionremoveall_online = new QAction(ourplayer);
        actionremoveall_online->setObjectName(QStringLiteral("actionremoveall_online"));
        centralWidget = new QWidget(ourplayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget_local = new QTableWidget(centralWidget);
        if (tableWidget_local->columnCount() < 2)
            tableWidget_local->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_local->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_local->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_local->setObjectName(QStringLiteral("tableWidget_local"));
        tableWidget_local->setGeometry(QRect(20, 60, 201, 471));
        tableWidget_local->setContextMenuPolicy(Qt::ActionsContextMenu);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 540, 571, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblTimeElsp = new QLabel(layoutWidget);
        lblTimeElsp->setObjectName(QStringLiteral("lblTimeElsp"));

        horizontalLayout->addWidget(lblTimeElsp);

        SeekSlider = new QSlider(layoutWidget);
        SeekSlider->setObjectName(QStringLiteral("SeekSlider"));
        SeekSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(SeekSlider);

        lblTimeRemaining_2 = new QLabel(layoutWidget);
        lblTimeRemaining_2->setObjectName(QStringLiteral("lblTimeRemaining_2"));

        horizontalLayout->addWidget(lblTimeRemaining_2);

        btn_shuffle = new QPushButton(layoutWidget);
        btn_shuffle->setObjectName(QStringLiteral("btn_shuffle"));
        btn_shuffle->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral("image/shuffle.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_shuffle->setIcon(icon);

        horizontalLayout->addWidget(btn_shuffle);

        btn_repeat = new QPushButton(layoutWidget);
        btn_repeat->setObjectName(QStringLiteral("btn_repeat"));
        btn_repeat->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral("image/repeat.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_repeat->setIcon(icon1);

        horizontalLayout->addWidget(btn_repeat);

        lblTimeRemaining = new QLabel(layoutWidget);
        lblTimeRemaining->setObjectName(QStringLiteral("lblTimeRemaining"));

        horizontalLayout->addWidget(lblTimeRemaining);

        volumeSlider = new QSlider(layoutWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(volumeSlider);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 9);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(5, 1);
        horizontalLayout->setStretch(6, 2);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 540, 171, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_pre = new QPushButton(layoutWidget1);
        btn_pre->setObjectName(QStringLiteral("btn_pre"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_pre->sizePolicy().hasHeightForWidth());
        btn_pre->setSizePolicy(sizePolicy);
        btn_pre->setMaximumSize(QSize(50, 50));
        btn_pre->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral("image/skip-previous-circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pre->setIcon(icon2);
        btn_pre->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(btn_pre);

        btn_play = new QPushButton(layoutWidget1);
        btn_play->setObjectName(QStringLiteral("btn_play"));
        sizePolicy.setHeightForWidth(btn_play->sizePolicy().hasHeightForWidth());
        btn_play->setSizePolicy(sizePolicy);
        btn_play->setMaximumSize(QSize(50, 50));
        btn_play->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral("image/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8("image/\346\232\202\345\201\234.png"), QSize(), QIcon::Selected, QIcon::On);
        btn_play->setIcon(icon3);
        btn_play->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(btn_play);

        btn_next = new QPushButton(layoutWidget1);
        btn_next->setObjectName(QStringLiteral("btn_next"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_next->sizePolicy().hasHeightForWidth());
        btn_next->setSizePolicy(sizePolicy1);
        btn_next->setMaximumSize(QSize(50, 50));
        btn_next->setFocusPolicy(Qt::NoFocus);
        btn_next->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QStringLiteral("image/skip-next-circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon4);
        btn_next->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(btn_next);

        table = new QTabWidget(centralWidget);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(270, 10, 591, 531));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableWidget_schRes_2 = new QTableWidget(tab_3);
        if (tableWidget_schRes_2->columnCount() < 4)
            tableWidget_schRes_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_schRes_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_schRes_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_schRes_2->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_schRes_2->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        tableWidget_schRes_2->setObjectName(QStringLiteral("tableWidget_schRes_2"));
        tableWidget_schRes_2->setGeometry(QRect(10, 30, 561, 461));
        tableWidget_schRes_2->setFocusPolicy(Qt::TabFocus);
        tableWidget_schRes_2->setLineWidth(4);
        tableWidget_schRes_2->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget_schRes_2->setShowGrid(false);
        tableWidget_schRes_2->setGridStyle(Qt::SolidLine);
        table->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableWidget_schRes = new QTableWidget(tab);
        if (tableWidget_schRes->columnCount() < 4)
            tableWidget_schRes->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_schRes->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_schRes->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_schRes->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_schRes->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        tableWidget_schRes->setObjectName(QStringLiteral("tableWidget_schRes"));
        tableWidget_schRes->setGeometry(QRect(10, 30, 561, 461));
        tableWidget_schRes->setFocusPolicy(Qt::TabFocus);
        tableWidget_schRes->setLineWidth(4);
        tableWidget_schRes->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget_schRes->setShowGrid(false);
        tableWidget_schRes->setGridStyle(Qt::SolidLine);
        input_key = new QLineEdit(tab);
        input_key->setObjectName(QStringLiteral("input_key"));
        input_key->setGeometry(QRect(10, 0, 201, 21));
        table->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 40, 591, 441));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        yuzhong_yueyu = new QPushButton(layoutWidget2);
        yuzhong_yueyu->setObjectName(QStringLiteral("yuzhong_yueyu"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(yuzhong_yueyu->sizePolicy().hasHeightForWidth());
        yuzhong_yueyu->setSizePolicy(sizePolicy2);
        yuzhong_yueyu->setMaximumSize(QSize(120, 120));
        yuzhong_yueyu->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(yuzhong_yueyu, 2, 3, 1, 1);

        xinqing_huankuai = new QPushButton(layoutWidget2);
        xinqing_huankuai->setObjectName(QStringLiteral("xinqing_huankuai"));
        sizePolicy2.setHeightForWidth(xinqing_huankuai->sizePolicy().hasHeightForWidth());
        xinqing_huankuai->setSizePolicy(sizePolicy2);
        xinqing_huankuai->setMaximumSize(QSize(120, 120));
        xinqing_huankuai->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(xinqing_huankuai, 1, 2, 1, 1);

        fengge_xiaoqingxin = new QPushButton(layoutWidget2);
        fengge_xiaoqingxin->setObjectName(QStringLiteral("fengge_xiaoqingxin"));
        sizePolicy2.setHeightForWidth(fengge_xiaoqingxin->sizePolicy().hasHeightForWidth());
        fengge_xiaoqingxin->setSizePolicy(sizePolicy2);
        fengge_xiaoqingxin->setMaximumSize(QSize(120, 120));
        fengge_xiaoqingxin->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(fengge_xiaoqingxin, 1, 3, 1, 1);

        shiguang_lvxing = new QPushButton(layoutWidget2);
        shiguang_lvxing->setObjectName(QStringLiteral("shiguang_lvxing"));
        sizePolicy2.setHeightForWidth(shiguang_lvxing->sizePolicy().hasHeightForWidth());
        shiguang_lvxing->setSizePolicy(sizePolicy2);
        shiguang_lvxing->setMaximumSize(QSize(120, 120));
        shiguang_lvxing->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(shiguang_lvxing, 1, 0, 1, 1);

        shiguang_90hou = new QPushButton(layoutWidget2);
        shiguang_90hou->setObjectName(QStringLiteral("shiguang_90hou"));
        sizePolicy2.setHeightForWidth(shiguang_90hou->sizePolicy().hasHeightForWidth());
        shiguang_90hou->setSizePolicy(sizePolicy2);
        shiguang_90hou->setMaximumSize(QSize(120, 120));
        shiguang_90hou->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(shiguang_90hou, 0, 3, 1, 1);

        tuijian_wangluo = new QPushButton(layoutWidget2);
        tuijian_wangluo->setObjectName(QStringLiteral("tuijian_wangluo"));
        sizePolicy2.setHeightForWidth(tuijian_wangluo->sizePolicy().hasHeightForWidth());
        tuijian_wangluo->setSizePolicy(sizePolicy2);
        tuijian_wangluo->setMaximumSize(QSize(120, 120));
        tuijian_wangluo->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(tuijian_wangluo, 0, 1, 1, 1);

        xinqing_qingge = new QPushButton(layoutWidget2);
        xinqing_qingge->setObjectName(QStringLiteral("xinqing_qingge"));
        sizePolicy2.setHeightForWidth(xinqing_qingge->sizePolicy().hasHeightForWidth());
        xinqing_qingge->setSizePolicy(sizePolicy2);
        xinqing_qingge->setMaximumSize(QSize(120, 120));
        xinqing_qingge->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(xinqing_qingge, 2, 0, 1, 1);

        tuijian_suibiantingting = new QPushButton(layoutWidget2);
        tuijian_suibiantingting->setObjectName(QStringLiteral("tuijian_suibiantingting"));
        sizePolicy2.setHeightForWidth(tuijian_suibiantingting->sizePolicy().hasHeightForWidth());
        tuijian_suibiantingting->setSizePolicy(sizePolicy2);
        tuijian_suibiantingting->setMaximumSize(QSize(120, 120));
        tuijian_suibiantingting->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(tuijian_suibiantingting, 0, 2, 1, 1);

        fengge_yaogun = new QPushButton(layoutWidget2);
        fengge_yaogun->setObjectName(QStringLiteral("fengge_yaogun"));
        sizePolicy2.setHeightForWidth(fengge_yaogun->sizePolicy().hasHeightForWidth());
        fengge_yaogun->setSizePolicy(sizePolicy2);
        fengge_yaogun->setMaximumSize(QSize(120, 120));
        fengge_yaogun->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(fengge_yaogun, 1, 1, 1, 1);

        yuzhong_riyu = new QPushButton(layoutWidget2);
        yuzhong_riyu->setObjectName(QStringLiteral("yuzhong_riyu"));
        sizePolicy2.setHeightForWidth(yuzhong_riyu->sizePolicy().hasHeightForWidth());
        yuzhong_riyu->setSizePolicy(sizePolicy2);
        yuzhong_riyu->setMaximumSize(QSize(120, 120));
        yuzhong_riyu->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(yuzhong_riyu, 2, 2, 1, 1);

        yuzhong_huayu = new QPushButton(layoutWidget2);
        yuzhong_huayu->setObjectName(QStringLiteral("yuzhong_huayu"));
        sizePolicy2.setHeightForWidth(yuzhong_huayu->sizePolicy().hasHeightForWidth());
        yuzhong_huayu->setSizePolicy(sizePolicy2);
        yuzhong_huayu->setMaximumSize(QSize(120, 120));
        yuzhong_huayu->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(yuzhong_huayu, 2, 1, 1, 1);

        btn_billboard = new QPushButton(layoutWidget2);
        btn_billboard->setObjectName(QStringLiteral("btn_billboard"));
        sizePolicy2.setHeightForWidth(btn_billboard->sizePolicy().hasHeightForWidth());
        btn_billboard->setSizePolicy(sizePolicy2);
        btn_billboard->setMaximumSize(QSize(120, 120));
        btn_billboard->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(btn_billboard, 0, 0, 1, 1);

        table->addTab(tab_2, QString());
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 10, 131, 41));
        label_4->setStyleSheet(QLatin1String("font: 24pt \".SF NS Text\";\n"
"color: rgb(252, 0, 9);"));
        picture = new QLabel(centralWidget);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setGeometry(QRect(231, 544, 41, 41));
        ourplayer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ourplayer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 902, 26));
        ourplayer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ourplayer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ourplayer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ourplayer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ourplayer->setStatusBar(statusBar);
        toolBar = new QToolBar(ourplayer);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        ourplayer->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(ourplayer);

        table->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ourplayer);
    } // setupUi

    void retranslateUi(QMainWindow *ourplayer)
    {
        ourplayer->setWindowTitle(QApplication::translate("ourplayer", "MainWindow", nullptr));
        actionAdd_files->setText(QApplication::translate("ourplayer", "Add_files", nullptr));
        actionRemove_File->setText(QApplication::translate("ourplayer", "Remove_File", nullptr));
        actionAdd_to_Queue->setText(QApplication::translate("ourplayer", "Add_to_Queue", nullptr));
        actionPlay_Selected->setText(QApplication::translate("ourplayer", "Play_Selected", nullptr));
        actionClear_all->setText(QApplication::translate("ourplayer", "Clear_all", nullptr));
        actiononline_remove_item->setText(QApplication::translate("ourplayer", "online_remove_item", nullptr));
        actionremoveall_online->setText(QApplication::translate("ourplayer", "removeall_online", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_local->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ourplayer", "songName", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_local->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ourplayer", "filePath", nullptr));
        lblTimeElsp->setText(QApplication::translate("ourplayer", "00:00", nullptr));
        lblTimeRemaining_2->setText(QApplication::translate("ourplayer", "00:00", nullptr));
        btn_shuffle->setText(QString());
        btn_repeat->setText(QString());
        lblTimeRemaining->setText(QApplication::translate("ourplayer", "Volume", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        btn_pre->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        btn_pre->setText(QString());
        btn_play->setText(QString());
        btn_next->setText(QString());
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_schRes_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("ourplayer", "songName", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_schRes_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("ourplayer", "artistName", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_schRes_2->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("ourplayer", "info", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_schRes_2->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("ourplayer", "id", nullptr));
        table->setTabText(table->indexOf(tab_3), QApplication::translate("ourplayer", "online_songlist", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_schRes->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("ourplayer", "songName", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_schRes->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("ourplayer", "artistName", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_schRes->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("ourplayer", "info", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_schRes->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("ourplayer", "id", nullptr));
        input_key->setText(QApplication::translate("ourplayer", "\346\220\234\347\264\242", nullptr));
        table->setTabText(table->indexOf(tab), QApplication::translate("ourplayer", "search", nullptr));
        yuzhong_yueyu->setText(QApplication::translate("ourplayer", "\347\262\244\350\257\255", nullptr));
        xinqing_huankuai->setText(QApplication::translate("ourplayer", "\346\254\242\345\277\253", nullptr));
        fengge_xiaoqingxin->setText(QApplication::translate("ourplayer", "\345\260\217\346\270\205\346\226\260", nullptr));
        shiguang_lvxing->setText(QApplication::translate("ourplayer", "\346\227\205\350\241\214", nullptr));
        shiguang_90hou->setText(QApplication::translate("ourplayer", "90\345\220\216", nullptr));
        tuijian_wangluo->setText(QApplication::translate("ourplayer", "\347\275\221\347\273\234\346\216\250\350\215\220", nullptr));
        xinqing_qingge->setText(QApplication::translate("ourplayer", "\346\203\205\346\255\214", nullptr));
        tuijian_suibiantingting->setText(QApplication::translate("ourplayer", "\351\232\217\344\276\277\345\220\254\345\220\254", nullptr));
        fengge_yaogun->setText(QApplication::translate("ourplayer", "\346\221\207\346\273\232", nullptr));
        yuzhong_riyu->setText(QApplication::translate("ourplayer", "\346\227\245\350\257\255", nullptr));
        yuzhong_huayu->setText(QApplication::translate("ourplayer", "\345\215\216\350\257\255", nullptr));
        btn_billboard->setText(QApplication::translate("ourplayer", "\345\205\254\345\221\212\347\211\214", nullptr));
        table->setTabText(table->indexOf(tab_2), QApplication::translate("ourplayer", "FM", nullptr));
        label_4->setText(QApplication::translate("ourplayer", "MediaPlayer", nullptr));
        picture->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("ourplayer", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ourplayer: public Ui_ourplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OURPLAYER_H
