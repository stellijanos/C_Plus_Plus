#include "Repository.h"
#include <algorithm>
#include <utility>

void FruitRepo::add(const Fruit &fruit) {
    this->fruitsArray.push_back(fruit);
}


void FruitRepo::remove(const Fruit &fruit) {
    fruitsArray.erase(std::remove_if(
                    fruitsArray.begin(),fruitsArray.end(),
                    [&](Fruit &f) {return f.compare(fruit.get_name(), fruit.get_type());
                              }),fruitsArray.end());
}


void FruitRepo::update(int &index_, double &quantity_) {
    fruitsArray[index_].set_quantity(quantity_);
}

std::vector<Fruit> FruitRepo::get_all() {
    return this->fruitsArray;
}

FruitRepo::FruitRepo(std::vector<Fruit> fruitArray_) {
    this->fruitsArray = std::move(fruitArray_);
}



