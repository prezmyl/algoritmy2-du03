//
// Created by xpolas on 11/24/24.
//

#ifndef SIMPLEOWNHASHFUNCTION_H
#define SIMPLEOWNHASHFUNCTION_H
#include <string>

#include "InterfaceHashFunction.h"


class SimpleOwnHashFunction : public InterfaceHashFunction{
public:
    int ComputeHash(const string key, size_t tableSize) const override;
};



#endif //SIMPLEOWNHASHFUNCTION_H
