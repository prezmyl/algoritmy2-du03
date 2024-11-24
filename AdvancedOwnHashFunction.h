//
// Created by xpolas on 11/24/24.
//

#ifndef ADVANCEDOWNHASHFUNCTION_H
#define ADVANCEDOWNHASHFUNCTION_H
#include "InterfaceHashFunction.h"


class AdvancedOwnHashFunction : public InterfaceHashFunction {
public:
    int ComputeHash(const string key, size_t tableSize) const override;

};



#endif //ADVANCEDOWNHASHFUNCTION_H
