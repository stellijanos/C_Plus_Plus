
//
// Created by stell on 2023. 03. 24..
//

#include <iostream>
#include <map>
#include "L2_Stelli_Janos_Problem2_duration.h"

using namespace std;


double Duration::get_value() const {
    return value;
}

std::string Duration::get_unit() const {
    return unit;
}

double Duration::add(const Duration &other) {
    if (this->unit != other.unit) {
        convertTo(other);
    }
    return this->value + other.value;
}

double Duration::subtract(const Duration &other) {
    if (this->unit != other.unit) {
        convertTo(other);
    }
    return this->value - other.value;
}

void Duration::scale(double number) {
    this->value *= number;
}

void Duration::divide(double number) {
    this->value /= number;
}

std::string Duration::text() {
    const string &var = std::to_string(this->value);
    return "The time Duration is " +
           var.substr(0, var.find('.') + 3) +
           " in the unit of " + this->unit + ".\n";
}

int Duration::compare(const Duration &other) {
    if (this->unit != other.unit) {
        convertTo(other);
    }
    if (this->value < other.value)
        return -1;
    if (this->value > other.value)
        return 1;
    return 0;
}


// converts this value and unit to other.value and unit
void Duration::convertTo(const Duration &other) {
    std::map<std::string, double> conversionTable;
    conversionTable["sec"] = 1;
    conversionTable["min"] = 60;
    conversionTable["hour"] = 3600;
    conversionTable["day"] = 3600 * 24;
    conversionTable["week"] = 3600 * 24 * 7;

    double ratio = conversionTable[this->unit] / conversionTable[other.unit];
    this->value *= ratio;
    this->unit = other.unit;
}

double Duration::operator+(const Duration &other) {
    return this->add(other);
}

double Duration::operator-(const Duration &other) {
    return this->subtract(other);
}

void Duration::operator*(double other) {
    this->scale(other);
}

void Duration::operator/(double other) {
    this->divide(other);
}
