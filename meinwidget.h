#include <QWidget>
#include <QPushButton>
#include "zeichenfeld.h"

class meinWidget : public QWidget
{
  Q_OBJECT
public:
    meinWidget(QWidget *parent = 0);
    QPushButton *startButton;
    enum zustand{anfang,pause};
    enum zustand wechsel=anfang;

private:
    zeichenFeld *meinZeichenFeld;

private slots:
    void saveFile(void);
    void loadFile(void);
    void start(void);


protected:
     bool eventFilter(QObject *object, QEvent *e);
};
