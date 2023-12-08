/*
Section 20 Challenge
====================

Challenge 2

Using std::list

In this challenge you will create a menu driven application that
will simulate a user playing songs from a playlist of songs.

We will use a list to simulate the user selecting the the first song in the playlist and
then selecting next and previous to play forward of backwards through the
playlist.

Please refer to the video demo run.

We will also allow users to add new song to the playlist and they
will be added prior to the currently playing song.
The menu looks as follows:

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
========================
Enter a selection (Q to quit):

And the available playlist is modeled as a std::list<Song>
I will provide the Song class. Following are the songs in the playlist.
I grabbed these from the pop charts, you can use them or change
them to any songs you wish.

The Heart of the Unicorn    Gamma Ray     5
Power of the Night          Savatage      5
I Rule the Ruins            Warlock       4
Watching Over Me            Iced Earth    5
Hunter's Moon               Ghost         4
Dying Breed                 Accept        4

I have provided the starting project.
Have fun!

Note:
If you have trouble reading input, you can clear std::cin and
ignore everything in the buffer with:

std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

Make sure you #include <limits> to use it.
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <list>
#include <limits>

#include "Song.h"

void play_current_song(const Song &s);
void handle_display_menu();
void handle_first_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song);
void handle_next_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song);
void handle_previous_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song);
void handle_display_playlist(const std::list<Song> &playlist, const Song &current_song);
void handle_add_new_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song);
void handle_quit();
void handle_invalid_option();

int main()
{
  std::list<Song> playlist{
      {"The Heart of the Unicorn", "Gamma Ray", 5},
      {"Power of the Night", "Savatage", 5},
      {"I Rule the Ruins", "Warlock", 4},
      {"Watching Over Me", "Iced Earth", 5},
      {"Hunter's Moon", "Ghost", 4},
      {"Dying Breed", "Accept", 4}};

  std::list<Song>::iterator current_song = playlist.begin();
  handle_display_playlist(playlist, *current_song);
  std::cout << std::endl;

  char option{};
  do
  {
    handle_display_menu();

    std::cin >> option;
    option = std::toupper(option);

    switch (option)
    {
    case 'F':
      handle_first_song(playlist, current_song);
      break;
    case 'N':
      handle_next_song(playlist, current_song);
      break;
    case 'P':
      handle_previous_song(playlist, current_song);
      break;
    case 'A':
      handle_add_new_song(playlist, current_song);
      break;
    case 'L':
      handle_display_playlist(playlist, *current_song);
      break;
    case 'Q':
      handle_quit();
      break;
    default:
      handle_invalid_option();
      break;
    }

    std::cout << std::endl;
  } while (option != 'Q');
}

void handle_display_menu()
{
  std::cout << "F - Play First Song" << std::endl;
  std::cout << "N - Play Next Song" << std::endl;
  std::cout << "P - Play Previous Song" << std::endl;
  std::cout << "A - Add and Play a New Song" << std::endl;
  std::cout << "L - List the Current Playlist" << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Enter a Selection (Q to quit)" << std::endl;
}

void play_current_song(const Song &s)
{
  std::cout << "Now Playing:" << std::endl;
  std::cout << s << std::endl;
}

void handle_first_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
  current_song = playlist.begin();
  play_current_song(*current_song);
}

void handle_next_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
  current_song++;

  if (current_song == playlist.end())
  {
    current_song = playlist.begin();
  }

  play_current_song(*current_song);
}

void handle_previous_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
  if (current_song == playlist.begin())
  {
    current_song = playlist.end();
  }

  current_song--;
  play_current_song(*current_song);
}

void handle_display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
  for (const Song &s : playlist)
  {
    std::cout << s << std::endl;
  }

  std::cout << std::endl;
  play_current_song(current_song);
}

void handle_add_new_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Adding and playing new song" << std::endl;

  std::cout << "Enter the song name: ";
  std::string song_name{};
  std::getline(std::cin, song_name);

  std::cout << "Enter the song artist: ";
  std::string song_artist{};
  std::getline(std::cin, song_artist);

  std::cout << "Enter your rating (1-5): ";
  int song_rating{};
  std::cin >> song_rating;

  playlist.emplace(current_song, song_name, song_artist, song_rating);
  handle_previous_song(playlist, current_song);
}

void handle_quit()
{
  std::cout << "Thanks for listening!" << std::endl;
}

void handle_invalid_option()
{
  std::cout << "Invalid option!" << std::endl;
}