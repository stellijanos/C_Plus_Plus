//
// Created by Janos Stelli on 2023. 03. 24..
//
#include <iostream>
#include <string>
#include <cassert>
#include "L2_Stelli_Janos_Problem2_duration.h"

using namespace std;


void test_get_value() {
    Duration time1(34.5, "min");

    double expected = 34.5;
    double result = time1.get_value();

    assert(result == expected);
    cout << "Test  1 successful!\n";
}

void test_get_unit() {
    Duration time1(34.5, "min");

    string expected = "min";
    string result = time1.get_unit();

    assert(result == expected);
    cout << "Test  2 successful!\n";
}

void test_add() {
    Duration time1(34.5, "min");
    Duration time2(30, "min");

    double expected = 64.5;
    double result = time1.add(time2);

    assert(result == expected);
    cout << "Test  3 successful!\n";
}

void test_subtract() {
    Duration time1(34.5, "min");
    Duration time2(30, "min");

    double expected = 4.5;
    double result = time1.subtract(time2);

    assert(result == expected);
    cout << "Test  4 successful!\n";
}

void test_scale() {
    Duration time1(34.5, "min");
    time1.scale(10);

    double expected = 345;
    double result = time1.get_value();

    assert(result == expected);
    cout << "Test  5 successful!\n";
}

void test_divide() {
    Duration time1(34.5, "min");
    time1.divide(10);

    double expected = 3.45;
    double result = time1.get_value();

    assert(result == expected);
    cout << "Test  6 successful!\n";
}

void test_text() {
    Duration time1(34.5, "min");

    string expected = "The time Duration is 34.50 in the unit of min.\n";
    string result = time1.text();

    assert(result == expected);
    cout << "Test  7 successful!\n";
}

void test_compare() {
    Duration time1(34.5, "min");
    Duration time2(40, "min");

    double expected = -1;
    double result = time1.compare(time2);

    assert(result == expected);
    cout << "Test  8 successful!\n";
}

void test_convertTo() {
    Duration time1(34.5, "sec");
    Duration time2(30, "min");

    double expected = 1800;
    time2.convertTo(time1);
    double result = time2.get_value();

    assert(result == expected);
    cout << "Test  9 successful!\n";
}

void test_operator_add() {
    Duration time1(34.5, "min");
    Duration time2(30, "min");

    double expected = 64.5;
    double result = time1 + time2;

    assert(result == expected);
    cout << "Test 10 successful!\n";
}

void test_operator_subtract() {
    Duration time1(34.5, "min");
    Duration time2(30, "min");

    double expected = 4.5;
    double result = time1 - time2;

    assert(result == expected);
    cout << "Test 11 successful!\n";
}


void test_operator_scale() {
    Duration time1(34.5, "min");

    time1 * 10;
    double expected = 345;
    double result = time1.get_value();

    assert(result == expected);
    cout << "Test 12 successful!\n";
}

void test_operator_divide() {
    Duration time1(34.5, "min");

    time1 / 10;
    double expected = 3.45;
    double result = time1.get_value();

    assert(result == expected);
    cout << "Test 13 successful!\n";
}

void all_tests() {
    cout << "Tests of all the methods:\n\n";
    test_get_value();
    test_get_unit();
    test_add();
    test_subtract();
    test_scale();
    test_divide();
    test_text();
    test_compare();
    test_convertTo();
    test_operator_add();
    test_operator_subtract();
    test_operator_scale();
    test_operator_divide();
}

void user_input() {
    double value, number;
    string unit;

    //read the values and generate the first Duration (time)
    cout << "\n\nPlease read the value:\n";
    cin >> value;
    cout << "Please read the unit:\n";
    cin >> unit;
    Duration time1(value, unit);

    //read the values and generate the second Duration (time)
    cout << "\n\nPlease read the value:\n";
    cin >> value;
    cout << "Please read the unit:\n";
    cin >> unit;
    Duration time2(value, unit);

    cout << "Please read a number: \n";
    cin >> number;

    cout << "\nAddition: " << time1 + time2 << " " << time1.get_unit() << "\n\n";
    cout << "Subtraction: " << time1 - time2 << " " << time1.get_unit() << "\n\n";
    time1 * number;
    cout << "Scale: " << time1.text() << endl;
    time2 / number;
    cout << "Division: " << time2.text() << endl;
    cout << "Comparison: " << time1.compare(time2);
}

int main() {
    all_tests();
    user_input();
    return 0;
}
