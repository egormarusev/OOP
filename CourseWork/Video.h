#pragma once
#include <string>
#include <vector>
#include <iostream>

const std::string TITLE_DEF = "TITLE";
const int YEAR_DEF = 2020;
const std::string GENRE_DEF = "GENRE";
const std::string COUNTRY_DEF = "COUNTRY";
const std::string DURATION_DEF = "DURATION";
const float RANK_DEF = 0.0;
const int SEASONS_DEF = 1;
const std::vector<int> EPISODES_DEF = { 1 };
const bool ENDED_DEF = false;
const std::string AVERAGE_DURATION_DEF = "AVERAGE DURATION";
const int L_WATCHED_SEASON_DEF = 1;
const int L_WATCHED_EPISODE_DEF = 1;
const bool WATCHED_DEF = true;
const bool FOR_CHILD_DEF = true;

enum VideoType {
	video,
	movie,
	series,
	cartoon
};

class Video
{
protected:
	VideoType type;
	std::string title;
	int year;
	std::string country;
	std::string duration;
	float rank;
	bool watched;
public:
	virtual ~Video();
	virtual VideoType getType() const;
	virtual void printParams() const = 0;

	std::string getTitle() const;
	int getYear() const;
	std::string getCountry() const;
	std::string getDuration() const;
	float getRank() const;
	bool getWatched() const;

    void setTitle(const std::string& title);
	void setYear(const int& year);
	void setCountry(const std::string& country);
	void setDuration(const std::string& duration);
	void setRank(const float& rank);
	void setWatched(const bool& b);
};

