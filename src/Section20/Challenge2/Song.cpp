#include <iostream>
#include <string>
#include <iomanip>
#include "Song.h"

/*****************************************************************************/
// Constructors / Destructor
/*****************************************************************************/
Song::Song(std::string name, std::string artist, int rating)
    : name{name}, artist{artist}, rating{rating} {}

/*****************************************************************************/
// Getters
/*****************************************************************************/
std::string Song::get_name() const
{
  return this->name;
}

std::string Song::get_artist() const
{
  return this->artist;
}

int Song::get_rating() const
{
  return this->rating;
}

/*****************************************************************************/
// Operations
/*****************************************************************************/
bool Song::operator<(const Song &s) const
{
  return this->get_name() < s.get_name();
}

bool Song::operator==(const Song &s) const
{
  return this->get_name() == s.get_name() && this->get_artist() == s.get_artist();
}

/*****************************************************************************/
// Friends
/*****************************************************************************/
std::ostream &operator<<(std::ostream &os, const Song &s)
{
  os << std::setw(30) << std::left << s.get_name()
     << std::setw(20) << std::left << s.get_artist()
     << std::setw(1) << std::right << s.get_rating();

  return os;
}