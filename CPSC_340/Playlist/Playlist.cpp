//
// Created by Victoria Jackson on 9/30/2025.
//
#include <string>
#include <iostream>
#include <cstdlib>
#include "Playlist.h"

#include <algorithm>
#include <math.h>

using std::cout, std::endl, std::string;

/**
 * Creates an empty Playlist
 */
Playlist::Playlist() {
    numSongs = 0;
    totalDuration = 0;
    head = new Song();
    tail = new Song();

    // When the playlist is created, it should already be empty, so they should point to each other
    // Also why I didn't have an if statement in enqueue
    head->setNext(tail);
    tail->setPrev(head);
}

/**
 * Deletes the Playlist
 */
Playlist::~Playlist() {
    Song* curr = head;
    while (curr != NULL) {
        Song* next = curr->getNext();
        delete curr;
        curr = next;
    }
    // cout << "Playlist destroyed" << endl;
}

/**
 * Adds a new song at the end of the Playlist
 * @param title
 * @param artist
 * @param duration
 */
void Playlist::enqueue(string title, string artist, int duration) {
    Song* newSong = new Song(title, artist, duration);

    tail->getPrev()->setNext(newSong);
    newSong->setPrev(tail->getPrev());
    newSong->setNext(tail);
    tail->setPrev(newSong);

    numSongs++;
    totalDuration += newSong->getDuration();
}

/**
 * Prints the Playlist out
 */
void Playlist::play() {
    cout << "Full Playlist (" << numSongs << " Songs):" << endl;
    Song* curr = head->getNext();
    for (int i = 0; i < numSongs; i++) {
        cout << i+1 << ". " << curr->getTitle() << " - " << curr->getArtist() << " (" << curr->getDuration() << ")\n";
        curr = curr->getNext();
    }
}

/**
 * Shuffles the playlist
 */
void Playlist::shuffle() {
    // cout << "Playlist shuffling" << endl;

    int array[numSongs]; // Creates a list that determines the order of indexes
    for (int i = 0; i < numSongs; i++) {
        array[i] = numSongs; // This is to make sure the elements before the rand don't match the random number generator
    }

    srand(time(0)); // Ensures that the playlist is truly random every time it is run
    int index = 0;

    /* I tried make it so that the randomness comes from a set of numbers, but I couldn't figure out how to do it,
       so I went with the while loop. While probably the least efficient way, it was understandable to me.
       I'll try to mess with this some more in my spare time to see if I can get it to work with a set
     */
    while (index < numSongs) {
        int r = rand() % numSongs;
        bool canEnter = true;
        for (int j = 0; j < numSongs; j++) { //Checks the array to see if the index is already in there
            if (array[j] == r) { // If the number already has appeared in the array, run the while loop again
                canEnter = false;
                break;
            }
        }
        if (canEnter == true) { //If the number isn't in the array, it can be added, and the index can increase
            array[index] = r;
            index++;
        }
    }
    // The while loop should output an array with a set order of numbers the songs will follow

    Song* curr = head;
    for (int i = 0; i < numSongs; i++) { // Connects all previous pointers
        Song* next = head->getNext();
        for (int j = 0; j < array[i]; j++) { // Stops when j is equal to the element in the array
            next = next->getNext();
        }
        next->setPrev(curr);
        curr = next;
    }
    tail->setPrev(curr);

    curr = tail;
    while (curr != head) { // Connects all next pointers
        curr->getPrev()->setNext(curr);
        curr = curr->getPrev();
    }
}

/**
 * Removes and returns the song at the end of the playlist
 * @return
 */
Song* Playlist::dequeue() {
    if (tail->getPrev() != head) {
        Song* curr = head->getNext();
        curr->getNext()->setPrev(head);
        head->setNext(curr->getNext());
        curr->setPrev(nullptr);
        curr->setNext(nullptr);

        numSongs--;
        totalDuration -= curr->getDuration();
        return curr;
    } else { // If the playlist is empty, It cannot dequeue the tail or head
        cout << "Playlist empty, cannot dequeue" << endl;
        return nullptr;
    }
}

/**
 * Removes a song based on the title
 * @param title
 */
void Playlist::removeSong(string title) {
    Song* curr = head->getNext();
    while ((curr->getTitle() != title) && (curr != tail)) { // Checks to see if the song exists
        curr = curr->getNext();
    }
    if (curr == tail) { // Song doesn't exist
        cout << title << " Not Found" << endl;
    } else {
        curr->getPrev()->setNext(curr->getNext());
        curr->getNext()->setPrev(curr->getPrev());
        curr->setPrev(nullptr);
        curr->setNext(nullptr);

        numSongs--;
        totalDuration -= curr->getDuration();
        delete curr;
    }
}

/**
 * Removes a song based on the title and the artist if there are multiple songs of the same name
 * @param title
 * @param artist
 */
void Playlist::removeSong(string title, string artist) {
    Song* curr = head->getNext();
    while ((curr->getTitle() != title) && (curr->getArtist() != artist) && (curr != tail)) {
        // Checks to see if the song exists
        curr = curr->getNext();
    }
    if (curr == tail) { // The song doesn't exist
        cout << title << " Not Found" << endl;
    } else {
        curr->getPrev()->setNext(curr->getNext());
        curr->getNext()->setPrev(curr->getPrev());
        curr->setPrev(nullptr);
        curr->setNext(nullptr);

        totalDuration -= curr->getDuration();
        delete curr;
        numSongs--;
    }
}

/**
 *
 * @return Number of songs in the Playlist
 */
int Playlist::getNumberOfSongs() {
    return numSongs;
}

/**
 *
 * @return Total duration of the playlist
 */
int Playlist::getTotalDuration() {
    return totalDuration;
}