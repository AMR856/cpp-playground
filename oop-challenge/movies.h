#ifndef _MOVIES_H
#define _MOVIES_H


#include "./movie.h"


class Movies {
  private:
    inline static const std::vector<std::string> allowedRatings = {"G", "PG", "PG-13", "R"};
    static std::vector<Movie> moviesCollection;
  public:
    bool addMovie(std::string, std::string, int);
    bool incrementWatch(std:: string);
    void displayMovies() const;
};

#endif