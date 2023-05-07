#include <string>

using namespace std;

class DSM {
private:
    string *elementNames;
    int **connectionMatrix;
    int elementCount;

public:

    explicit DSM(int elementCount);

    DSM(string *elementNames, int elementCount);

    DSM(const DSM &other);

    int size() const;

    string getName(int index);

    void addLink(const string &fromElement, const string &toElement, int weight);

    void setElementName(int index, string elementName);

    void deleteLink(const string &fromElement, const string &toElement);

    bool hasLink(const string &fromElement, const string &toElement);

    int linkWeight(const string &fromElement, const string &toElement);

    int countToLinks(const string &elementName);

    int countFromLinks(const string &elementName);

    int countAllLinks();

    ~DSM();

    void resizeUpOne();

    void resizeDownOne(int index);
};