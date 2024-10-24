#include <string>
#include "Playlist.h"
using namespace std;

Playlist::Playlist() {
	playlistName = "null";
}

Playlist::Playlist(string newPlaylistName) {
	playlistName = newPlaylistName;
}

string Playlist::PlaylistName() {
	return playlistName;
}

void Playlist::AddSong(Song* newSong) {
	playlistSongs.push_back(newSong);
}

void Playlist::PlaySongs() {
	for (int i = 0; i < playlistSongs.size(); i++) {
		playlistSongs.at(i)->PlaySong();
	}
}

void Playlist::RemoveSong(int songIndex) {
	playlistSongs.erase(playlistSongs.begin() + songIndex);
}

void Playlist::RemoveSongPointer(Song* songPointer) {
	for (int i = playlistSongs.size() - 1; i >= 0 ; i--) {
		if (playlistSongs.at(i) == songPointer) {
			playlistSongs.pop_back();
		}
	}
}