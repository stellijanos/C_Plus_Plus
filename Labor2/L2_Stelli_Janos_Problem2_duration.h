//
// Created by stell on 2023. 03. 24..
//

#ifndef SEMESTRUL_2_DURATION_H
#define SEMESTRUL_2_DURATION_H

#endif //SEMESTRUL_2_DURATION_H

#include <iostream>
#include <string>
#include <cmath>

class Duration {
private:

    double value;
    std::string unit;

public:

    Duration(double value, std::string unit) {
        this->value = floor(value * 100) / 100;
        this->unit = std::move(unit);
    }

    [[nodiscard]] double get_value() const;

    [[nodiscard]] std::string get_unit() const;

    double add(const Duration &other);

    double subtract(const Duration &other);

    void scale(double number);

    void divide(double number);

    std::string text();

    int compare(const Duration &other);

    // Bonus Methods
    void convertTo(const Duration &secondTime);

    double operator+(const Duration &other);

    double operator-(const Duration &other);

    void operator*(double other);

    void operator/(double other);

};