#include <iostream>
#include <memory>

namespace mierla {
    struct MyData {
        int x;
        int y;
        MyData(int _x, int _y): x(_x), y(_y) {}
    };

    void remind_me(int x, int y) {
        int *ptr_to_x = &x;
        std::cout << "Miejsce w pamieci zmiennej: " << ptr_to_x << std::endl;
        std::cout << "Jaka liczba jest w danej komorce pamieci: " << *ptr_to_x << std::endl;
        std::cout << "Podana liczba jako argument: " << x << std::endl;

        std::cout << std::endl;
        std::cout << "Inteligentne wskazniki." << std::endl;
        std::unique_ptr<int> x_ptr = std::make_unique<int>(x);
        std::cout << "Inteligentny wskaznik (Unique) i jego komorka w pamieci: " << x_ptr.get() << std::endl;
        std::cout << "Wartosc na ktora wskazuje: " << *x_ptr;

        std::cout << std::endl;
        std::cout << "Inteligentny wskaznik (Shared)" << std::endl;
        std::shared_ptr<int> x_ptr_shared = std::make_shared<int>(x);
        std::cout << std::endl;
        std::cout << "Wskaznik wspoldzielony 1: " << x_ptr_shared.get() << std::endl;
        {
            std::shared_ptr<int> x_ptr_shared_2 = x_ptr_shared;
            std::cout << "Wskaznik wspoldzielony 2: " << x_ptr_shared_2.get() << std::endl;
            std::cout << "Wartosc na ktora wskazuje: " << *x_ptr_shared_2 << std::endl;
            std::cout << "Licznik referencji: " << x_ptr_shared.use_count() << std::endl;
            if (x_ptr_shared_2) {
                std::cout << "Wartosc drugiego wskaznika wspoldzielonego z 1: " << *x_ptr_shared_2 << std::endl;
            }
            std::cout << std::endl;
            std::weak_ptr<int> x_weak_1 = x_ptr_shared;
            if (auto weak_locked = x_weak_1.lock()) {
                std::cout << "Weak_ptr (po lock()) - adres: " << weak_locked.get() << ", wartosc: " << *weak_locked << std::endl;
                std::cout << "Licznik referencji: " << x_ptr_shared.use_count() << std::endl;
            }
        }
        std::cout << "Licznik referencji: " << x_ptr_shared.use_count() << std::endl;
    }
}

int main() {
    std::cout << std::endl;
    mierla::remind_me(3,4 );
    return 0;
}