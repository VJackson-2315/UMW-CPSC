//
// Created by Victoria Jackson on 9/30/2025.
//

#include "Song.h"

/**
 * Creates an empty Song
 */
Song::Song() {
    title = " ";
    artist = " ";
    duration = 0;
    next = nullptr;
    prev = nullptr;
}

/**
 * Creates a new Song
 * @param inTitle
 * @param inArtist
 * @param inDuration
 */
Song::Song(string inTitle, string inArtist, int inDuration) {
    title = inTitle;
    artist = inArtist;
    duration = inDuration;
    next = nullptr;
    prev = nullptr;
}

/**
 *
 * @return Song's title
 */
string Song::getTitle() {
    return title;
}

/**
 *
 * @return Song's artist
 */
string Song::getArtist() {
    return artist;
}

/**
 *
 * @return Duration of the Song
 */
int Song::getDuration() {
    return duration;
}

/**
 *
 * @return Pointer for the next Song
 */
Song* Song::getNext() {
    return next;
}

/**
 *
 * @return Pointer for the previous Song
 */
Song* Song::getPrev() {
    return prev;
}

/**
 * Sets the next Song
 * @param next
 */
void Song::setNext(Song *next) {
    this->next = next;
}

/**
 * Sets the previous Song
 * @param prev
 */
void Song::setPrev(Song *prev) {
    this->prev = prev;
}
