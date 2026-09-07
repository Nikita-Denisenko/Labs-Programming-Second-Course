#include <iostream>
#include <vector>

#include "Store.h"
#include "Supermarket.h"
#include "OnlineStore.h"
#include "IStoreOperations.h"

using namespace std;

int main()
{
    Store* store1 = new Store(
        "Magnit",
        "Lenina 10",
        1994,
        101
    );

    Supermarket* supermarket = new Supermarket(
        "Pyaterochka",
        "Mira 25",
        1999,
        102,
        8,
        12
    );

    OnlineStore* onlineStore = new OnlineStore(
        "Lenta Online",
        "Centralnaya 5",
        1993,
        103,
        "lenta.ru",
        1500
    );

    Supermarket* supermarket2 = new Supermarket(
        "Auchan",
        "Sovetskaya 15",
        1961,
        104,
        12,
        18
    );


    // Заполняем прибыль
    store1->setSeptemberProfit(120000);
    store1->setOctoberProfit(140000);
    store1->setNovemberProfit(160000);

    supermarket->setSeptemberProfit(150000);
    supermarket->setOctoberProfit(155000);
    supermarket->setNovemberProfit(180000);

    onlineStore->setSeptemberProfit(200000);
    onlineStore->setOctoberProfit(230000);
    onlineStore->setNovemberProfit(270000);

    supermarket2->setSeptemberProfit(130000);
    supermarket2->setOctoberProfit(160000);
    supermarket2->setNovemberProfit(190000);


    // Массив указателей базового класса
    vector<Store*> stores =
    {
        store1,
        supermarket,
        onlineStore,
        supermarket2
    };


    cout << "POLYMORPHISM\n\n";

    for (Store* store : stores)
    {
        store->print();

        cout << "\n------------------------\n";
    }


    // RTTI + интерфейс
    cout << "\nRTTI AND INTERFACE\n\n";

    for (Store* store : stores)
    {
        IStoreOperations* operations =
            dynamic_cast<IStoreOperations*>(store);

        if (operations != nullptr)
        {
            cout << "Object supports IStoreOperations:\n";

            operations->openStore();
            operations->closeStore();
        }
        else
        {
            cout << "Object does not support IStoreOperations.\n";
        }

        cout << '\n';
    }


    delete store1;
    delete supermarket;
    delete onlineStore;
    delete supermarket2;

    return 0;
}
