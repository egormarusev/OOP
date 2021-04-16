#include "showmoviewindow.h"
#include "ui_showmoviewindow.h"

ShowMovieWindow::ShowMovieWindow(Video *film,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowMovieWindow)
{
    ui->setupUi(this);
    this->film = film;

    ui->out_name->setText(film->getTitle().c_str());
    ui->out_year->setText(std::to_string(film->getYear()).c_str());
    ui->out_duration->setText(film->getDuration().c_str());
    ui->out_country->setText(film->getCountry().c_str());
    ui->out_rating->setText(std::to_string(film->getRank()).c_str());
    ui->out_genre->setText(dynamic_cast<Movie*>(film)->getGenre().c_str());
    std::string view = std::to_string(dynamic_cast<Movie*>(film)->getWatched());
    if (view == "0"){
        ui->CheckView->setCheckState(Qt::Unchecked);
    }
    else if (view == "1"){
        ui->CheckView->setCheckState(Qt::Checked);
    }

}

ShowMovieWindow::~ShowMovieWindow()
{
    delete ui;
}

void ShowMovieWindow::on_OkButton_clicked()
{
    if(ui->CheckView->isChecked()){
        film->setWatched(true);
    }
    else if(!ui->CheckView->isChecked()){
        film->setWatched(false);
    }
    this->close();
}

void ShowMovieWindow::on_CheckView_stateChanged(int arg1)
{
    if (ui->CheckView->isChecked()){
        dynamic_cast<Movie*>(film)->setWatched(true);
    }
    else{
        dynamic_cast<Movie*>(film)->setWatched(false);
    }
}
