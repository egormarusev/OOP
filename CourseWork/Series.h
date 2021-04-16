#pragma once
#include "Video.h"
#include <vector>
class Series :
    public Video
{
private:
    int seasons;
    std::vector<int> episodes;
    bool ended;
    int lastWatchedSeason;
    int lastWatchedEpisode;
public:
    Series(const std::string title = TITLE_DEF, const int year = YEAR_DEF,
        const std::string country = COUNTRY_DEF, const std::string averageDuration = AVERAGE_DURATION_DEF, const float rank = RANK_DEF,
        const int seasons = SEASONS_DEF, const std::vector<int> episodes = EPISODES_DEF, const bool ended = ENDED_DEF,
        const bool isWatched = WATCHED_DEF, const int lastWatchedSeason = L_WATCHED_SEASON_DEF,
        const int lastWatchedEpisode = L_WATCHED_EPISODE_DEF);
    //Series();
    Series(const Series& other);
    ~Series();
    
    int getSeasons() const;
    std::vector<int> getEpisodes() const;
    bool getEnded() const;
    int getLastWatchedSeason() const;
    int getLastWatchedEpisode() const;
    
    void setSeasons(const int& seasons);
    void setEpisodes(const std::vector<int>& episodes);
    void setEnded(const bool& b);
    void setLastWatchedSeason(const int& lSeason);
    void setLastWatchedEpisode(const int& lEpisode);

    VideoType getType() const override;

    void printParams() const override;
    void clearEpisodes();
};

