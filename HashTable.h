//
// Created by xpolas on 11/24/24.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "InterfaceHashFunction.h"
#include "keyValuePair.h"
#include <string>
#include <memory>
#include <vector>

using namespace std;

class HashTable {
private:
    size_t tableSize;
    size_t keysCount;
    unique_ptr<InterfaceHashFunction> hashFunc;
    vector<vector<KeyValuePair>> table;




public:
    HashTable();
    HashTable(const int tableSize, unique_ptr<InterfaceHashFunction> hashFunc);
    ~HashTable() = default;

    bool ContainKey(const string& key) const;
    bool TryGetValue(const string& key, int& value) const;
    void Insert(const string& key, const int newValue);
    void Delete(const string& key);
    void Clear();
    void Initialize();


    size_t GetTableSize() const;
    size_t GetNumberOfKeys() const;
    double GetLoadFactor() const;
    void Report() const;


};



#endif //HASHTABLE_H
