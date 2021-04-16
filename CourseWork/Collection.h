#pragma once
#include "Video.h"
#include "Movie.h"
#include "Series.h"
#include "Cartoon.h"

class Collection
{
public:
	Collection();
	Collection(const Collection& other);
	Collection(const int& count);
	~Collection();

	void addVideo(Video* video);
	void delVideo(const int index);
	void clear();

	std::vector<Video*> getVideos();
	Video* getVideo(const int index) const;
	Video* searchVideo(const std::string& title);
	int getCount() const;

	void fGetData(const std::string& filename);
	void fPrintData(const std::string& filename) const;

private:
	std::vector<Video*> videos;
	int count;
};

