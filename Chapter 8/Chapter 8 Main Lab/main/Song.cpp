#include "Song.h"
#include <iostream>
#include <string>
using namespace std;

Song::Song() {
	songName = "null";
	firstLine = "null";
	timesPlayed = 0;
}

Song::Song(string newName, string newLine) {
	songName = newName;
	firstLine = newLine;
	timesPlayed = 0;
}

void Song::PlaySong() {
	cout << firstLine << endl;
	timesPlayed += 1;
}

string Song::SongName() {
	return songName;
}

void Song::PrintSong() {
	cout << songName << ": \"" << firstLine << "\", " << timesPlayed << " play(s)." << endl;
}