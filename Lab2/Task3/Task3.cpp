#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

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
    // Конструктор без параметров
    Store()
        : foundationYear(0),
        number(0),
        totalProfit(0),
        septemberProfit(0),
        octoberProfit(0),
        novemberProfit(0)
    {
    }

    // Конструктор с параметрами
    Store(
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

    // Сеттеры
    void setName(const string& name)
    {
        this->name = name;
    }

    void setAddress(const string& address)
    {
        this->address = address;
    }

    void setFoundationYear(int year)
    {
        foundationYear = year;
    }

    void setNumber(int number)
    {
        this->number = number;
    }

    // Продажи за сентябрь
    void setSeptemberProfit(double profit)
    {
        septemberProfit = profit;
        updateTotalProfit();
    }

    // Продажи за октябрь
    void setOctoberProfit(double profit)
    {
        octoberProfit = profit;
        updateTotalProfit();
    }

    // Продажи за ноябрь
    void setNovemberProfit(double profit)
    {
        novemberProfit = profit;
        updateTotalProfit();
    }

    // Получение общей прибыли
    double getTotalProfit() const
    {
        return totalProfit;
    }

    // Средний прирост прибыли
    double getAverageProfitIncrease() const
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

    // Вывод магазина
    void print() const
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

    // Сериализация в файл по умолчанию
    void serialize() const
    {
        serialize("store.txt");
    }

    // Десериализация из файла по умолчанию
    void deserialize()
    {
        deserialize("store.txt");
    }

    // Сериализация в указанный файл
    void serialize(string filename) const
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

    // Десериализация из указанного файла
    void deserialize(string filename)
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

private:
    void updateTotalProfit()
    {
        totalProfit =
            septemberProfit +
            octoberProfit +
            novemberProfit;
    }
};


// Вывод рейтинга магазинов
void printRating(
    vector<Store*>& stores,
    bool sortByTotalProfit
)
{
    vector<Store*> rating = stores;

    if (sortByTotalProfit)
    {
        sort(
            rating.begin(),
            rating.end(),
            [](Store* a, Store* b)
            {
                return a->getTotalProfit()
                     > b->getTotalProfit();
            }
        );
    }
    else
    {
        sort(
            rating.begin(),
            rating.end(),
            [](Store* a, Store* b)
            {
                return a->getAverageProfitIncrease()
                     > b->getAverageProfitIncrease();
            }
        );
    }

    for (Store* store : rating)
    {
        cout << "\n------------------------\n";
        store->print();
    }
}


int main()
{
    // Два магазина в куче
    Store* store1 = new Store();
    Store* store2 = new Store();

    // Первые два магазина заполняем сеттерами
    store1->setName("Magnit");
    store1->setAddress("Lenina 10");
    store1->setFoundationYear(1994);
    store1->setNumber(101);

    store2->setName("Pyaterochka");
    store2->setAddress("Mira 25");
    store2->setFoundationYear(1999);
    store2->setNumber(102);

    // Третий магазин в стеке через параметризованный конструктор
    Store store3(
        "Lenta",
        "Centralnaya 5",
        1993,
        103
    );


    // Продажи за сентябрь
    store1->setSeptemberProfit(120000);
    store2->setSeptemberProfit(150000);
    store3.setSeptemberProfit(100000);

    // Продажи за октябрь
    store1->setOctoberProfit(140000);
    store2->setOctoberProfit(155000);
    store3.setOctoberProfit(130000);

    // Продажи за ноябрь
    store1->setNovemberProfit(160000);
    store2->setNovemberProfit(180000);
    store3.setNovemberProfit(150000);


    vector<Store*> stores =
    {
        store1,
        store2,
        &store3
    };


    // Рейтинг №1:
    // по общей прибыли за 3 месяца
    cout << "RATING 1: TOTAL PROFIT\n";

    printRating(stores, true);


    // Рейтинг №2:
    // по среднему приросту прибыли
    cout << "\n\nRATING 2: AVERAGE PROFIT INCREASE\n";

    printRating(stores, false);


    // Проверка сериализации
    store3.serialize("store.txt");

    Store loadedStore;

    loadedStore.deserialize("store.txt");

    cout << "\n\nDESERIALIZED STORE\n";

    loadedStore.print();


    // Освобождаем память магазинов из кучи
    delete store1;
    delete store2;

    return 0;
}
