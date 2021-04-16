#include "addmoviewindow.h"
#include "ui_addmoviewindow.h"

AddMovieWindow::AddMovieWindow(Collection *collection, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovieWindow)
{
    ui->setupUi(this);
    this->collection=collection;

    connect(ui->enter_title, &QLineEdit::cursorPositionChanged,this,
            &AddMovieWindow::check_button_add);
    connect(ui->enter_year, &QLineEdit::cursorPositionChanged,this,
            &AddMovieWindow::check_button_add);
    connect(ui->enter_duration, &QLineEdit::cursorPositionChanged,this,
            &AddMovieWindow::check_button_add);
    connect(ui->enter_rating, &QLineEdit::cursorPositionChanged,this,
            &AddMovieWindow::check_button_add);
    connect(ui->enter_country, &QLineEdit::cursorPositionChanged,this,
            &AddMovieWindow::check_button_add);
    connect(ui->enter_genre, &QLineEdit::cursorPositionChanged,this,
            &AddMovieWindow::check_button_add);

    ui->AddButton->setEnabled(false);

}

void AddMovieWindow::check_button_add()
{
    if (ui->enter_title->text().size() != 0
        && ui->enter_year->text().size() !=0
        && ui->enter_duration->text().size() != 0
        && ui->enter_country->text().size() != 0
        && ui->enter_genre->text().size() != 0
        && ui->enter_rating->text().size() != 0){

        ui->AddButton->setEnabled(true);
    }
    else
    {
        ui->AddButton->setEnabled(false);
    }
}

AddMovieWindow::~AddMovieWindow()
{
    delete ui;
}

void AddMovieWindow::on_CancelButton_clicked()
{
    this->close();
}

void AddMovieWindow::on_AddButton_clicked()
{
    Movie* temp = new Movie;
    QString word = ui->enter_title->text();
    std::string word_ = word.toStdString();
    temp->setTitle(word_);

    word = ui->enter_year->text();
    word_ = word.toStdString();
    temp->setYear(std::stoi(word_));

    word = ui->enter_genre->text();
    word_ = word.toStdString();
    temp->setGenre(word_);

    word = ui->enter_duration->text();
    word_ = word.toStdString();
    temp->setDuration(word_);

    word = ui->enter_country->text();
    word_ = word.toStdString();
    temp->setCountry(word_);

    word = ui->enter_rating->text();
    word_ = word.toStdString();
    temp->setRank(std::stof(word_));

    if (ui->checkWatched->isChecked()){
        temp->setWatched(true);
    }
    else if(!ui->checkWatched->isChecked()){
        temp->setWatched(false);
    }



    collection->addVideo(temp);

    this->close();

}
