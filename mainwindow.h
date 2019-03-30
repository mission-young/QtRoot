#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qrootcanvas.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual void changeEvent(QEvent *e);
    ~MainWindow();
public slots:

private:
    Ui::MainWindow *ui;
protected:

private slots:
    void on_btn_draw_clicked();
};

#endif // MAINWINDOW_H
