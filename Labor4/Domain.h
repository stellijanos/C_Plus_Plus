#pragma once

#include <string>

namespace Domain {

    class Fruit {
    private:
        std::string name;
        std::string origin;
        std::string expireDate;
        double quantity;
        int price;
    public:

        Fruit(std::string &name_, std::string &origin_, std::string &expireDate_, double &quantity_, int &price_);

        std::string get_name() const;

        std::string get_type() const;

        std::string get_expire_date() const;


        double get_quantity() const;

        void set_quantity(double &quantity_);

        int get_price() const;

        void set_price(int newPrice);


        bool compare(const std::string &name_, const std::string &origin_) const;
    };

}