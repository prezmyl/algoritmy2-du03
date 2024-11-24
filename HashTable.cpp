//
// Created by xpolas on 11/24/24.
//

#include "HashTable.h"

#include <iostream>

#include "SimpleOwnHashFunction.h"
using namespace std;

HashTable::HashTable()
    : tableSize(101), keysCount(0), hashFunc(make_unique<SimpleOwnHashFunction>()){

    if (tableSize <= 0) {
        throw invalid_argument("Table size must be greater than 0");
    }
    Initialize();
}

HashTable::HashTable(const int tableSize, unique_ptr<InterfaceHashFunction> hashFunc)
    : tableSize(tableSize), keysCount(0), hashFunc(move(hashFunc)) {
    if (tableSize <= 0) {
        throw invalid_argument("Table size must be greater than 0");
    }`
    if (!this->hashFunc) {
        throw invalid_argument("Hash function must not be null");
    }
    Initialize();
}


bool HashTable::ContainKey(const string &key) const {
    int index = hashFunc->ComputeHash(key, tableSize);
    for (const auto& pair : table[index]) {
        if (pair.key == key) {
            return true;
        }
    }
    return false;
}

bool HashTable::TryGetValue(const string &key, int &value) const {
    int index = hashFunc->ComputeHash(key, tableSize);
    for (const auto& pair : table[index]) {
        if (pair.key == key) {
            value = pair.value;
            return true;
        }
    }
    return false;
}

void HashTable::Insert(const string& key, const int newValue) {
    // Ověření platnosti hash funkce
    if (!hashFunc) {
        throw runtime_error("Hash function not initialized");
    }

    // Výpočet indexu
    int index = hashFunc->ComputeHash(key, tableSize);

    // Ověření platnosti indexu
    if (index < 0 || index >= tableSize) {
        throw out_of_range("Hash index out of range");
    }

    // Vyhledání klíče a aktualizace hodnoty, pokud existuje
    for (auto& pair : table[index]) {
        if (pair.key == key) {
            pair.value = newValue;
            return;
        }
    }

    // Pokud klíč neexistuje, přidání nového záznamu
    table[index].emplace_back(KeyValuePair{key, newValue});
    keysCount++;
}


void HashTable::Delete(const string &key) {
    int index = hashFunc->ComputeHash(key, tableSize);
    auto& bucket = table[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->key == key) {
            bucket.erase(it);
            keysCount--;
            return;
        }
    }
}

void HashTable::Clear() {
    table.clear();
    keysCount = 0;
    Initialize();
}

void HashTable::Initialize() {
    table.resize(tableSize);
}

size_t HashTable::GetTableSize() const {
    return tableSize;
}

size_t HashTable::GetNumberOfKeys() const {
    return keysCount;
}

double HashTable::GetLoadFactor() const {
    return static_cast<double>(keysCount / tableSize);
}

void HashTable::Report() const {
    for (size_t i = 0; i < table.size(); i++) {
        if (!table[i].empty()) {
            cout << "Slot " << i << ": ";
            for (const auto& pair : table[i]) {
                cout << "(" << pair.key << ", " << pair.value << ") ";
            }
            cout << endl;
        }
    }
}


