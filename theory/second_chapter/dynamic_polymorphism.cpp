/*
 * Dynamiczny polimorfizm (runtime polymorphism) to mechanizm jezyka C++, w ktorym wybor odpowiedniej wersji
 * funkcji (zazwyczaj wirtualnej) nastepuje w czasie wykonywania programu, na podstawie rzeczywistego typu obiektu,
 * a nie typu wskaznika lub referencji przez ktory jest on uzywany.
 *
 * Polimorfizm dynamiczny dziala na vtable, vptr i na slowie kluczowym virtual.
 *
 * Vtable to wirtualna tablica metod. Dla kazdej klasy, ktora ma metody wirtualne kompilator generuje statyczna
 * tablice wskaznikow do funkcji.
 *
 * Vptr to pointer do vtable. Kazdy obiekt z metodami wirtualnymi zawiera ukryty wskaznik (vptr) skierowany
 * na odpowiednia vtable. Jest inicjalizowany w konstruktorze na poczatku tworzenia obiektu.
 *
 * Jak to sie dzieje?
 * Najpierw jest ladowany vptr, potem wskaznik zaladowany przez kompilator znajduje w vtable wskaznik do wlasciwej funkcji, pozniej skacze
 * pod adres z vtable i wykonuje odpowiednia metode.
 *
 * Wazne, ze polimorfizm dynamiczny wiaze sie z RUNTIME czyli dziala podczas dzialania programu!!!
*/

#include <iostream>

class A {
private:
    std::string text;
public:
    A() {
        std::cout << "A constructor" << std::endl;
    }

    virtual void print_text() = 0;

    virtual ~A() {
        std::cout << "A destructor";
    };
};

class B: public A {
private:
    std::string* text;
public:
    B(): text(new std::string("")) {
        std::cout << "B constructor " << std::endl;
    }

    B(const std::string &_text): text(new std::string(_text)) {
        std::cout << "B constructor" << std::endl;
    }

    const std::string get_text() const {
        return *text;
    }

    void print_text() override {
        std::cout << "class B print_text()" << std::endl;
        std::cout << get_text() << std::endl;
    }

    ~B() {
        std::cout << "Destructor B" << std::endl;
        delete this->text;
    }
};


//Example of dynamic polymorphism.
int main(int args, char* argv[]) {
    A *a = new B("some text");
    a -> print_text();
    delete a;
    return 0;
}

