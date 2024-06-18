#ifndef BROWSER_H
#define BROWSER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> // Incluir para usar std::none_of y std::remove_if
#include "DataHandler.h"

class Browser {
private:
    std::vector<std::string> history;
    int currentIndex;
    std::vector<std::pair<std::string, std::string>> removedFavorites;
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> favorites;

public:
    Browser();
    void navigateTo(std::string url);
    void navigateToFavorite(std::string folder, std::string url);
    void navigateForward();
    void navigateBackward();
    void addFavorite(std::string folder, std::string url, std::string name);
    void removeFavorite(std::string folder, std::string identifier);
    void restoreFavorites();
    void organizeFavorites(std::string folder);
    void exportToHTML();
    void saveData();
    void showHistory();
    void showFavorites();
};

#endif // BROWSER_H
