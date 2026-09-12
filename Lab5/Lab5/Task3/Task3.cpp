#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Book
{
private:
    std::string title;
    std::string author;
    int year;

public:
    Book(
        const std::string& title,
        const std::string& author,
        int year)
        : title(title),
        author(author),
        year(year)
    {
    }

    const std::string& GetTitle() const
    {
        return title;
    }

    const std::string& GetAuthor() const
    {
        return author;
    }

    int GetYear() const
    {
        return year;
    }
};

class BookComparator
{
public:
    bool operator()(
        const Book& first,
        const Book& second) const
    {
        if (first.GetAuthor() != second.GetAuthor())
        {
            return first.GetAuthor() < second.GetAuthor();
        }

        return first.GetTitle() < second.GetTitle();
    }
};

class YearRangePredicate
{
private:
    int minYear;
    int maxYear;

public:
    YearRangePredicate(
        int minYear,
        int maxYear)
        : minYear(minYear),
        maxYear(maxYear)
    {
    }

    bool operator()(const Book& book) const
    {
        return book.GetYear() >= minYear &&
            book.GetYear() <= maxYear;
    }
};

void PrintBook(const Book& book)
{
    std::cout << book.GetAuthor()
        << " - "
        << book.GetTitle()
        << " ("
        << book.GetYear()
        << ")\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<Book> books =
    {
        Book("Мастер и Маргарита", "Булгаков", 1967),
        Book("Отцы и дети", "Тургенев", 1862),
        Book("Преступление и наказание", "Достоевский", 1866),
        Book("Идиот", "Достоевский", 1869),
        Book("Война и мир", "Толстой", 1869),
        Book("Анна Каренина", "Толстой", 1878),
        Book("Герой нашего времени", "Лермонтов", 1840),
        Book("Евгений Онегин", "Пушкин", 1833)
    };

    std::cout << "Исходная коллекция:\n\n";

    for (const Book& book : books)
    {
        PrintBook(book);
    }

    std::sort(
        books.begin(),
        books.end(),
        BookComparator());

    std::cout << "\nПосле сортировки:\n\n";

    for (const Book& book : books)
    {
        PrintBook(book);
    }

    int minYear;
    int maxYear;

    std::cout << "\nВведите диапазон годов:\n";
    std::cout << "От: ";
    std::cin >> minYear;

    std::cout << "До: ";
    std::cin >> maxYear;

    std::vector<Book> foundBooks;

    std::copy_if(
        books.begin(),
        books.end(),
        std::back_inserter(foundBooks),
        YearRangePredicate(minYear, maxYear));

    std::cout << "\nКниги в указанном диапазоне:\n\n";

    if (foundBooks.empty())
    {
        std::cout << "Книги не найдены.\n";
    }
    else
    {
        for (const Book& book : foundBooks)
        {
            PrintBook(book);
        }
    }

    return 0;
}