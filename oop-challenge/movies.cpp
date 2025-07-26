#include "movies.h"


std::vector<Movie> Movies::moviesCollection; 
bool Movies::addMovie(std::string name, std::string rating, int watched) {
  for (const auto &movie: moviesCollection){
    if (name == movie.getName()) 
      return false;
  }
  for (char& c : rating) {
    c = std::toupper(static_cast<unsigned char>(c));
  }
  if (std::find(allowedRatings.begin(), allowedRatings.end(), rating) != allowedRatings.end()) {
    moviesCollection.push_back(Movie{name, rating, watched});
    return true;
  } else return false;
}

bool Movies::incrementWatch(std::string name) {
  for (auto &movie: moviesCollection){
    if (name == movie.getName()) {
      movie.setWatchesCount(movie.getWatchCount() + 1);
      return true;
    }
  }
  return false;
}

void Movies::displayMovies() const{
  if (moviesCollection.empty()){
    std::cout << "No movies to display" << std::endl;
    return;
  }
  std::cout << "#####################" << std::endl;
  for (auto movie: moviesCollection)
    movie.displayMovie();
  std::cout << "#####################" << std::endl;
}
