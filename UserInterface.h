#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include "Browser.h"

class UserInterface {
public:
    void showMenu();
    void handleUserInput(Browser& browser);
};

#endif // USERINTERFACE_H
