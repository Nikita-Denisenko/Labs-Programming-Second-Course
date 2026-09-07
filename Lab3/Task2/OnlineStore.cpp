#include "OnlineStore.h"

#include <iostream>

using namespace std;

OnlineStore::OnlineStore(
    string name,
    string address,
    int foundationYear,
    int number,
    string website,
    int ordersPerMonth
)
    : Store(name, address, foundationYear, number),
    website(website),
    ordersPerMonth(ordersPerMonth)
{
}

void OnlineStore::print() const
{
    Store::print();

    cout << "Website: " << website << '\n';
    cout << "Orders per month: "
        << ordersPerMonth << '\n';
}

void OnlineStore::openStore()
{
    cout << "Online store is available.\n";
}

void OnlineStore::closeStore()
{
    cout << "Online store is unavailable.\n";
}
