#include "Movies.h"

void Movies::add_movie(std::string name, std::string rating, int watched)
{
  for (const Movie &m : this->movies)
  {
    if (m.get_name() == name)
    {
      std::cout << name << " already exists" << std::endl;
      return;
    }
  }

  Movie m {name, rating, watched};
  (this->movies).push_back(m);
  std::cout << name << " added" << std::endl;
}

void Movies::increment_watched(std::string name)
{
  for (Movie &m : this->movies)
  {
    if (m.get_name() == name)
    {
      m.increment_watched();
      return;
    }
  }

  std::cout << name << " not found" << std::endl;
}

void Movies::display() const
{
  if (this->movies.size() == 0)
  {
    std::cout << "Sorry! No movies to display" << std::endl;
    return;
  }

  for (const Movie &m : this->movies)
    m.display();
  std::cout << std::endl;
}