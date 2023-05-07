#include "UI.h"

FruitUI::FruitUI(FruitController &fruitController) : ctrl(fruitController) {
    this->ctrl = fruitController;
}

void FruitUI::uIScreen() {
    std::cout << "Here are the options:\n\n"
                 "\t1. Load initial data (Fruits)\n"
                 "\t2. Insert/Update a product\n"
                 "\t3. Delete a product\n"
                 "\t4. Search products by name\n"
                 "\t5. Search products by quantity\n"
                 "\t6. List products by expire date\n\n"
                 "Please choose an option (enter a number between 1 and 6; 0 for exit):";
}

void FruitUI::runUI() {
    std::cout << "\n@author: Stelli Janos\n\n"
                 "Welcome to Janos' Fruit Shop handler Menu\n";
    while (true) {
        uIScreen();
        std::string input;
        std::getline(std::cin, input);
        if (input == "0") {
            break;
        } else if (input == "1") {
            std::cout << "You chose option 1. Load initial data (Fruits)\n";
            ctrl.loadDataFromFile();
            std::cout << "\nDone.\n\n";
            system("pause");
        } else if (input == "2") {
            std::cout << "You chose option 2. Insert/Update a product\n";
            ctrl.insertProduct();
            std::cout << "\nDone.\n\n";
            system("pause");
        } else if (input == "3") {
            std::cout << "You chose option 3. Delete a product\n";
            ctrl.deleteProduct();
            std::cout << "\nDone.\n\n";
            system("pause");
        } else if (input == "4") {
            std::cout << "You chose option 4. Search products by name\n";
            ctrl.searchProductByName();
            std::cout << "\nDone.\n\n";
            system("pause");
        } else if (input == "5") {
            std::cout << "You chose option 5. Search products by quantity\n";
            ctrl.searchProductByQuantity();
            std::cout << "\nDone.\n\n";
            system("pause");
        } else if (input == "6") {
            std::cout << "You chose option 6. List products by expire date\n";
            ctrl.listProductsByExpireDate();
            std::cout << "\nDone.\n\n";
            system("pause");
        } else {
            std::cout << "Please try again!\n\n";
        }
    }
}

