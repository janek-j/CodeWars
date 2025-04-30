#include <iostream>
#include <functional>
#include <memory>
#include <utility>

/*
 * Smart pointery, to inteligentne wskazniki. Zapewniaja bezpieczenstwo RAII, bo automatycznie zwalniaja zasoby, gdy
 * obiekt wychodzi z zakresu. Dzieki nim, unika sie memory leakow i double delete.
 *
 *      -std::unique_ptr: Wskaznik posiadajacy wylaczna wlasnosc obiektu. Mozna go przeniesc korzystajac z std::move i nie mozna kopiowac.
 *       auto p2 = std::move(p1); //przeniesienie.
 *
 *      -std::shared_ptr: Umozliwia wielu wskaznikom posiadanie jednego zasobu. Dziala dzieki licznikom referencji. Gdy licznik
 *       spadnie do zera, zasob jest zwalniany. Przy kazdej kopii licznik jest inkrementowany, a przy reset() jest dekrementowany. Wiekszy koszt, bo kontrola licznika
 *       i pulapka cyklicznych referencji. Obiekty wzajemnie wskazujace shared_ptr nigdy sie nie zniszcza.
 *
 *      -std::weak_ptr: Slaby wskaznik do zasobu zarzadzanego przez shared_ptr. Nie wplywa na licznik referencji. Aby uzyskac dostep
 *       do obiektu wywoluje sie lock(): auto tmp = sp.lock();
 *       Weak ptr uzywa sie, gdy shared_ptr tworzy cykl ownership.
 *
 *
 * */

class Book {
private:
  std::string title;
public:
  Book() = default;
  explicit Book(std::string _title): title(std::move(_title)) {
    std::cout << "Tworzenie ksiazki." << std::endl;
  }
  ~Book() {
    std::cout << "Niszczenie ksiazki " << get_title() << std::endl;
  }
  [[nodiscard]] std::string get_title() const {
    return title;
  }
  void read() const {
    std::cout << "Czytam " << get_title() << std::endl;
  }
};

class BookShelf: public Book {
public:
  std::vector<std::shared_ptr<Book>> books;
  explicit BookShelf(const int n): Book() {
    std::cout << "Creating a bookshelf." << std::endl;
    books.reserve(n);
  }

  void add_book(const std::shared_ptr<Book>& book) {
    books.push_back(book);
    std::cout << "Dodaje ksiazke " << book->get_title() << " do biblioteczki ";
  }
  void list_books() const {
    for (const auto &book: books) {
      std::cout << book->get_title() << std::endl;
    }
  }
};

void unique_example() {
  const auto b = std::make_unique<Book>("Wladca pierscieni");
  b -> read();
 }


int main() {
  unique_example();

  BookShelf shelf(5);
  shelf.add_book(std::make_shared<Book>("Pan Tadeusz"));
  shelf.add_book(std::make_shared<Book>("Lalka"));
  shelf.add_book(std::make_shared<Book>("Zbrodnia i kara"));
  shelf.add_book(std::make_shared<Book>("Przedwiośnie"));
  shelf.add_book(std::make_shared<Book>("Mistrz i Malgorzata"));
  shelf.list_books();

  return 0;
}