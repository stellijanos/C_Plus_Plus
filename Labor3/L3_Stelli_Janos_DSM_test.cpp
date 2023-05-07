#include "L3_Stelli_Janos_DSM.h"
#include <cassert>
#include <iostream>

using namespace std;


void test_all() {
    cout << "\nBegin of the tests:\n";
    DSM matrix_1(0);
    assert(matrix_1.size() == 0);
    cout << "Test 1 successful!\n";

    string elements[] = {"unit", "power", "hdd", "ram", "motherboard", "cpu", "gpu"};
    DSM matrix_2(elements, 7);
    assert(matrix_2.size() == 7);
    cout << "Test 2 successful!\n";

    assert(matrix_2.getName(6) == "gpu");
    cout << "Test 3 successful!\n";

    assert(matrix_2.getName(7) == "");
    cout << "Test 4 successful!\n";

    matrix_2.addLink("ram", "motherboard", 1);
    assert(matrix_2.linkWeight("ram", "motherboard") == 1);
    cout << "Test 5 successful!\n";

    assert(matrix_2.countToLinks("ram") == 0);
    cout << "Test 6 successful!\n";

    assert(matrix_2.countFromLinks("ram") == 1);
    cout << "Test 7 successful!\n";

    assert(matrix_2.hasLink("ram","motherboard"));
    cout<<"Test 8 successful!\n";

    matrix_2.deleteLink("ram","motherboard");
    assert(matrix_2.countAllLinks()==0);
    cout<<"Test 9 successful!\n";

    matrix_2.setElementName(4,"circuit");
    assert(matrix_2.getName(4)=="circuit");
    cout<<"Test 10 successful!\n\nEND Tests.\n";



    matrix_2.addLink("sound", "motherboard", 1);
    assert(matrix_2.linkWeight("sound", "motherboard") == 1);
    cout << "Test 11 successful!\n";

}


void testAll() {
    cout << "Begin tests:\n";

    DSM dsm1(0);
    assert(dsm1.size() == 0);
    cout << "Test 1 successful!\n";
    string elements[]={"Motor",	"Getriebe",	"Aufhangung",	"Bremsen",	"Räder",	"Türen",	"Karosserie"};

    DSM dsm2(elements, 7);
    assert(dsm2.size() == 7);
    cout << "Test 2 successful!\n";

    assert(dsm2.getName(dsm2.size()) == "");
    cout << "Test 3 successful!\n";
    assert(dsm2.getName(6) == "Karosserie");
    cout << "Test 4 successful!\n";

    dsm2.addLink("Motor", "Aufhangung", 1);
    assert(dsm2.linkWeight("Motor", "Aufhangung") == 1);
    cout << "Test 5 successful!\n";

    assert(dsm2.countToLinks("Bremsen") == 0);
    cout << "Test 6 successful!\n";

    assert(dsm2.countFromLinks("Motor") == 1);
    cout << "Test 7 successful!\n";

    assert(dsm2.hasLink("Motor","Aufhangung"));
    cout<<"Test 8 successful!\n";

    dsm2.deleteLink("Motor","Aufhangung");
    assert(dsm2.countAllLinks()==0);
    cout<<"Test 9 successful!\n";

    dsm2.setElementName(4,"Lights");
    assert(dsm2.getName(4)=="Lights");
    cout<<"Test 10 successful!\nEND Tests.\n";
}

int main() {
    //test_all();
    testAll();
    return 0;
}