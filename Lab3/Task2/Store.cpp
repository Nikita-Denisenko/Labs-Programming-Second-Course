#include "Store.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Store::Store()
    : foundationYear(0),
    number(0),
    totalProfit(0),
    septemberProfit(0),
    octoberProfit(0),
    novemberProfit(0)
{
}

Store::Store(
    string name,
    string address,
    int foundationYear,
    int number
)
    : name(name),
    address(address),
    foundationYear(foundationYear),
    number(number),
    totalProfit(0),
    septemberProfit(0),
    octoberProfit(0),
    novemberProfit(0)
{
}

void Store::setName(const string& name)
{
    this->name = name;
}

void Store::setAddress(const string& address)
{
    this->address = address;
}

void Store::setFoundationYear(int year)
{
    foundationYear = year;
}

void Store::setNumber(int number)
{
    this->number = number;
}

void Store::setSeptemberProfit(double profit)
{
    septemberProfit = profit;
    updateTotalProfit();
}

void Store::setOctoberProfit(double profit)
{
    octoberProfit = profit;
    updateTotalProfit();
}

void Store::setNovemberProfit(double profit)
{
    novemberProfit = profit;
    updateTotalProfit();
}

double Store::getTotalProfit() const
{
    return totalProfit;
}

double Store::getAverageProfitIncrease() const
{
    double increaseSeptemberOctober =
        octoberProfit - septemberProfit;

    double increaseOctoberNovember =
        novemberProfit - octoberProfit;

    return (
        increaseSeptemberOctober +
        increaseOctoberNovember
        ) / 2.0;
}

void Store::print() const
{
    cout << "Name: " << name << '\n';
    cout << "Address: " << address << '\n';
    cout << "Foundation year: " << foundationYear << '\n';
    cout << "Number: " << number << '\n';

    cout << fixed << setprecision(2);

    cout << "September profit: "
        << septemberProfit << '\n';

    cout << "October profit: "
        << octoberProfit << '\n';

    cout << "November profit: "
        << novemberProfit << '\n';

    cout << "Total profit: "
        << totalProfit << '\n';

    cout << "Average profit increase: "
        << getAverageProfitIncrease() << '\n';
}

void Store::serialize() const
{
    serialize("store.txt");
}

void Store::deserialize()
{
    deserialize("store.txt");
}

void Store::serialize(string filename) const
{
    ofstream file(filename);

    if (!file)
    {
        cout << "Error opening file for writing.\n";
        return;
    }

    file << name << '\n';
    file << address << '\n';
    file << foundationYear << '\n';
    file << number << '\n';
    file << totalProfit << '\n';
    file << septemberProfit << '\n';
    file << octoberProfit << '\n';
    file << novemberProfit << '\n';
}

void Store::deserialize(string filename)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "Error opening file for reading.\n";
        return;
    }

    getline(file, name);
    getline(file, address);

    file >> foundationYear;
    file >> number;
    file >> totalProfit;
    file >> septemberProfit;
    file >> octoberProfit;
    file >> novemberProfit;
}

void Store::updateTotalProfit()
{
    totalProfit =
        septemberProfit +
        octoberProfit +
        novemberProfit;
}
