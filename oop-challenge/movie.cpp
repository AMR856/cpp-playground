#include "movie.h"

std::string Movie::getName() const {
  return this->name;
}

std::string Movie::getMovieRating() const {
  return this->movieRating;
}

void Movie::setWatchesCount(int watchesCount) {
  this->watchesCount  = watchesCount;
}

int Movie::getWatchCount() const {
  return this->watchesCount;
}

void Movie::displayMovie() const {
  std::cout <<
  this->getName() << " " <<
  this->getMovieRating() << " " <<
  this->getWatchCount() << std::endl;
}

Movie::Movie(Movie&& source)
    : name(std::move(source.name)),
      movieRating(std::move(source.movieRating)),
      watchesCount(source.watchesCount) {
}


Movie::Movie(std::string name, std::string rating, int watchsCount): name{name}
, movieRating{rating}, watchesCount {watchsCount} {
}

Movie::~Movie() {
  // std::cout << this->getName() + " has been deleted" << std::endl;
}