#include "Series.h"

Series::Series(const std::string title, const int year,
	const std::string country, const std::string averageDuration, const float rank,
	const int seasons, const std::vector<int> episodes, const bool ended,
	const bool isWatched, const int lastWatchedSeason,
	const int lastWatchedEpisode) {

	this->title = title;
	this->year = year;
	this->country = country;
	this->duration = averageDuration;
	this->rank = rank;
	this->seasons = seasons;
	for (int i = 0; i < episodes.size(); i++)
	{
		int element = episodes[i];
		this->episodes.push_back(element);
	}
	this->ended = ended;
	this->watched = isWatched;
	this->lastWatchedSeason = lastWatchedSeason;
	this->lastWatchedEpisode = lastWatchedEpisode;
	this->type = series;
}
Series::Series(const Series& other) {
	this->title = other.getTitle();
	this->year = other.getYear();
	this->country = other.getCountry();
	this->duration = other.getDuration();
	this->rank = other.getRank();
	this->seasons = other.getSeasons();
	for (int i = 0; i < other.getEpisodes().size(); i++)
	{
		int element = other.getEpisodes().at(i);
		this->episodes.push_back(element);
	}
	this->ended = other.getEnded();
	this->watched = other.getWatched();
	this->lastWatchedSeason = other.getLastWatchedSeason();
	this->lastWatchedEpisode = other.getLastWatchedEpisode();
	this->type = series;
}

Series::~Series() {

}

int Series::getSeasons() const {
	return this->seasons;
}

std::vector<int> Series::getEpisodes() const {
	return this->episodes;
}

bool Series::getEnded() const {
	return this->ended;
}

int Series::getLastWatchedSeason() const {
	return this->lastWatchedSeason;
}

int Series::getLastWatchedEpisode() const {
	return this->lastWatchedEpisode;
}

void Series::setSeasons(const int& seasons) {
	this->seasons = seasons;
}

void Series::setEpisodes(const std::vector<int>& episodes) {
	for (int i = 0; i < episodes.size(); i++)
	{
		int element = episodes.at(i);
		this->episodes.push_back(element);
	}
}

void Series::setEnded(const bool& b) {
	this->ended = b;
}

void Series::setLastWatchedSeason(const int& lSeason) {
	this->lastWatchedSeason = lSeason;
}

void Series::setLastWatchedEpisode(const int& lEpisode) {
	this->lastWatchedEpisode = lEpisode;
}

VideoType Series::getType() const {
	return this->type;
}

void Series::printParams() const {
	std::cout << "/-------- SERIES --------/\n";
	std::cout << "Title: " << this->getTitle() << "\n";
	std::cout << "Year: " << this->getYear() << "\n";
	std::cout << "Country: " << this->getCountry() << "\n";
	std::cout << "Duration: " << this->getDuration() << "\n";
	std::cout << "Rank: " << this->getRank() << "\n";
	std::cout << "Seasons: " << this->getSeasons() << "\n";
	for (int i = 0; i < this->getEpisodes().size(); i++)
	{
		std::cout << this->getEpisodes().at(i) << " ";
	}
	std::cout << "\n";
	std::cout << "Ended: " << this->getEnded() << "\n";
	std::cout << "Watched: " << this->getWatched() << "\n";
	std::cout << "Last watched season: " << this->getLastWatchedSeason() << "\n";
	std::cout << "Last watched episode: " << this->getLastWatchedEpisode() << "\n";
	std::cout << "/-----------------------/\n";
}

void Series::clearEpisodes() {
	this->episodes.clear();
}