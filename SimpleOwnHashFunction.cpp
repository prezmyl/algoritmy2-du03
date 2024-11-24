//
// Created by xpolas on 11/24/24.
//

#include "SimpleOwnHashFunction.h"


int SimpleOwnHashFunction::ComputeHash(const string key, size_t tableSize) const {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % tableSize;
    }
    return hash;
}
