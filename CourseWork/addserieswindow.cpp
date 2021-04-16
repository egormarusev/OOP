#include "addserieswindow.h"
#include "ui_addserieswindow.h"
#include <iostream>

AddSeriesWindow::AddSeriesWindow(Collection *collection, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSeriesWindow)
{
    ui->setupUi(this);
    this->collection=collection;

    connect(ui->enter_title, &QLineEdit::cursorPositionChanged,this,
            &AddSeriesWindow::check_button_add);
    connect(ui->enter_year, &QLineEdit::cursorPositionChanged,this,
            &AddSeriesWindow::check_button_add);
    connect(ui->enter_country, &QLineEdit::cursorPositionChanged,this,
            &AddSeriesWindow::check_button_add);
    connect(ui->enter_duration, &QLineEdit::cursorPositionChanged,this,
            &AddSeriesWindow::check_button_add);
    connect(ui->enter_rating, &QLineEdit::cursorPositionChanged,this,
            &AddSeriesWindow::check_button_add);
    connect(ui->enter_seasons, &QLineEdit::cursorPositionChanged,this,
            &AddSeriesWindow::check_button_add);
    connect(ui->enter_episodes, &QLineEdit::cursorPositionChanged,this,
            &AddSeriesWindow::check_button_add);
    connect(ui->enter_lSeason, &QLineEdit::cursorPositionChanged,this,
            &AddSeriesWindow::check_button_add);
    connect(ui->enter_lEpisode, &QLineEdit::cursorPositionChanged,this,
            &AddSeriesWindow::check_button_add);


    ui->AddButton->setEnabled(false);
}

void AddSeriesWindow::check_button_add()
{
    if (ui->enter_title->text().size() != 0
        && ui->enter_year->text().size() !=0
        && ui->enter_country->text().size() != 0
        && ui->enter_duration->text().size() != 0
        && ui->enter_rating->text().size() != 0
        && ui->enter_episodes->text().size() != 0
        && ui->enter_seasons->text().size() != 0
        && ui->enter_lSeason->text().size() != 0
        && ui->enter_lEpisode->text().size() != 0){

        ui->AddButton->setEnabled(true);
    }
    else
    {
        ui->AddButton->setEnabled(false);
    }
}

AddSeriesWindow::~AddSeriesWindow()
{
    delete ui;
}

void AddSeriesWindow::on_CancelButton_clicked()
{
    this->close();
}

void AddSeriesWindow::on_AddButton_clicked()
{
    Series* temp = new Series;

    QString word = ui->enter_title->text();
    std::string word_ = word.toStdString();
    temp->setTitle(word_);

    word = ui->enter_year->text();
    word_ = word.toStdString();
    temp->setYear(std::stoi(word_));

    word = ui->enter_country->text();
    word_ = word.toStdString();
    temp->setCountry(word_);

    word = ui->enter_duration->text();
    word_ = word.toStdString();
    temp->setDuration(word_);

    word = ui->enter_rating->text();
    word_ = word.toStdString();
    temp->setRank(std::stof(word_));

    QString qSeasons = ui->enter_seasons->text();
    std::string qSeasons_ = qSeasons.toStdString();
    temp->setSeasons(std::stoi(qSeasons_));

    word = ui->enter_episodes->text();
    word_ = word.toStdString();
    std::vector<int> episodes;
    std::string substring;
    for (int i = 0; i < std::stoi(qSeasons_); i++)
    {
        substring = word_.substr(0, word_.find(' '));
        int i_substring = std::stoi(substring);
        episodes.push_back(i_substring);
        word_ = word_.substr(word_.find(' ') + 1, word_.length());
    }
    temp->clearEpisodes();
    temp->setEpisodes(episodes);

    word = ui->enter_lSeason->text();
    word_ = word.toStdString();
    temp->setLastWatchedSeason(std::stoi(word_));

    word = ui->enter_lEpisode->text();
    word_ = word.toStdString();
    temp->setLastWatchedEpisode(std::stoi(word_));

    if (ui->CheckEnded->isChecked()){
        temp->setEnded(true);
    }
    else if(!ui->CheckEnded->isChecked()){
        temp->setEnded(false);
    }

    if (ui->CheckWatched->isChecked()){
        temp->setWatched(true);
    }
    else if(!ui->CheckWatched->isChecked()){
        temp->setWatched(false);
    }

    collection->addVideo(temp);

    this->close();
}


