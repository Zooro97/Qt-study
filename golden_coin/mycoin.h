#ifndef MYCOIN_H
#define MYCOIN_H
#include <QTimer>

#include <QPushButton>


class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);

    //参数代表传入的金币路径或者银币的路径
    MyCoin(QString btnImg);

    //金币属性
    int posX;//x坐标位置
    int posY;//y坐标位置
    bool flag;//正反标识

    //改变标志的方法
    void changeFlag();
    QTimer *timer1;//正面翻反面的定时器
    QTimer *timer2;//反面翻正面的定时器
    int min = 1;
    int max = 8;

    //执行动画标志
    bool isAnimation = false;

    //重写按下
    void mousePressEvent(QMouseEvent *e);

    //是否胜利标志
    bool isWin;

signals:

};

#endif // MYCOIN_H
