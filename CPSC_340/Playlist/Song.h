//
// Created by Victoria Jackson on 9/30/2025.
//

#ifndef PLAYLIST_SONG_H
#define PLAYLIST_SONG_H
#include <string>

using std::string;

class Song {
    public:
        Song();
        Song(string title, string artist, int duration);
        // ~Song();

        string getTitle();
        string getArtist();
        int getDuration();

        Song* getNext();
        Song* getPrev();

        void setNext(Song* next);
        void setPrev(Song* prev);

    private:
        Song* prev;
        Song* next;
        string title;
        string artist;
        int duration;
        string displayedDuration;
};


#endif //PLAYLIST_SONG_H