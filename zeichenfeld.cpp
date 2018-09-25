#include <QPainter>
#include <QtGui>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>

#include "zeichenFeld.h"



zeichenFeld::zeichenFeld(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(224, 238, 224)));
    setAutoFillBackground(true);
    setFixedSize(800,600);                                   // 800x600 große Zeichenflaeche
    y=385;
    setMouseTracking(false);

    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));    //Timer definiert
    increment=0;

}



void zeichenFeld::paintEvent(QPaintEvent *event)
{
    QPainter painter,painter2,painter3,painter4,painter5,
             painter6,painter7,painter8,painter9,painter10,
             painter11,painter12;

    //Avatar

    painter.begin(this);
    painter.setPen(QPen(Qt::darkGray,7));
    painter.drawRect(y,565,25,25);                          //gelblicher Avatar der Größe 25x25 platziert
    painter.fillRect(y,565,25,25,QColor(238,232,170));
    painter.end();

    //Score

    painter2.begin(this);
    QString anzahl = QString::number(zaehler);
    painter2.setPen(QPen(QColor(16,78,139)));
    painter2.setFont(QFont("Times",10));
    painter2.drawText(rect(), Qt::AlignLeft, anzahl);
    if (increment){
        zaehler++;                                      //Score erhöht sich nach und nach
    }
    painter2.end();

    //Leben


    painter3.begin(this);
    painter3.setPen(QPen(Qt::black,2));
    painter3.setBrush(QColor(255,106,106));
    painter3.drawEllipse(725,5,20,20);               //Drei rote Kreise mit schwarzem Rand in der rechten oberen Seite der
    painter3.drawEllipse(750,5,20,20);               //Zeichenfläche platziert. Diese stellen das Leben dar.
    painter3.drawEllipse(775,5,20,20);
    painter3.end();


    //Hindernis Nr.1

    painter4.begin(this);
    painter4.setPen(QPen(QColor(139,115,85),5));
    painter4.setBrush(QColor(238,180,180));
    painter4.drawEllipse(m,x,70,70);
    if (increment){
        x=x+8;                                         //Hindernis 1 und 2 stellen zwei rosa Kreise dar, die sich
    }                                                  //mit der Geschwindigkeit 8 bewegen
    if (x>650){
        x=-45;
        m=(rand()%750);                                //Durch eine Zufallszahl werden die Objekte platziert
    }
    painter4.end();

    //Hindernis Nr.2

    painter5.begin(this);
    painter5.setPen(QPen(QColor(139,115,85),5));
    painter5.setBrush(QColor(238,180,180));
    painter5.drawEllipse(m2,x2,70,70);
    if (increment){
        x2=x2+8;
    }
    if (x2>650){
        x2=-45;
        m2=(rand()%750);
    }
    painter5.end();


   //Hindernis Nr.3

    painter6.begin(this);
    QPen p (Qt::DotLine);
    p.setColor(QColor(139,95,101));
    p.setWidth(8);
    painter6.setPen(p);
    painter6.drawRect(m3,x3,120,45);
    painter6.fillRect(m3,x3,120,45,QColor(205,183,181));
    if (increment){
        x3=x3+10;                                           //Hindernis 3 und 4 stellen bräunliche Rechtecke dar, die
    }                                                       //sich mit der Geschwindigkeit 10 bewegen
    if (x3>650){
        x3=-70;
        m3=(rand()%750);
    }
    painter6.end();


    //Hindernis Nr.4

    painter7.begin(this);
    QPen p2 (Qt::DotLine);
    p2.setColor(QColor(139,95,101));
    p2.setWidth(8);
    painter7.setPen(p2);
    painter7.drawRect(m4,x4,120,45);
    painter7.fillRect(m4,x4,120,45,QColor(205,183,181));
    if (increment){
        x4=x4+10;
    }
    if (x4>650){
        x4=-70;
        m4=(rand()%750);
    }
    painter7.end();


    //Hindernis Nr.5

    painter8.begin(this);
    painter8.setPen(QPen(QColor(000,104,139),5));
    painter8.setBrush(QColor(121,205,205));
    painter8.drawEllipse(m5,x5,40,40);
    if (increment){
        x5=x5+12;                                   //Hindernis 5, 6 und 7 stellen blaue kleine Kreise dar, die
    }                                               //sich mit der Geschwindigkeit 12 bewegen
    if (x5>650){
        x5=-45;
        m5=(rand()%750);
    }
    painter8.end();


    //Hindernis Nr.6

    painter9.begin(this);
    painter9.setPen(QPen(QColor(000,104,139),5));
    painter9.setBrush(QColor(121,205,205));
    painter9.drawEllipse(m6,x6,40,40);
    if (increment){
        x6=x6+12;
    }
    if (x6>650){
        x6=-45;
        m6=(rand()%750);
    }
    painter9.end();


    //Hindernis Nr.7

    painter10.begin(this);
    painter10.setPen(QPen(QColor(000,104,139),5));
    painter10.setBrush(QColor(121,205,205));
    painter10.drawEllipse(m7,x7,40,40);
    if (increment){
        x7=x7+12;
    }
    if (x7>650){
        x7=-45;
        m7=(rand()%750);
    }
    painter10.end();

    //Hindernis Nr.8

    painter11.begin(this);
    QPen p3 (Qt::DotLine);
    p3.setColor(QColor(255,165,79));
    p3.setWidth(8);
    painter11.setPen(p3);
    painter11.drawRect(m8,x8,45,120);
    painter11.fillRect(m8,x8,45,120,QColor(255,231,186));
    if (increment){
        x8=x8+15;                                           //Hindernis 8 und 9 stellen orangefarbene Rechtecke dar,
    }                                                       //die sich mit der Geschwindigkeit 15 bewegen. Sie stellen
    if (x8>650){                                            //somit die schnellsten Hindernisse dar.
        x8=-150;
        m8=(rand()%750);
    }
    painter11.end();



    //Hindernis Nr.9

    painter12.begin(this);
    QPen p4 (Qt::DotLine);
    p4.setColor(QColor(255,165,79));
    p4.setWidth(8);
    painter12.setPen(p4);
    painter12.drawRect(m9,x9,45,120);
    painter12.fillRect(m9,x9,45,120,QColor(255,231,186));
    if (increment){
        x9=x9+15;
    }
    if (x9>650){
        x9=-150;
        m9=(rand()%750);
    }
    painter12.end();


}

