#include "Cartoon.h"


Cartoon::Cartoon(const std::string title, const int year,
	const std::string country, const std::string duration, const float rank, const bool watched,
	const bool isForChild) {
	this->title = title;
	this->year = year;
	this->country = country;
	this->duration = duration;
	this->rank = rank;
	this->watched = watched;
	this->isForChild = isForChild;
	this->type = cartoon;
}

Cartoon::Cartoon(const Cartoon& other) {
	this->title = other.getTitle();
	this->year = other.getYear();
	this->country = other.getCountry();
	this->duration = other.getDuration();
	this->rank = other.getRank();
	this->watched = other.getWatched();
	this->isForChild = other.getForChild();
	this->type = cartoon;
}

Cartoon::~Cartoon() {

}

bool Cartoon::getForChild() const {
	return this->isForChild;
}

void Cartoon::setForChild(const bool& b) {
	this->isForChild = b;
}

VideoType Cartoon::getType() const {
	return this->type;
}

void Cartoon::printParams() const {
	std::cout << "/------- CARTOON -------/\n";
	std::cout << "Title: " << this->getTitle() << "\n";
	std::cout << "Year: " << this->getYear() << "\n";
	std::cout << "Country: " << this->getCountry() << "\n";
	std::cout << "Duration: " << this->getDuration() << "\n";
	std::cout << "Rank: " << this->getRank() << "\n";
	std::cout << "Watched: " << this->getWatched() << "\n";
	std::cout << "For child: " << this->getForChild() << "\n";
	std::cout << "/-----------------------/\n";
}