#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "numbers.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_stepen->hide();
    ui->label_stepen->hide();
    ui->lineEdit_stepen_2->hide();
    ui->label_stepen_2->hide();
    ui->lineEdit_znam1->hide();
    ui->lineEdit_chisl1->hide();
    ui->lineEdit_cel1->hide();
    ui->label_black1->hide();

    connect(ui->pushButton_plus,SIGNAL(clicked()), this, SLOT(def_operates()));
    connect(ui->pushButton_minus,SIGNAL(clicked()), this, SLOT(def_operates()));
    connect(ui->pushButton_ymnojenie,SIGNAL(clicked()), this, SLOT(def_operates()));
    connect(ui->pushButton_delenie,SIGNAL(clicked()), this, SLOT(def_operates()));

    connect(ui->pushButton_smena,SIGNAL(clicked()), this, SLOT(non_def_operates()));
    connect(ui->pushButton_sokrat,SIGNAL(clicked()), this, SLOT(non_def_operates()));
    connect(ui->pushButton_obmen,SIGNAL(clicked()), this, SLOT(non_def_operates()));

    connect(ui->pushButton_stepen,SIGNAL(clicked()), this, SLOT(stepen_operat()));

    connect(ui->pushButton_ravno,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(AC()));
    connect(ui->pushButton_otmena, SIGNAL(clicked()), this, SLOT(cancel()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_ymnojenie->setCheckable(true);
    ui->pushButton_delenie->setCheckable(true);
    ui->pushButton_smena->setCheckable(true);
    ui->pushButton_sokrat->setCheckable(true);
    ui->pushButton_obmen->setCheckable(true);
    ui->pushButton_stepen->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cancel()
{
    QString new_label_cel;
    QString new_label_chisl;
    QString new_label_znam;
    numbers A(ui->lineEdit_cel2->text().toInt(),ui->lineEdit_chisl2->text().toInt(),ui->lineEdit_znam2->text().toInt(), ui->label_stepen->text().toInt());
    if(pos == 1 or pos == 2 or pos == 3 or pos == 4)
    {
        ui->lineEdit_znam1->hide();
        ui->lineEdit_chisl1->hide();
        ui->lineEdit_cel1->hide();
        ui->label_black1->hide();
        ui->pushButton_plus->setCheckable(false);
        ui->pushButton_minus->setCheckable(false);
        ui->pushButton_ymnojenie->setCheckable(false);
        ui->pushButton_delenie->setCheckable(false);
        ui->lineEdit_stepen_2->setText(0);
        ui->lineEdit_znam1->setText(0);
        ui->lineEdit_chisl1->setText(0);
        ui->lineEdit_cel1->setText(0);
        ui->label_cel->setText("0");
        ui->label_znam->setText("0");
        ui->label_chisl->setText("0");
        ui->label_znak->setText(0);
    }else if(pos == 8)
    {
        new_label_chisl = QString::number(A.get_chisl());
        new_label_znam = QString::number(A.get_znam());
        ui->lineEdit_chisl2->setText(new_label_znam);
        ui->lineEdit_znam2->setText(new_label_chisl);
        ui->label_cel->setText("0");
        ui->label_znam->setText("0");
        ui->label_chisl->setText("0");
        ui->label_znak->setText(0);
    }
    else
    {
        ui->label_cel->setText("0");
        ui->label_znam->setText("0");
        ui->label_chisl->setText("0");
        ui->pushButton_smena->setCheckable(false);
        ui->pushButton_sokrat->setCheckable(false);
        ui->pushButton_obmen->setCheckable(false);
        ui->pushButton_stepen->setCheckable(false);
    }

}

void MainWindow::AC()
{

    ui->pushButton_plus->setCheckable(false);
    ui->pushButton_minus->setCheckable(false);
    ui->pushButton_ymnojenie->setCheckable(false);
    ui->pushButton_delenie->setCheckable(false);
    ui->pushButton_smena->setCheckable(false);
    ui->pushButton_sokrat->setCheckable(false);
    ui->pushButton_obmen->setCheckable(false);
    ui->pushButton_stepen->setCheckable(false);

    ui->lineEdit_stepen->hide();
    ui->label_stepen->hide();
    ui->lineEdit_stepen_2->hide();
    ui->label_stepen_2->hide();
    ui->lineEdit_znam1->hide();
    ui->lineEdit_chisl1->hide();
    ui->lineEdit_cel1->hide();
    ui->label_black1->hide();

    ui->lineEdit_stepen->setText(0);
    ui->lineEdit_stepen_2->setText(0);
    ui->lineEdit_stepen->setText(0);
    ui->lineEdit_znam1->setText(0);
    ui->lineEdit_chisl1->setText(0);
    ui->lineEdit_cel1->setText(0);


    ui->label_znak->setText(0);
    ui->lineEdit_cel2->setText(0);
    ui->lineEdit_chisl2->setText(0);
    ui->lineEdit_znam2->setText(0);
    ui->label_cel->setText("0");
    ui->label_znam->setText("0");
    ui->label_chisl->setText("0");

    ui->label_chisl->show();
    ui->label_black3->show();
    ui->label_znam->show();
    ui->label_cel->show();

    pos = 0;

}

void MainWindow::def_operates()
{

    stepn = 1;
    ui->lineEdit_znam1->show();
    ui->lineEdit_chisl1->show();
    ui->lineEdit_cel1->show();
    ui->label_black1->show();

    QPushButton *button = (QPushButton *)sender();
    ui->label_znak->setText(button->text());
    numbers A(ui->lineEdit_cel2->text().toInt(),ui->lineEdit_chisl2->text().toInt(),ui->lineEdit_znam2->text().toInt(), ui->label_stepen->text().toInt());
    QString new_label_cel;
    QString new_label_chisl;
    QString new_label_znam;
    new_label_cel = QString::number(A.get_cel());
    new_label_chisl = QString::number(A.get_chisl());
    new_label_znam = QString::number(A.get_znam());
    ui->lineEdit_cel1->setText(new_label_cel);
    ui->lineEdit_chisl1->setText(new_label_chisl);
    ui->lineEdit_znam1->setText(new_label_znam);
    if (A.get_cel()==0)
    {
        ui->lineEdit_cel1->setText(NULL);
    }
    else
    {
        ui->lineEdit_cel1->setText(new_label_cel);
    }

    button->setChecked(true);

    QString new_label_cel1;
    QString new_label_chisl1;
    QString new_label_znam1;
    new_label_cel = QString::number(0);
    new_label_chisl = QString::number(0);
    new_label_znam = QString::number(0);
    ui->lineEdit_cel2->setText(new_label_cel1);
    ui->lineEdit_chisl2->setText(new_label_chisl1);
    ui->lineEdit_znam2->setText(new_label_znam1);

    if (button->text()=="+")
    {
        pos = 1;
    }
    else if (button->text()=="-")
    {
        pos = 2;
    }
    else if (button->text()=="*")
    {
        pos = 3;
    }
    else if(button->text()=="/")
    {
        pos = 4;
    }
}

void MainWindow::stepen_operat()
{
    QPushButton *button = (QPushButton *)sender();
    if(stepn == 0)
    {
     ui->lineEdit_stepen ->show();
     ui->label_stepen->show();
    }

    button->setChecked(true);

    stepn = 0;

    pos = 5;


}

void MainWindow::non_def_operates()
{
    QPushButton *button = (QPushButton *)sender();
    if(button->text()=="+-")
    {
        pos = 6;
    }
    else if(button->text()=="~")
    {
        pos = 7;
    }
    else if(button->text()=="@")
    {
        pos = 8;
    }
    button->setChecked(true);
}

void MainWindow::operations()
{
    QString new_label_cel;
    QString new_label_chisl;
    QString new_label_znam;
    numbers A(ui->lineEdit_cel2->text().toInt(),ui->lineEdit_chisl2->text().toInt(),ui->lineEdit_znam2->text().toInt(), ui->lineEdit_stepen->text().toInt());
    numbers B(ui->lineEdit_cel1->text().toInt(),ui->lineEdit_chisl1->text().toInt(),ui->lineEdit_znam1->text().toInt(), ui->lineEdit_stepen_2->text().toInt());

    switch (pos) {
    case(1):

         A = A+B;

        if (A.get_chisl()==0)
        {
            ui->label_chisl->hide();
            ui->label_black3->hide();
            ui->label_znam->hide();
        }
        if (A.get_cel()==0)
        {
            ui->label_cel->hide();
        }
        if(A.get_cel()==0 and A.get_chisl()==0 and A.get_znam()==0)
        {
            ui->label_cel->show();
            ui->label_cel->setText(" 0 ");
        }
        new_label_cel = QString::number(A.get_cel());
        new_label_chisl = QString::number(A.get_chisl());
        new_label_znam = QString::number(A.get_znam());
        ui->label_cel->setText(new_label_cel);
        ui->label_chisl->setText(new_label_chisl);
        ui->label_znam->setText(new_label_znam);
        break;
    case(2):

        A = B-A;

        if (A.get_chisl()==0)
        {
            ui->label_chisl->hide();
            ui->label_black3->hide();
            ui->label_znam->hide();
        }
        if (A.get_cel()==0)
        {
            ui->label_cel->hide();
        }
        if(A.get_cel()==0 and A.get_chisl()==0)
        {
            ui->label_cel->show();
            ui->label_cel->setText(" 0 ");
        }
        new_label_cel = QString::number(A.get_cel());
        new_label_chisl = QString::number(A.get_chisl());
        new_label_znam = QString::number(A.get_znam());
        ui->label_cel->setText(new_label_cel);
        ui->label_chisl->setText(new_label_chisl);
        ui->label_znam->setText(new_label_znam);
        break;
    case(3):

         A = A*B;

        if (A.get_chisl()==0)
        {
            ui->label_chisl->hide();
            ui->label_black3->hide();
            ui->label_znam->hide();
        }
        if (A.get_cel()==0)
        {
            ui->label_cel->hide();
        }
        if(A.get_cel()==0 and A.get_chisl()==0 and A.get_znam()==0)
        {
            ui->label_cel->show();
            ui->label_cel->setText(" 0 ");
        }
        new_label_cel = QString::number(A.get_cel());
        new_label_chisl = QString::number(A.get_chisl());
        new_label_znam = QString::number(A.get_znam());
        ui->label_cel->setText(new_label_cel);
        ui->label_chisl->setText(new_label_chisl);
        ui->label_znam->setText(new_label_znam);
        break;
    case(4):

         A = B/A;


        if (A.get_chisl()==0)
        {
            ui->label_chisl->hide();
            ui->label_black3->hide();
            ui->label_znam->hide();
        }
        if (A.get_cel()==0)
        {
            ui->label_cel->hide();
        }
        if(A.get_cel()==0 and A.get_chisl()==0 and A.get_znam()==0)
        {
            ui->label_cel->show();
            ui->label_cel->setText(" 0 ");
        }
        new_label_cel = QString::number(A.get_cel());
        new_label_chisl = QString::number(A.get_chisl());
        new_label_znam = QString::number(A.get_znam());
        ui->label_cel->setText(new_label_cel);
        ui->label_chisl->setText(new_label_chisl);
        ui->label_znam->setText(new_label_znam);
        break;
    case(5):
        A.stepen();
        if (A.get_chisl()==0)
        {
           ui->label_chisl->hide();
           ui->label_black3->hide();
           ui->label_znam->hide();
        }
        if (A.get_cel()==0)
        {
            ui->label_cel->hide();
        }
        new_label_cel = QString::number(A.get_cel());
        new_label_chisl = QString::number(A.get_chisl());
        new_label_znam = QString::number(A.get_znam());
        ui->label_cel->setText(new_label_cel);
        ui->label_chisl->setText(new_label_chisl);
        ui->label_znam->setText(new_label_znam);
        break;
    case(6):

        A = A*(-1);
        if (A.get_chisl()==0)
        {
            ui->label_chisl->hide();
            ui->label_black3->hide();
            ui->label_znam->hide();
        }
        if (A.get_cel()==0)
        {
            ui->label_cel->setText("--");
        }
        new_label_cel = QString::number(A.get_cel());
        new_label_chisl = QString::number(A.get_chisl());
        new_label_znam = QString::number(A.get_znam());
        ui->label_cel->setText(new_label_cel);
        ui->label_chisl->setText(new_label_chisl);
        ui->label_znam->setText(new_label_znam);
        break;
    case(7):
        A--;
        if (A.get_chisl()==0)
        {
            ui->label_chisl->hide();
            ui->label_black3->hide();
            ui->label_znam->hide();
        }
        if (A.get_cel()==0)
        {
            ui->label_cel->hide();
        }
        new_label_cel = QString::number(A.get_cel());
        new_label_chisl = QString::number(A.get_chisl());
        new_label_znam = QString::number(A.get_znam());
        ui->label_cel->setText(new_label_cel);
        ui->label_chisl->setText(new_label_chisl);
        ui->label_znam->setText(new_label_znam);
        break;
    case(8):
        new_label_chisl = QString::number(A.get_chisl());
        new_label_znam = QString::number(A.get_znam());
        ui->lineEdit_chisl2->setText(new_label_znam);
        ui->lineEdit_znam2->setText(new_label_chisl);
        break;
    default:
        if (A.get_chisl()==0)
        {
            ui->label_chisl->hide();
            ui->label_black3->hide();
            ui->label_znam->hide();
        }
        if (A.get_cel()==0)
        {
            ui->label_cel->hide();
        }
        new_label_cel = QString::number(A.get_cel());
        new_label_chisl = QString::number(A.get_chisl());
        new_label_znam = QString::number(A.get_znam());
        ui->label_cel->setText(new_label_cel);
        ui->label_chisl->setText(new_label_chisl);
        ui->label_znam->setText(new_label_znam);
    }
}
