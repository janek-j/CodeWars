#include <iostream>
#include <functional>
#include <memory>
#include <utility>

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
  auto greater = [](const int x, const int y) { return x > y; };
  auto lower = [](const int x, const int y) { return x < y; };
  auto equals = [](const int x, const int y) { return x == y; };
  const std::function<int(int)> square = [](const int x) { return x*x; };

  unique_example();

  BookShelf shelf(5);
  shelf.add_book(std::make_shared<Book>("Pan Tadeusz"));
  shelf.add_book(std::make_shared<Book>("Lalka"));
  shelf.add_book(std::make_shared<Book>("Zbrodnia i kara"));
  shelf.add_book(std::make_shared<Book>("Przedwiośnie"));
  shelf.add_book(std::make_shared<Book>("Mistrz i Malgorzata"));
  shelf.list_books();

  std::cout << greater(3, 4) << std::endl;
  std::cout << lower(3,4) << std::endl;
  std::cout << equals(4, 4) << std::endl;
  std::cout << square(4) << std::endl;

  return 0;
}