//
// Created by Victoria Jackson on 9/30/2025.
//

#ifndef PLAYLIST_PLAYLIST_H
#define PLAYLIST_PLAYLIST_H
#include <string>

#include "Song.h"

using std::string;

class Playlist {
    public:
        Playlist();
        ~Playlist();

        void enqueue(string title, string artist, int duration);
        void removeSong(string title);
        void removeSong(string title, string artist);
        void play();
        void shuffle();

        int getNumberOfSongs();
        int getTotalDuration();

        Song* dequeue();

    private:
        Song* head;
        Song* tail;
        int numSongs;
        int totalDuration;
};


#endif //PLAYLIST_PLAYLIST_H