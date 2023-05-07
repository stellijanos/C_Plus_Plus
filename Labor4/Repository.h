#include "Domain.h"
#include <vector>
#include <iostream>
#include <string>
using namespace Domain;

class FruitRepo {
    std::vector<Fruit> fruitsArray;
public:

    explicit FruitRepo(std::vector<Fruit> fruitArray_ = std::vector<Fruit>());

    void add(const Fruit &fruit);

    void remove(const Fruit &fruit);

    void update(int &index_, double &quantity_);

    std::vector<Fruit> get_all();


};