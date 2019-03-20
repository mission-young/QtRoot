#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TMath.h"
#include "TString.h"
//#include <iostream>
//#include "TList.h"
#include "TFile.h"
#include "TTree.h"
#include "TGraph.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //std::cout<<TString("hello");
    TString s("nihao");
    s.Append("hello");
    s.Data();
    ui->setupUi(this);
    ui->label->setText(QString::number(TMath::Pi()+Int_t(32),10,10)+s.Data());
    TFile *f=new TFile("test.root","recreate");

    TTree *tree=new TTree("tree","tree");
    TGraph *gg=new TGraph();
    for (int i = 0; i < 100; ++i) {
        gg->SetPoint(i,TMath::Sin(i),TMath::CosH(i));
    }
    gg->Write();
    gg->Draw();
    tree->Write();
    f->Close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
