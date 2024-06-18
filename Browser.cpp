#include "Browser.h"

Browser::Browser() : currentIndex(-1) {
    favorites = DataHandler::loadFavorites();
}

void Browser::navigateTo(std::string url) {
    if (currentIndex < static_cast<int>(history.size()) - 1) {
        history.resize(currentIndex + 1);
    }
    history.push_back(url);
    currentIndex++;
    std::cout << "Haz navegado en: " << url << std::endl;
}

void Browser::navigateToFavorite(std::string folder, std::string url) {
    if (favorites.find(folder) != favorites.end()) {
        for (const auto& fav : favorites[folder]) {
            if (fav.first == url) {
                navigateTo(url);
                break;
            }
        }
    }
}

void Browser::navigateForward() {
    if (currentIndex < static_cast<int>(history.size()) - 1) {
        currentIndex++;
        std::cout << "Haz navegado en: " << history[currentIndex] << std::endl;
    } else {
        std::cout << "No hay más páginas hacia adelante." << std::endl;
    }
}

void Browser::navigateBackward() {
    if (currentIndex > 0) {
        currentIndex--;
        std::cout << "Haz navegado en: " << history[currentIndex] << std::endl;
    } else {
        std::cout << "No hay más páginas hacia atrás." << std::endl;
    }
}

void Browser::addFavorite(std::string folder, std::string url, std::string name) {
    if (favorites.find(folder) == favorites.end()) {
        favorites[folder] = {};
    }
    auto& favs = favorites[folder];
    if (std::none_of(favs.begin(), favs.end(), [&](const std::pair<std::string, std::string>& fav) { return fav.first == url || fav.second == name; })) {
        favs.emplace_back(url, name);
    }
}

void Browser::removeFavorite(std::string folder, std::string identifier) {
    if (favorites.find(folder) != favorites.end()) {
        auto& favs = favorites[folder];
        auto it = std::remove_if(favs.begin(), favs.end(), [&](const std::pair<std::string, std::string>& fav) { return fav.first == identifier || fav.second == identifier; });
        if (it != favs.end()) {
            removedFavorites.push_back(*it);
            if (removedFavorites.size() > 5) {
                removedFavorites.erase(removedFavorites.begin());
            }
            favs.erase(it);
        }
    }
}

void Browser::restoreFavorites() {
    for (const auto& fav : removedFavorites) {
        addFavorite("Restored", fav.first, fav.second);
    }
    removedFavorites.clear();
}

void Browser::organizeFavorites(std::string folder) {
    // Functionality for organizing favorites into folders
    // Placeholder for the actual implementation
}

void Browser::exportToHTML() {
    std::ofstream outFile("favorites.html");
    outFile << "<html><body><h1>Favorites</h1>";
    for (const auto& folder : favorites) {
        outFile << "<h2>" << folder.first << "</h2><ul>";
        for (const auto& fav : folder.second) {
            outFile << "<li><a href=\"" << fav.first << "\">" << fav.second << "</a></li>";
        }
        outFile << "</ul>";
    }
    outFile << "</body></html>";
}

void Browser::saveData() {
    DataHandler::saveFavorites(favorites);
}

void Browser::showHistory() {
    for (int i = 0; i <= currentIndex; ++i) {
        std::cout << history[i] << std::endl;
    }
}

void Browser::showFavorites() {
    for (const auto& folder : favorites) {
        std::cout << folder.first << ":" << std::endl;
        for (const auto& fav : folder.second) {
            std::cout << "  " << fav.first << " - " << fav.second << std::endl;
        }
    }
}
