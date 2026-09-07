#pragma once

#include "Store.h"
#include "IStoreOperations.h"

class OnlineStore
    : public Store,
    public IStoreOperations
{
private:
    string website;
    int ordersPerMonth;

public:
    OnlineStore(
        string name,
        string address,
        int foundationYear,
        int number,
        string website,
        int ordersPerMonth
    );

    void print() const override;

    void openStore() override;
    void closeStore() override;
};
