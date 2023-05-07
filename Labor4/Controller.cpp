#include "Controller.h"
#include <iostream>
#include <iomanip>
#include <cassert>

FruitController::FruitController(FruitRepo &fruitRepo) {
    this->repo = fruitRepo;
}

//Creating a new Fruit Object with the parameters as attributes and then calls the repository's add method then printing
// out the added
void
FruitController::add(std::string &name_, std::string &origin_, std::string &expireDate_, double &quantity_,
                     int &price_) {
    std::string name = name_;
    std::string origin = origin_;
    std::string expireDate = expireDate_;
    double quantity = quantity_;
    int price = price_;
    Fruit fruit = Fruit(name_, origin_, expireDate_, quantity_, price_);
    repo.add(fruit);
    assert(fruit.get_name() == name);
    assert(fruit.get_type() == origin);
    assert(fruit.get_expire_date() == expireDate);
    assert(fruit.get_quantity() == quantity);
    assert(fruit.get_price() == price);
    std::cout << std::left << std::setw(15) << fruit.get_name() << std::setw(15) << fruit.get_type() << std::setw(15)
              << fruit.get_expire_date() << std::setw(10) << fruit.get_quantity() << std::setw(7) << fruit.get_price()
              << std::endl;
}

void FruitController::remove(const Fruit &fruit) {
    repo.remove(fruit);
}

void
FruitController::update(int &index_, double &quantity_) {
    repo.update(index_, quantity_);
}


std::vector<Fruit> FruitController::find(std::string &type) {
    std::vector<Fruit> result;
    for (const auto &fruit: repo.get_all()) {
        if (fruit.get_name().find(type) != std::string::npos || fruit.get_type().find(type) != std::string::npos) {
            result.push_back(fruit);
        }
    }
    std::sort(result.begin(), result.end(),
              [](const Fruit &a, const Fruit &b) { return a.get_name() < b.get_name(); });
    return result;
}


// load the fruits from a file  then verity if already exists or not,
//if exists then the quantity will be updated
// if not, then will be added as a new Fruit
void FruitController::loadDataFromFile() {
    std::string fileName = "data.txt";
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string name;
        std::string origin;
        std::string expireDate;
        double quantity;
        int price;
        std::cout << std::left << std::setw(15) << "Name" << std::setw(15) << "Origin" << std::setw(15) << "Expire Date"
                  << std::setw(10) << "Quantity" << std::setw(7) << "Price" << std::endl;

        while (file >> name >> origin >> expireDate >> quantity >> price) {
            int index = 0;
            for (auto &fruit: repo.get_all()) {
                if (fruit.compare(name, origin)) {
                    update(index, quantity);
                    return;
                }
                index++;
            }
            add(name, origin, expireDate, quantity, price);
        }
        assert(repo.get_all().size() == 10);
    } else {
        std::cout << "Failed to open the file.";
    }
    file.close();
}

//if exists then the quantity will be updated
// if not, then will be added as a new Fruit
void FruitController::insertProduct() {
    std::string name_, origin_, expireDate_;
    double quantity_;
    int price_;
    std::cout << "Please enter the following informations to add a fruit\n";
    std::cout << "Name: ";
    std::cin >> name_;
    std::cout << "Origin: ";
    std::cin >> origin_;
    std::cout << "Expire Date (yyyy-mm-dd): ";
    std::cin >> expireDate_;
    std::cout << "Quantity: ";
    std::cin >> quantity_;
    std::cout << "Price: ";
    std::cin >> price_;
    std::replace(expireDate_.begin(), expireDate_.end(), ' ', '-');

    int index = 0;
    for (auto &fruit: repo.get_all()) {
        if (fruit.compare(name_, origin_)) {
            update(index, quantity_);
            return;
        }
        index++;
    }
    add(name_, origin_, expireDate_, quantity_, price_);
}

//deletes if the name and origin attributes match a Fruit, in toher case not
void FruitController::deleteProduct() {
    std::string name, origin;
    std::cout << "Enter the name of the fruit you want to delete: ";
    std::cin >> name;
    std::cout << "Enter the origin of the fruit you want to delete: ";
    std::cin >> origin;
    int length = repo.get_all().size();
    for (const auto &fruit: repo.get_all()) {
        if (fruit.compare(name, origin)) {
            remove(fruit);
            std::cout << "Successfully deleted the fruit " << name << "with origin " << origin << ".\n";
            assert(repo.get_all().size() == length - 1);
            return;
        }
    }
    assert(repo.get_all().size() == length);
    std::cout << "Sorry, the fruit was not found.\n";
}

