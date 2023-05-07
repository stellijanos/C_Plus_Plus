#include "Controller.h"

class FruitUI {
private:
    FruitController ctrl;
public:
    FruitUI(FruitController &fruitController);

    void uIScreen();

    void runUI(); //FruitController &fruitController,FruitRepo &fruitsArray
};
