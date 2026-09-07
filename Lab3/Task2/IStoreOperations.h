#pragma once

class IStoreOperations
{
public:
    virtual void openStore() = 0;
    virtual void closeStore() = 0;

    virtual ~IStoreOperations() = default;
};
