#pragma once

#include "Store.h"
#include "IStoreOperations.h"

class Supermarket
    : public Store,
    public IStoreOperations
{
private:
    int cashDesks;
    int departments;

public:
    Supermarket(
        string name,
        string address,
        int foundationYear,
        int number,
        int cashDesks,
        int departments
    );

    void print() const override;

    void openStore() override;
    void closeStore() override;
};
