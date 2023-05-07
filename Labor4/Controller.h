#include "Repository.h"
#include <iostream>
#include <fstream>
#include <algorithm>

class FruitController {
private:
    FruitRepo repo;
public:

    explicit FruitController(FruitRepo &fruitRepo_);

    void add(std::string &name_, std::string &origin_, std::string &expireDate_, double &quantity_, int &price_);

    void remove(const Fruit &fruit);

    void update(int &index_, double &quantity_);

    std::vector<Fruit> find(std::string &type);

    void loadDataFromFile(); //option 1 completed

    void insertProduct(); //option 2

    void deleteProduct(); //option 3

    void searchProductByName();  //option 4

    void searchProductByQuantity(); //option 5

    void listProductsByExpireDate(); //opton 6

    void listProducts();

};