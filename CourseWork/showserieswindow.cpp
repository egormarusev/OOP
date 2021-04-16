#include "showserieswindow.h"
#include "ui_showserieswindow.h"

ShowSeriesWindow::ShowSeriesWindow(Video *serial,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowSeriesWindow)
{
    ui->setupUi(this);
    this->serial = serial;

    ui->out_title->setText(serial->getTitle().c_str());

    ui->out_year->setText(std::to_string(serial->getYear()).c_str());

    ui->out_country->setText(serial->getCountry().c_str());

    ui->out_duration->setText(serial->getDuration().c_str());

    ui->out_rating->setText(std::to_string(serial->getRank()).c_str());

    std::string item = std::to_string(dynamic_cast<Series*>(serial)
                                      ->getSeasons());
    ui->out_seasons->setText(item.c_str());

    item = std::to_string(dynamic_cast<Series*>(serial)->getEpisodes()[0]);

    for(int i = 1; i < dynamic_cast<Series*>(serial)
        ->getSeasons(); i++){
        int amount = dynamic_cast<Series*>(serial)->getEpisodes()[i];
        item = item + " " + std::to_string(amount);
    }

    ui->out_episodes->setText(item.c_str());

    item = std::to_string(dynamic_cast<Series*>(serial)->getEnded());
    if (item == "0") {item = "Ended";}
    if (item == "1") {item = "Not Ended";}
    ui->out_ended->setText(item.c_str());

    std::string watched = std::to_string(dynamic_cast<Series*>(serial)->getWatched());
    if (watched == "0"){
        ui->CheckWatched->setCheckState(Qt::Unchecked);
    }
    else if (watched == "1"){
        ui->CheckWatched->setCheckState(Qt::Checked);
    }
    item = std::to_string(dynamic_cast<Series*>(serial)->getLastWatchedSeason());
    ui->out_lSeason->setText(item.c_str());

    item = std::to_string(dynamic_cast<Series*>(serial)->getLastWatchedEpisode());
    ui->out_lEpisode->setText(item.c_str());
}

ShowSeriesWindow::~ShowSeriesWindow()
{
    delete ui;
}

void ShowSeriesWindow::on_OkButton_clicked()
{
    if (ui->CheckWatched->isChecked()){
        serial->setWatched(true);
    }
    else if (!ui->CheckWatched->isChecked()){
        serial->setWatched(false);
    }
    this->close();
}

void ShowSeriesWindow::on_CheckView_stateChanged(int arg1)
{
    if (ui->CheckWatched->isChecked()){
        dynamic_cast<Series*>(serial)->setWatched(true);
    }
    else{
        dynamic_cast<Series*>(serial)->setWatched(false);
    }
}

