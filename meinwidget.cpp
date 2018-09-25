#include <QtGui>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include "meinWidget.h"

meinWidget::meinWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Beenden"));
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    startButton = new QPushButton(tr("Start"));
    startButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));

    QPushButton *saver = new QPushButton(tr("Sichern"));
    saver->setFont(QFont("Times", 18, QFont::Bold));
    connect(saver, SIGNAL(clicked()), this, SLOT(saveFile()));

    QPushButton *loader = new QPushButton(tr("Laden"));
    loader->setFont(QFont("Times", 18, QFont::Bold));
    connect(loader, SIGNAL(clicked()), this, SLOT(loadFile()));


    meinZeichenFeld = new zeichenFeld;


    qApp->installEventFilter(this);
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(quit, 1, 0);
    gridLayout->addWidget(startButton,2,0);
    gridLayout->addWidget(saver,1,3);
    gridLayout->addWidget(loader,2,3);
    gridLayout->addWidget(meinZeichenFeld, 1, 1, 2, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);
}



// Die Steuerung des Avatars mit den Pfeiltasten wurde mit Hilfe der folgenden Internetseite gelöst:
// https://stackoverflow.com/questions/10942384/handling-left-and-right-key-events-in-qt


bool meinWidget::eventFilter(QObject *object, QEvent *e)
{
  if (e->type() == QEvent::KeyPress)
  {
  QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
  if (keyEvent->key() == Qt::Key_Left){
      meinZeichenFeld->y=meinZeichenFeld->y-8;
  }

  if (keyEvent->key() == Qt::Key_Right){
     meinZeichenFeld->y=meinZeichenFeld->y+8;
  }

  }
  return false;
}



void meinWidget::start(void)
{
    if (wechsel==anfang) {                          //Buttonwechsel von Start zu Pause
        startButton->setText("Pause");
        meinZeichenFeld->start();
    } else {
        startButton->setText("Start");
        meinZeichenFeld->stop();
    }

    if(wechsel==anfang){                            //Zustandswechsel
        wechsel=pause;
    } else {
        wechsel=anfang;
    }

}



void meinWidget::saveFile(void)
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getSaveFileName(this,
                                      tr("Speichern als"), ".", tr("Spielstand (*.myz)"));

    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht verwendet werden: ") + fileName,QMessageBox::Ok);
        }

        meinZeichenFeld->serialize(file);
        file.close();
        return;
    }
}



void meinWidget::loadFile(void)
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this,
                                      tr("Datei öffnen"), ".", tr("Spielstand (*.myz)"));

    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht geöffnet werden: ") + fileName,QMessageBox::Ok);
        }

        meinZeichenFeld->deserialize(file);
        file.close();
        return;
    }
}




