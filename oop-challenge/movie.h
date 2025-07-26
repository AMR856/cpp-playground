#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


class Movie {
  private:
    std::string name = "Unknown";
    std::string movieRating = "Unrated";
    int watchesCount  = 0;
  public:
    std:: string getName() const;
    std:: string getMovieRating() const;
    void setWatchesCount(int);
    int getWatchCount() const;
    void displayMovie() const;
    Movie(Movie &&source);
    Movie(const Movie &) = default; 
    Movie(std::string, std::string, int);
    ~Movie();
};

#endif