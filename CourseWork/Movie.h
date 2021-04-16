#pragma once
#include "Video.h"

class Movie :
    public Video
{
private:
    std::string genre;
public:
    Movie(const std::string title = TITLE_DEF, const int year = YEAR_DEF, const std::string genre = GENRE_DEF,
        const std::string country = COUNTRY_DEF, const std::string duration = DURATION_DEF, const float rank = RANK_DEF, const bool watched = WATCHED_DEF);
    Movie(const Movie& other);
    ~Movie();

    std::string getGenre() const;
    void setGenre(const std::string& genre);

    VideoType getType() const override;

    void printParams() const override;
};

