//
// Created by xpolas on 11/24/24.
//

#ifndef INTERFACEHASHFUNCTION_H
#define INTERFACEHASHFUNCTION_H

#include <string>
using namespace std;

class InterfaceHashFunction {
public:
    virtual ~InterfaceHashFunction() = default;
    virtual int ComputeHash(const string key, size_t tableSize) const = 0;

};

#endif //INTERFACEHASHFUNCTION_H
