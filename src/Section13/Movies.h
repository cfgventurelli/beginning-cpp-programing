#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <iostream>
#include <vector>
#include <string>
#include "Movie.h"

class Movies
{
  private:
    std::vector<Movie> movies;
  public:
    // General
    void add_movie(std::string name, std::string rating, int watched);
    void increment_watched(std::string name);
    void display() const;
};

#endif
