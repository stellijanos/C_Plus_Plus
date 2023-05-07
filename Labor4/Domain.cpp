#include "Domain.h"
#include <utility>

using namespace Domain;

Fruit::Fruit(std::string &name_, std::string &origin_, std::string &expireDate_, double &quantity_, int &price_) {
    name = std::move(name_);
    origin = std::move(origin_);
    expireDate = std::move(expireDate_);
    quantity = quantity_;
    price = price_;
}

std::string Fruit::get_name() const {
    return name;
}

std::string Fruit::get_type() const {
    return origin;
}

std::string Fruit::get_expire_date() const {
    return this->expireDate;
}


double Fruit::get_quantity() const {
    return this->quantity;
}

void Fruit::set_quantity(double &quantity_) {
    this->quantity += quantity_;
}

int Fruit::get_price() const {
    return price;
}

void Fruit::set_price(int newPrice) {
    this->price = newPrice;
}


bool Fruit::compare(const std::string &name_, const std::string &origin_) const {
    return this->name == name_ && this->origin == origin_;
}

