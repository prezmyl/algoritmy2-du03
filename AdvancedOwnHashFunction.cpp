//
// Created by xpolas on 11/24/24.
//

#include "AdvancedOwnHashFunction.h"

int AdvancedOwnHashFunction::ComputeHash(const string key, size_t tableSize) const {
    int hash = 0;
    for (size_t i = 0; i < key.size(); ++i) {
        hash = (hash + key[i] * (i + 1)) % tableSize;
    }
    return hash;
}
