#pragma once
#include <string>

class Song {
public:
	Song();
	Song(std::string newName, std::string newLine);
	void PlaySong();
	void PrintSong();
	std::string SongName();
private:
	std::string songName;
	std::string firstLine;
	int timesPlayed;
};

