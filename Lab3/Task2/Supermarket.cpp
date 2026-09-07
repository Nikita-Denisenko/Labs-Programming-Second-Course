#include "Supermarket.h"

#include <iostream>

using namespace std;

Supermarket::Supermarket(
    string name,
    string address,
    int foundationYear,
    int number,
    int cashDesks,
    int departments
)
    : Store(name, address, foundationYear, number),
    cashDesks(cashDesks),
    departments(departments)
{
}

void Supermarket::print() const
{
    Store::print();

    cout << "Cash desks: " << cashDesks << '\n';
    cout << "Departments: " << departments << '\n';
}

void Supermarket::openStore()
{
    cout << "Supermarket is open.\n";
}

void Supermarket::closeStore()
{
    cout << "Supermarket is closed.\n";
}
