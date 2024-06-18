#include "DataHandler.h"

void DataHandler::saveFavorites(const std::map<std::string, std::vector<std::pair<std::string, std::string>>>& folders) {
    std::ofstream outFile("favorites.txt");
    for (const auto& folder : folders) {
        outFile << folder.first << std::endl;
        for (const auto& fav : folder.second) {
            outFile << fav.first << " " << fav.second << std::endl;
        }
        outFile << "# #" << std::endl; // Marca el final de una carpeta de favoritos
    }
}

std::map<std::string, std::vector<std::pair<std::string, std::string>>> DataHandler::loadFavorites() {
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> folders;
    std::ifstream inFile("favorites.txt");
    std::string folderName, url, name;
    while (std::getline(inFile, folderName)) {
        std::vector<std::pair<std::string, std::string>> favorites;
        while (inFile >> url >> name) {
            if (url == "#" && name == "#") break;
            favorites.emplace_back(url, name);
        }
        inFile.ignore(); // Ignorar el salto de línea después del "# #"
        folders[folderName] = favorites;
    }
    return folders;
}
