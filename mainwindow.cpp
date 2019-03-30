#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TMath.h"
#include "TString.h"
//#include <iostream>
//#include "TList.h"
#include "TFile.h"
#include "TTree.h"
#include "TGraph.h"
#include "qrootcanvas.h"
#include <QVBoxLayout>
#include <TSystem.h>
#include <QTimer>
#include <TH1F.h>
#include <TF1.h>
#include <QDebug>
#include <QWindow>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::changeEvent(QEvent *e)
{
    if(e->type() == QEvent::WindowStateChange){
        QWindowStateChangeEvent *event = static_cast<QWindowStateChangeEvent *>(e);
        if((event->oldState() & Qt::WindowMaximized)||
                (event->oldState() & Qt::WindowMinimized)||
                (event->oldState() & Qt::WindowNoState &&
                 this->windowState() == Qt::WindowMaximized)){
            if(ui->canvas->Canvas()){
                ui->canvas->Canvas()->Resize();
                ui->canvas->Canvas()->Update();
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_draw_clicked()
{
    static TH1F *h=new TH1F("h1f","TEST Random",200,0,10);
    h->Reset();
    h->SetFillStyle(3001);
    TF1 *f=new TF1("sqroot","abs(sin(x)/x)",0,10);
    h->FillRandom("sqroot",10000);
    h->Draw();
    ui->canvas->Canvas()->Modified();
    ui->canvas->Canvas()->Update();
}
