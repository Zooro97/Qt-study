#include "mainsence.h"
#include "ui_mainsence.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QSound>

MainSence::MainSence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainSence)
{
    ui->setupUi(this);

    //配置主场景
    //设置窗口固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币");

    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //准备开始音效
    QSound * startSound = new QSound(":/res/TapButtonSound.wav");
    //startSound->setLoops(10);//改为-1可以无限循环播放音效
    //startSound->play();

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    //开始按钮位置设置
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5,this->height() * 0.7);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;

    //监听选择关卡按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseScene->geometry());//调整窗口位置
        chooseScene->hide();//隐藏选择关卡
        this->show();//重新选择主场景
    });


    //开始按钮
    connect(startBtn,&MyPushButton::clicked,[=](){
//        qDebug() << "点击开始了";
        //播放开始音效资源
        startSound->play();
        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入到选择关卡场景中，以便显示弹起效果
        //0.5秒后让当前窗口执行以下程序
        QTimer::singleShot(500,this,[=](){
            //设置chooseScene场景的位置
            chooseScene->setGeometry(this->geometry());
            //首先隐藏开始主界面
            this->hide();
            //显示选择关卡场景
            chooseScene->show();
        });

    });

}


void MainSence::paintEvent(QPaintEvent *)
{
    //背景图
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    //painter.drawPixmap(0,0,pix);
    //底部有空白，需要对图片拉伸
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //在背景上画图标
    pix.load(":/res/Title.png");
    //缩放图片
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap(0,10,pix);

}

MainSence::~MainSence()
{
    delete ui;
}

