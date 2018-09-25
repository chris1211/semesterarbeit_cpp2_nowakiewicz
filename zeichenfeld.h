#include <QtGui>
#include <QtCore>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QWidget>
#include <QTimer>

class zeichenFeld : public QWidget
{
    Q_OBJECT
public:
    zeichenFeld(QWidget *parent = 0);

    void start(void) { timer->start(30); increment=1; }
    void stop(void) { timer->stop(); increment=0; }

    void serialize(QFile &file);
    void deserialize(QFile &file);
    int y;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent( QMouseEvent* event);

private:
    int zaehler=0;
    int x=-75,x2=-165,x3=-70,x4=-170,x5=-60,x6=-160,x7=-260,x8=-350,x9=-500;
    int m=100,m2=500,m3=300,m4=600,m5=10,m6=720,m7=500,m8=10,m9=300;
    QTimer *timer;
    int increment;


};
