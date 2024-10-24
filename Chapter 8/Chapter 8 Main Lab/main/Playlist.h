#pragma once
#include <vector>
#include <string>
#include "Song.h"

class Playlist {
public:
	Playlist();
	Playlist(std::string newPlaylistName);
	std::string PlaylistName();
	void AddSong(Song* newSong);
	void PlaySongs();
	void RemoveSong(int songIndex);
	void RemoveSongPointer(Song* songPointer);
private:
	std::string playlistName;
	std::vector<Song*> playlistSongs;
};

