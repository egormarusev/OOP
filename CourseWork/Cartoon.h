#pragma once
#include "Video.h"
class Cartoon :
    public Video
{
private:
    bool isForChild;
public:
    Cartoon(const std::string title = TITLE_DEF, const int year = YEAR_DEF,
        const std::string country = COUNTRY_DEF, const std::string duration = DURATION_DEF, const float rank = RANK_DEF, const bool watched = WATCHED_DEF,
        const bool isForChild = FOR_CHILD_DEF);
    Cartoon(const Cartoon& other);
    ~Cartoon();

    bool getForChild() const;
    void setForChild(const bool& b);

    VideoType getType() const override;
    void printParams() const override;
};

