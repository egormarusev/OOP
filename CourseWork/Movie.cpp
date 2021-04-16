#include "Movie.h"


Movie::Movie(const std::string title, const int year, const std::string genre,
	const std::string country, const std::string duration, const float rank, const bool watched) {
	this->title = title;
	this->year = year;
	this->genre = genre;
	this->country = country;
	this->duration = duration;
	this->rank = rank;
	this->watched = watched;
	this->type = movie;
}

Movie::Movie(const Movie& other) {
	this->title = other.getTitle();
	this->year = other.getYear();
	this->genre = other.getGenre();
	this->country = other.getCountry();
	this->duration = other.getDuration();
	this->rank = other.getRank();
	this->watched = other.getWatched();
	this->type = movie;
}


std::string Movie::getGenre() const {
	return this->genre;
}

void Movie::setGenre(const std::string& genre) {
	this->genre = genre;
}

Movie::~Movie() {

}

VideoType Movie::getType() const {
	return this->type;
}

void Movie::printParams() const {
	std::cout << "/-------- MOVIE --------/\n";
	std::cout << "Title: " << this->getTitle() << "\n";
	std::cout << "Year: " << this->getYear() << "\n";
	std::cout << "Genre: " << this->getGenre() << "\n";
	std::cout << "Country: " << this->getCountry() << "\n";
	std::cout << "Duration: " << this->getDuration() << "\n";
	
	std::cout << "Rank: " << this->getRank() << "\n";
	std::cout << "Watched: " << this->getWatched() << "\n";
	std::cout << "/-----------------------/\n";
}