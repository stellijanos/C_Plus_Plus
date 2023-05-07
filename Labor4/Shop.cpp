#include <iostream>
#include <fstream>
#include "UI.h"

using namespace std;


int main() {

    FruitRepo fruitsArray = FruitRepo();
    FruitController fruitController = FruitController(fruitsArray);
    FruitUI fruitUI = FruitUI(fruitController);
    fruitUI.runUI();

    std::cout << "Thank you for choosing Janos' Shop handler" << std::endl;

    return 0;
}
