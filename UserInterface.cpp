#include "UserInterface.h"

void UserInterface::showMenu() {
    std::cout << "1. Navegar a una pagina web" << std::endl;
    std::cout << "2. Navegar a una pagina web de favoritos" << std::endl;
    std::cout << "3. Navegar hacia adelante" << std::endl;
    std::cout << "4. Navegar hacia atras" << std::endl;
    std::cout << "5. Guardar en favoritos" << std::endl;
    std::cout << "6. Eliminar Favorito" << std::endl;
    std::cout << "7. Restaurar Favoritos" << std::endl;
    std::cout << "8. Organizar favoritos" << std::endl;
    std::cout << "9. Exportar a HTML" << std::endl;
    std::cout << "0. Salir" << std::endl;
}

void UserInterface::handleUserInput(Browser& browser) {
    int choice;
    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1: {
                std::string url;
                std::cout << "Ingrese la URL: ";
                std::getline(std::cin, url);
                browser.navigateTo(url);
                break;
            }
            case 2: {
                std::string folder, url;
                std::cout << "Ingrese la carpeta: ";
                std::getline(std::cin, folder);
                std::cout << "Ingrese la URL: ";
                std::getline(std::cin, url);
                browser.navigateToFavorite(folder, url);
                break;
            }
            case 3:
                browser.navigateForward();
                break;
            case 4:
                browser.navigateBackward();
                break;
            case 5: {
                std::string folder, url, name;
                std::cout << "Ingrese la carpeta: ";
                std::getline(std::cin, folder);
                std::cout << "Ingrese la URL: ";
                std::getline(std::cin, url);
                std::cout << "Ingrese el nombre: ";
                std::getline(std::cin, name);
                browser.addFavorite(folder, url, name);
                break;
            }
            case 6: {
                std::string folder, identifier;
                std::cout << "Ingrese la carpeta: ";
                std::getline(std::cin, folder);
                std::cout << "Ingrese el nombre o URL a eliminar: ";
                std::getline(std::cin, identifier);
                browser.removeFavorite(folder, identifier);
                break;
            }
            case 7:
                browser.restoreFavorites();
                break;
            case 8: {
                std::string folder;
                std::cout << "Ingrese la carpeta a organizar: ";
                std::getline(std::cin, folder);
                browser.organizeFavorites(folder);
                break;
            }
            case 9:
                browser.exportToHTML();
                break;
            case 0:
                browser.saveData();
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida" << std::endl;
        }
    } while (choice != 0);
}
