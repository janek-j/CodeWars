#include <iostream>

/*
 * Polimorfizm statyczny w jezyku C++ to mechanizm, w ktorym wybor odpowiedniej funkcji lub operacji nastepuje
 * w czasie kompilacji programu, a nie w czasie dzialania programu. Jest to mozliwe dzieki przeciazaniu funkcji,
 * operatorow, czy szablonom. W przypadku szablonow, kompilator generuje funkcje na podstawie typow przekazanych
 * jako parametr w czasie kompilacji.
 *
 * W polimorfizmie statycznym kompilator sprawdza sygnatury funkcji lub szablonow w czasie kompilacji.
 * Wybiera odpowiednia wersje na podstawie dostepnych informacji o typach.
 * Generuje kod dopasowany do uzycia, bez potrzeby vtable i vptr. Polimorfizm statyczny jest bardziej wydajny od
 * polimorfizmu dynamicznego, ale jest mniej elastyczny, bo jest ograniczony do znanych typow.
 *
 * Polimorfizm statyczny dziala w trakcie kompilacji!!!
 */

template<typename T>
void print_number(T number) {
    std::cout << "Printing generic type number: " << number << std::endl;
}

void print_number(int number) {
    std::cout << "Printing integer number: " << number << std::endl;
}

void print_number(float number) {
    std::cout << "Printing floating point number: " << number << std::endl;
}

void print_number(std::string number) {
    std::cout << "Printing string number: " << number << std::endl;
}



int main() {

    int num1 = 3;
    float num2 = 3.0;
    std::string num3 = "4.0";

    print_number(num1);
    print_number(num2);
    print_number(num3);

    return 0;
}

