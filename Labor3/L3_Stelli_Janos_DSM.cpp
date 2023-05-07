#include "L3_Stelli_Janos_DSM.h"

#include <utility>


DSM::DSM(int elementCount_) {
    this->elementCount = elementCount_;
    this->elementNames = new std::string[elementCount_];

    this->connectionMatrix = new int *[elementCount_];
    for (int i = 0; i < elementCount_; i++) {
        this->connectionMatrix[i] = new int[elementCount_];
        for (int j = 0; j < elementCount_; j++) {
            this->connectionMatrix[i][j] = 0;
        }
    }
}

DSM::DSM(string *elementNames_, int elementCount_) : DSM(elementCount_) {
    this->elementNames = new string[elementCount_];
    for (int i = 0; i < elementCount_; i++) {
        this->elementNames[i] = elementNames_[i];
    }

    connectionMatrix = new int *[elementCount_];
    for (int i = 0; i < elementCount_; i++) {
        connectionMatrix[i] = new int[elementCount_];
        for (int j = 0; j < elementCount_; j++) {
            connectionMatrix[i][j] = 0;
        }
    }
}


DSM::DSM(const DSM &other) {
    elementCount = other.elementCount;
    elementNames = new string[elementCount];
    for (int i = 0; i < elementCount; i++) {
        elementNames[i] = other.elementNames[i];
    }
    connectionMatrix = new int *[elementCount];
    for (int i = 0; i < elementCount; i++) {
        connectionMatrix[i] = new int[elementCount];
        for (int j = 0; j < elementCount; j++) {
            connectionMatrix[i][j] = other.connectionMatrix[i][j];
        }
    }
}


int DSM::size() const {
    return this->elementCount;
}

string DSM::getName(int index) {
    if (index >= 0 && index < elementCount)
        return elementNames[index];
    return "";
}

void DSM::setElementName(int index, string elementName) {
    if (index >= 0 && index < elementCount) {
        elementNames[index] = std::move(elementName);
        return;
    }
    throw exception();
}


void DSM::addLink(const string &fromElement, const string &toElement, int weight) {
    int fromIndex = -1;
    int toIndex = -1;
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == fromElement) fromIndex = i;
        if (elementNames[i] == toElement) toIndex = i;
        if (fromIndex != -1 && toIndex != -1) break;
    }

    if (fromIndex == -1) {
        resizeUpOne();
        elementNames[elementCount] = fromElement;
        fromIndex = elementCount++;
    }

    if (toIndex == -1) {
        resizeUpOne();
        elementNames[elementCount] = toElement;
        toIndex = elementCount++;
    }
    connectionMatrix[fromIndex][toIndex] = weight;

}


void DSM::deleteLink(const string &fromElement, const string &toElement) {
    int fromIndex = -1;
    int toIndex = -1;
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == fromElement) fromIndex = i;
        if (elementNames[i] == toElement) toIndex = i;
    }
    if (fromIndex != -1 && toIndex != -1)
        connectionMatrix[fromIndex][toIndex] = 0;

}

bool DSM::hasLink(const string &fromElement, const string &toElement) {
    int fromIndex = -1;
    int toIndex = -1;
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == fromElement) {
            fromIndex = i;
        }
        if (elementNames[i] == toElement) {
            toIndex = i;
        }
    }
    if (fromIndex != -1 && toIndex != -1) {
        return connectionMatrix[fromIndex][toIndex] > 0;
    }
    return false;
}

int DSM::linkWeight(const string &fromElement, const string &toElement) {
    int fromIndex = -1;
    int toIndex = -1;
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == fromElement) {
            fromIndex = i;
        }
        if (elementNames[i] == toElement) {
            toIndex = i;
        }
    }
    if (fromIndex != -1 && toIndex != -1) {
        return connectionMatrix[fromIndex][toIndex];
    }
    return 0;
}

int DSM::countToLinks(const string &elementName) {
    int toLinks = 0;
    int index = -1;
    for (int i = 0; i < elementCount; i++)
        if (elementNames[i] == elementName) {
            index = i;
            break;
        }
    if (index != -1)
        for (int i = 0; i < elementCount; i++)
            toLinks += connectionMatrix[i][index];
    return toLinks;
}

int DSM::countFromLinks(const string &elementName) {
    int fromLinks = 0;
    int index = -1;
    for (int i = 0; i < elementCount; i++)
        if (elementNames[i] == elementName) {
            index = i;
            break;
        }
    if (index != -1)
        for (int i = 0; i < elementCount; i++)
            fromLinks += connectionMatrix[index][i];
    return fromLinks;
}

int DSM::countAllLinks() {
    int links = 0;
    for (int i = 0; i < elementCount; i++)
        for (int j = 0; j < elementCount; j++)
            if (connectionMatrix[i][j] > 0)
                links++;
    return links;
}

DSM::~DSM() {
    for (int i = 0; i < elementCount; i++) {
        delete[] connectionMatrix[i];
    }
    delete[] connectionMatrix;
    delete[] elementNames;
}

void DSM::resizeUpOne() {

    auto *newElementNames = new std::string[elementCount + 1];
    int i = 0;
    for (; i < elementCount + 1; i++)
        newElementNames[i] = elementNames[i];
    newElementNames[i] = "";

    int **newMatrix = new int *[elementCount + 1];
    for (i = 0; i < elementCount + 1; i++) {
        connectionMatrix[i] = new int[elementCount + 1];
        for (int j = 0; j < elementCount + 1; j++) {
            newMatrix[i][j] = 0;
        }
    }
    for (i = 0; i < elementCount; i++)
        for (int j = 0; j < elementCount; j++)
            newMatrix[i][j] = connectionMatrix[i][j];

    for (i = 0; i < elementCount; i++) {
        delete[] connectionMatrix[i];
    }
    delete[] connectionMatrix;
    delete[] elementNames;

    connectionMatrix = newMatrix;
    elementNames = newElementNames;
    elementCount++;
}

void DSM::resizeDownOne(int index) {
    auto *newElementNames = new std::string[elementCount - 1];
    int i = 0;
    for (; i < index; i++) newElementNames[i] = elementNames[i];
    for (; i < elementCount - 1; i++) newElementNames[i] = elementNames[i + 1];

    int **newMatrix = new int *[elementCount - 1];
    for (i = 0; i < elementCount - 1; i++) {
        connectionMatrix[i] = new int[elementCount - 1];
        for (int j = 0; j < elementCount - 1; j++) {
            newMatrix[i][j] = 0;
        }
    }

    i = 0;
    for (; i < index; i++) {
        int j = 0;
        for (; j < index; j++)
            newMatrix[i][j] = connectionMatrix[i][j];
        for (; j < elementCount - 1; j++)
            newMatrix[i][j] = connectionMatrix[i][j + 1];
    }
    for (; i < elementCount - 1; i++) {
        int j = 0;
        for (; j < index; j++)
            newMatrix[i][j] = connectionMatrix[i + 1][j];
        for (; j < elementCount - 1; j++)
            newMatrix[i][j] = connectionMatrix[i + 1][j + 1];
    }

    for (i = 0; i < elementCount; i++)
        for (int j = 0; j < elementCount; j++)
            newMatrix[i][j] = connectionMatrix[i][j];

    for (i = 0; i < elementCount; i++) {
        delete[] connectionMatrix[i];
    }
    delete[] connectionMatrix;
    delete[] elementNames;

    connectionMatrix = newMatrix;
    elementNames = newElementNames;
    elementCount--;
}
