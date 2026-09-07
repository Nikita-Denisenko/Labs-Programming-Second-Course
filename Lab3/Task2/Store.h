#pragma once

#include <string>

using namespace std;

class Store
{
private:
    string name;
    string address;
    int foundationYear;
    int number;

    double totalProfit;

    double septemberProfit;
    double octoberProfit;
    double novemberProfit;

public:
    Store();

    Store(
        string name,
        string address,
        int foundationYear,
        int number
    );

    virtual ~Store() = default;

    void setName(const string& name);
    void setAddress(const string& address);
    void setFoundationYear(int year);
    void setNumber(int number);

    void setSeptemberProfit(double profit);
    void setOctoberProfit(double profit);
    void setNovemberProfit(double profit);

    double getTotalProfit() const;
    double getAverageProfitIncrease() const;

    virtual void print() const;

    void serialize() const;
    void deserialize();

    void serialize(string filename) const;
    void deserialize(string filename);

protected:
    void updateTotalProfit();
};
