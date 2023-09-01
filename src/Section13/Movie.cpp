#include <iostream>
#include "Movie.h"

// Constructors / Destructor
Movie::Movie(std::string name, std::string rating, int watched)
  : name {name}, rating {rating}, watched {watched}
{
}

Movie::Movie(const Movie &m)
  : Movie {m.name, m.rating, m.watched}
{
}

Movie::Movie(Movie &&m)
  : Movie (m)
{
}

Movie::~Movie()
{
}

// Setters
void Movie::set_name(std::string name)
{
  this->name = name;
}

void Movie::set_rating(std::string rating)
{
  this->rating = rating;
}

void Movie::set_watched(int watched)
{
  this->watched = watched;
}

// Getters
std::string Movie::get_name() const
{
  return this->name;
}

std::string Movie::get_rating() const
{
  return this->rating;
}

int Movie::get_watched() const
{
  return this->watched;
}

// General
void Movie::increment_watched()
{
  ++(this->watched);
}

void Movie::display() const
{
  std::cout << this->get_name() << " " << this->get_rating() << " " << this->get_watched() << std::endl;
}
