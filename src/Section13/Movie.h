#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
  private:
    std::string name;
    std::string rating; // G, PG, PG-13, R
    int watched;
  public:
    // Constructors / Destructor
    Movie(std::string name, std::string rating, int watched);
    Movie(const Movie &m);
    Movie(Movie &&m);
    ~Movie();

    // Setters
    void set_name(std::string name);
    void set_rating(std::string rating);
    void set_watched(int watched);

    // Getters
    std::string get_name() const;
    std::string get_rating() const;
    int get_watched() const;

    // General
    void increment_watched();
    void display() const;
};

#endif