void zeichenFeld::mousePressEvent(QMouseEvent *event)    //Alternative Steuerung des Avatars mit der linken und rechten Maustaste
{
    if(event->button()==Qt::LeftButton){
        y-=15;                             // 15 Pixel nach links
    }
    if(event->button()==Qt::RightButton){
        y+=15;                             // 15 Pixel nach rechts
    }


    update();
}

void zeichenFeld::serialize(QFile &file)
{
    QTextStream out(&file);

        out  << "p " << y << " " << zaehler << " "
             << m << " " << x << " " << m2 << " "
             << x2 << " " << m3 << " " << x3 << " "
             << m4 << " " << x4 << " " << m5 << " "
             << x5 << " " << m6 << " " << x6 << " "
             << m7 << " " << x7 << " " << m8 << " "
             << x8 << " " << m9 << " " << x9;
}


void zeichenFeld::deserialize(QFile &file)
{

    char d;
    QTextStream in(&file);

    while (in.status() == QTextStream::Ok)
    {
        in >> d;
        if (in.status() == QTextStream::ReadPastEnd) break;

        if (d!='p')
        {
            QMessageBox::warning(this, tr("Objektfehler"),
                                 tr("Folgender Objekttyp ist unbekannt: ") + d,QMessageBox::Ok);
            return;
        }

        in >> y >> zaehler >> m >> x >> m2 >> x2
                >> m3 >> x3 >> m4 >> x4 >> m5 >> x5
                >> m6 >> x6 >> m7 >> x7 >> m8 >> x8
                >> m9 >> x9;

    }

    update();
}