// input: a string that
void FruitController::searchProductByName() {
    std::string query;
    std::cout << "Please enter what you are searching for: ";
    std::getline(std::cin, query, '\n');
    int counter = 0;

    std::vector<Fruit> infos = find(query);
    if (!infos.empty()) {
        std::cout << std::left << std::setw(15) << "Name" << std::setw(15) << "Origin" << std::setw(15) << "Expire Date"
                  << std::setw(10) << "Quantity" << std::setw(7) << "Price" << std::endl;
        for (const auto &fruit: infos) {

            std::cout << std::left << std::setw(15) << fruit.get_name() << std::setw(15) << fruit.get_type()
                      << std::setw(15) << fruit.get_expire_date() << std::setw(10) << fruit.get_quantity()
                      << std::setw(7) << fruit.get_price() << std::endl;
            counter++;
        }
    } else {
        listProducts();
        return;
    }
    if (counter == 0) {
        std::cout << "No products were found\n";
    }
}

// enter a quantity then list all the products with < quantity
void FruitController::searchProductByQuantity() {
    double query;
    std::cout << "Please enter what you are searching for: ";
    std::cin >> query;
    int counter = 0;

    std::cout << std::left << std::setw(15) << "Name" << std::setw(15) << "Origin" << std::setw(15) << "Expire Date"
              << std::setw(10) << "Quantity" << std::setw(7) << "Price" << std::endl;

    for (const auto &fruit: repo.get_all())
        if (fruit.get_quantity() < query) {
            std::cout << std::left << std::setw(15) << fruit.get_name() << std::setw(15) << fruit.get_type()
                      << std::setw(15) << fruit.get_expire_date() << std::setw(10) << fruit.get_quantity()
                      << std::setw(7) << fruit.get_price() << std::endl;
            counter++;
        }
    if (counter == 0) {
        std::cout << "No products were found\n";
    }
}


// lists all the products (ascending) by expire date
void FruitController::listProductsByExpireDate() {
    std::cout << std::setw(15) << "Name" << std::setw(15) << "Origin" << std::setw(12) << "Expire Date" << std::setw(7)
              << "Quantity" << std::setw(7) << "Price" << std::endl;

    // converting dates to integer numbers then sort them in function of that
    auto convertDate = [](std::string date) {
        std::string year_str = date.substr(0, 4);
        std::string month_str = date.substr(5, 2);
        std::string day_str = date.substr(8, 2);
        int year = std::stoi(year_str);
        int month = std::stoi(month_str);
        int day = std::stoi(day_str);
        return (year * 100 + month) * 100 + day;
    };

    auto fruits = repo.get_all();
    if (!fruits.empty()) {
        std::sort(fruits.begin(), fruits.end(), [convertDate](const Fruit &f1, const Fruit &f2) {
            return convertDate(f1.get_expire_date()) < convertDate(f2.get_expire_date());
        });
    }

    for (const auto &fruit: fruits) { // Use the sorted list of fruits instead of calling repo.get_all() again
        std::cout << std::setw(15) << fruit.get_name() << std::setw(15) << fruit.get_type() << std::setw(12)
                  << fruit.get_expire_date() << std::setw(7) << fruit.get_quantity() << std::setw(7)
                  << fruit.get_price() << std::endl;
    }
}

// lists all the products in the repository
void FruitController::listProducts() {
    std::cout << std::setw(15) << "Name" << std::setw(15) << "Origin" << std::setw(12) << "Expire Date" << std::setw(7)
              << "Quantity" << std::setw(7) << "Price" << std::endl;


    std::sort(repo.get_all().begin(), repo.get_all().end(),
              [](const Fruit &a, const Fruit &b) { return a.get_name() < b.get_name(); });

    for (const auto &fruit: repo.get_all()) { // Use the sorted list of fruits instead of calling repo.get_all() again
        std::cout << std::setw(15) << fruit.get_name() << std::setw(15) << fruit.get_type() << std::setw(12)
                  << fruit.get_expire_date() << std::setw(7) << fruit.get_quantity() << std::setw(7)
                  << fruit.get_price() << std::endl;
    }

}

