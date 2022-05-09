#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    //重写绘图事件
    void paintEvent(QPaintEvent *);

    //游戏场景对象指针
    PlayScene * play = NULL;

signals:
    //自定义信号，告诉主场景，点击了返回
    //自定义信号只需要申明，不需要实现
    void chooseSceneBack();

};

#endif // CHOOSELEVELSCENE_H
