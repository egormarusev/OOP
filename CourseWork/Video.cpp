#include "Video.h"

Video::~Video() {

}

VideoType Video::getType() const {
	return this->type;
}

std::string Video::getTitle() const {
	return this->title;
}

int Video::getYear() const {
	return this->year;
}

std::string Video::getCountry() const {
	return this->country;
}

std::string Video::getDuration() const {
	return this->duration;
}

float Video::getRank() const {
	return this->rank;
}

bool Video::getWatched() const {

    return this->watched;
}

void Video::setTitle(const std::string& title) {
	this->title = title;
}

void Video::setYear(const int& year) {
    if(year > 1880 && year < 2021) this->year = year;
}



void Video::setCountry(const std::string& country) {
	this->country = country;
}

void Video::setDuration(const std::string& duration) {
	this->duration = duration;
}

void Video::setRank(const float& rank) {
	this->rank = rank;
}

void Video::setWatched(const bool& b) {
	this->watched = b;
}
