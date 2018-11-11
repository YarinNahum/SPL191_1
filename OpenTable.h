
#ifndef SPL191_1_OPENTABLE_H
#define SPL191_1_OPENTABLE_H


#include <string>

class OpenTable {

public:
    OpenTable(std::string tableStr);
    int getNumOfCustomers();

private:
    int numOfCustomers;

};


#endif //SPL191_1_OPENTABLE_H
