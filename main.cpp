#include "HashTable.h"
#include "SimpleOwnHashFunction.h"
#include "AdvancedOwnHashFunction.h"
#include <iostream>
#include <memory>

#include "AdvancedOwnHashFunction.h"
using namespace std;

int main() {
    // Tabulka s SimpleOwnHashFunction
    cout << "Tabulka s SimpleOwnHashFunction:" << endl;
    HashTable table1(101, make_unique<SimpleOwnHashFunction>());
    table1.Insert("Alice", 25);
    table1.Insert("Bob", 30);
    table1.Insert("Charlie", 35);

    table1.Report();

    // Tabulka s AdvancedHashFunction
    cout << "\nTabulka s AdvancedHashFunction:" << endl;
    HashTable table2(101, make_unique<AdvancedOwnHashFunction>());
    table2.Insert("Alice", 25);
    table2.Insert("Dave", 50);
    table2.Insert("Eve", 75);

    table2.Report();

    // Hledání klíče
    int value;
    if (table2.TryGetValue("Alice", value)) {
        cout << "\nHodnota pro klíč 'Alice' v table2: " << value << endl;
    }

    return 0;
}
