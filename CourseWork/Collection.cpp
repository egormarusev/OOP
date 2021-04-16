#include "Collection.h"
#include <iostream>
#include <fstream>
#include "utils.h"

Collection::Collection() {
	this->count = 0;
	this->videos.reserve(count);
}

Collection::Collection(const int& count) {
	this->count = count;
	this->videos.reserve(count);
}

Collection::Collection(const Collection& other) {
	this->count = other.getCount();
	this->videos = other.videos;
}

Collection::~Collection() {
	this->videos.clear();
	this->videos.shrink_to_fit();
}

void Collection::addVideo(Video* video) {
	if (video->getType() == movie)
	{
		this->videos.push_back(new Movie(*dynamic_cast<Movie*>(video)));
	}
	else {
			if (video->getType() == series)
			{
				this->videos.push_back(new Series(*dynamic_cast<Series*>(video)));
			}
			else {
				this->videos.push_back(new Cartoon(*dynamic_cast<Cartoon*>(video)));
				}
	}
	this->count = this->videos.size();
}

void Collection::delVideo(const int index) {
	//delete this->videos[index];
	videos.erase(videos.begin() + index);
	//videos.resize(index - 1);
	this->count = this->videos.size();
}

void Collection::clear() {
	this->videos.clear();
	this->count = 0;
}

std::vector<Video*> Collection::getVideos() {
	return this->videos;
}

Video* Collection::getVideo(const int index) const{
    if(index < videos.size() && index >= 0){
        return this->videos[index];
    }
    return nullptr;
}

Video* Collection::searchVideo(const std::string& title) {
	for (int i = 0; i < videos.size(); i++) {
		if (videos[i]->getTitle() == title)
			return videos[i];
	}
	return nullptr;
}

int Collection::getCount() const {
	return count;
}

void Collection::fGetData(const std::string& filename){
	std::ifstream file(filename);
	if (file.is_open())
	{
		while (!file.eof()) {
			std::string type;
			std::getline(file, type);
			if (type == "Movie")
			{
				std::string buffer;
				Movie* temp = new Movie;

				std::getline(file, buffer);
				temp->setTitle(buffer);

				std::getline(file, buffer);
				int i_buff = std::stoi(buffer);
				temp->setYear(i_buff);

				std::getline(file, buffer);
				temp->setGenre(buffer);

				std::getline(file, buffer);
				temp->setCountry(buffer);

				std::getline(file, buffer);
				temp->setDuration(buffer);

				std::getline(file, buffer);
				float f_buff = std::stof(buffer);
				temp->setRank(f_buff);

				std::getline(file, buffer);
				if (buffer == "true")
				{
					temp->setWatched(true);
				}
				if( buffer == "false")
				{
					temp->setWatched(false);
				}
				this->addVideo(temp);
			}
			else
			{
				if (type == "Series")
				{
					std::string buffer;
					Series* temp = new Series;

					std::getline(file, buffer);
					temp->setTitle(buffer);

					std::getline(file, buffer);
					int i_buff = std::stoi(buffer);
					temp->setYear(i_buff);

					std::getline(file, buffer);
					temp->setCountry(buffer);

					std::getline(file, buffer);
					temp->setDuration(buffer);

					std::getline(file, buffer);
					float f_buff = std::stof(buffer);
					temp->setRank(f_buff);

					std::getline(file, buffer);
					i_buff = std::stoi(buffer);
					temp->setSeasons(i_buff);

					std::getline(file, buffer);
					std::vector<int> episodes = utils::parseFileEpisodes(buffer, temp->getSeasons());
					temp->clearEpisodes();
                    temp->setEpisodes(episodes);

					std::getline(file, buffer);
					if (buffer == "true")
					{
                        temp->setWatched(true);
					}
					else
					{
						if (buffer == "false")
						{
                            temp->setWatched(false);
						}
					}

					std::getline(file, buffer);
					if (buffer == "true")
					{
                        temp->setEnded(true);
					}
					else
					{
						if (buffer == "false")
						{
                            temp->setEnded(false);
						}
					}

					std::getline(file, buffer);
					i_buff = std::stoi(buffer);
					temp->setLastWatchedSeason(i_buff);

					std::getline(file, buffer);
					i_buff = std::stoi(buffer);
					temp->setLastWatchedEpisode(i_buff);

					this->addVideo(temp);
				}
				if (type == "Cartoon")
				{
					std::string buffer;
					Cartoon* temp = new Cartoon;

					std::getline(file, buffer);
					temp->setTitle(buffer);

					std::getline(file, buffer);
					int i_buff = std::stoi(buffer);
					temp->setYear(i_buff);

					std::getline(file, buffer);
					temp->setCountry(buffer);

					std::getline(file, buffer);
					temp->setDuration(buffer);

					std::getline(file, buffer);
					float f_buff = std::stof(buffer);
					temp->setRank(f_buff);

					std::getline(file, buffer);
					if (buffer == "true")
					{
						temp->setWatched(true);
					}
					if (buffer == "false")
					{
						temp->setWatched(false);
					}

					std::getline(file, buffer);
					if (buffer == "true")
					{
						temp->setForChild(true);
					}
					if (buffer == "false")
					{
						temp->setForChild(false);
					}

					this->addVideo(temp);
				}
			}
		}
		file.close();
	}
}

void Collection::fPrintData(const std::string& filename) const {

	std::ofstream file;
	file.open(filename);
	for (int i = 0; i < videos.size(); ++i)
	{
		if (videos[i]->getType() == series)
		{
			file << "Series\n";
			file << videos[i]->getTitle() << std::endl;
			file << videos[i]->getYear() << std::endl;
			file << videos[i]->getCountry() << std::endl;
			file << videos[i]->getDuration() << std::endl;
			file << videos[i]->getRank() << std::endl;
			int seasons = dynamic_cast<Series*>(videos[i])->getSeasons();
			file << seasons << std::endl;
			//file << dynamic_cast<Series*>(videos[i])->getEpisodes() << std::endl;
			std::vector<int> episodes = dynamic_cast<Series*>(videos[i])->getEpisodes();
			for (int i = 0; i < episodes.size(); i++)
			{
				file << episodes[i] << " ";
			}
			file << std::endl;
            file << videos[i]->getWatched() << std::endl;
			file << dynamic_cast<Series*>(videos[i])->getEnded() << std::endl;
			file << dynamic_cast<Series*>(videos[i])->getLastWatchedSeason() << std::endl;
			file << dynamic_cast<Series*>(videos[i])->getLastWatchedEpisode() << std::endl;

		}
		else if (videos[i]->getType() == movie)
		{
			file << "Movie\n";
			file << videos[i]->getTitle() << std::endl;
			file << videos[i]->getYear() << std::endl;
			file << dynamic_cast<Movie*>(videos[i])->getGenre() << std::endl;
			file << videos[i]->getCountry() << std::endl;
			file << videos[i]->getDuration() << std::endl;
			file << videos[i]->getRank() << std::endl;
			file << videos[i]->getWatched() << std::endl;
			
		}
		else if (videos[i]->getType() == cartoon) {
			file << "Cartoon\n";
			file << videos[i]->getTitle() << std::endl;
			file << videos[i]->getYear() << std::endl;
			file << videos[i]->getCountry() << std::endl;
			file << videos[i]->getDuration() << std::endl;
			file << videos[i]->getRank() << std::endl;
			file << videos[i]->getWatched() << std::endl;
			file << dynamic_cast<Cartoon*>(videos[i])->getForChild() << std::endl;

		}
	}
	file.close();
}
