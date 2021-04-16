#include "showcartoon.h"
#include "ui_showcartoon.h"

ShowCartoonWindow::ShowCartoonWindow(Video *film,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowCartoonWindow)
{
    ui->setupUi(this);
    this->film = film;

    ui->out_name->setText(film->getTitle().c_str());
    ui->out_year->setText(std::to_string(film->getYear()).c_str());
    ui->out_duration->setText(film->getDuration().c_str());
    ui->out_country->setText(film->getCountry().c_str());
    ui->out_rating->setText(std::to_string(film->getRank()).c_str());
    std::string forChild = std::to_string(dynamic_cast<Cartoon*>(film)->getForChild());
    std::string view = std::to_string(dynamic_cast<Cartoon*>(film)->getWatched());
    if (forChild == "0"){
        ui->checkChild->setCheckState(Qt::Unchecked);
    }
    else if (forChild == "1"){
        ui->checkChild->setCheckState(Qt::Checked);
    }
    if (view == "0"){
        ui->CheckView->setCheckState(Qt::Unchecked);
    }
    else if (view == "1"){
        ui->CheckView->setCheckState(Qt::Checked);
    }

}

ShowCartoonWindow::~ShowCartoonWindow()
{
    delete ui;
}

void ShowCartoonWindow::on_OkButton_clicked()
{
    if (ui->checkChild->isChecked()){
        dynamic_cast<Cartoon*>(film)->setForChild(true);
    }
    else if (!ui->checkChild->isChecked()){
        dynamic_cast<Cartoon*>(film)->setForChild(false);
    }
    if (ui->CheckView->isChecked()){
        film->setWatched(true);
    }
    else if (!ui->CheckView->isChecked()){
        film->setWatched(false);
    }
    this->close();
}

void ShowCartoonWindow::on_CheckView_stateChanged(int arg1)
{
    if (ui->CheckView->isChecked()){
        dynamic_cast<Cartoon*>(film)->setWatched(true);
    }
    else{
        dynamic_cast<Cartoon*>(film)->setWatched(false);
    }
}
