#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <string>
#include <vector>
#include <map>
#include <fstream>

class DataHandler {
public:
    static void saveFavorites(const std::map<std::string, std::vector<std::pair<std::string, std::string>>>& folders);
    static std::map<std::string, std::vector<std::pair<std::string, std::string>>> loadFavorites();
};

#endif // DATAHANDLER_H
