#include <iostream>

/*
 * Casting to rzutowanie. Mozna rzutowac jeden typ danych, na inny. Na przyklad int na double. W przypadku castowania
 * double na int, traci sie czesc po przecinku, wiec trzeba uwazac.
 *
 * W C++ wyroznia sie:
 *
 *  -static_cast:
 *      Jest bezpieczna, kompilatorowa konwersja miedzy typami, ktore maja ze soba logiczny zwiazek. Sprawdza
 *      w czasie kompilacji, czy jest mozliwa konwersja pomiedzy jednym typem, a drugim. Static cast nie generuje kodu runtime.
 *
 *  -dynamic_cast:
 *      Jest bezpiecznym runtimowym rzutowaniem w hierarchii klas z polimorfizmem. Dynamic cast wykorzysuje
 *      wewnetrzne informacje RTTI (RunTimeTypeInformation). Moze rzucac wyjatek std::bad_cast lub zwracac nullptr dla wskaznikow.
 *
 *  -const_cast:
 *      Dodaje lub usuwa kwalifikator const (lub volatile) z typu na etapie kompilacji. Nie zmienia danych w pamieci, ale
 *      pozwala pisac do stalego obiektu. Uzywa sie rzadko, gdy np. trzeba uzyc metody z API , ktora nie przyjmuje const.
 *
 *  -reinterpret_cast:
 *      Najniebezpieczniejszy cast, traktuje bity obiektu w pamieci, jako inny, niepowiazany typ.
 *      Nie weryfikuje bezpieczenstwa, zmienia interpretacje adresu/bajtow. Uzywa sie w sytuacjach niskopoziomowych, gdy
 *      ma sie pelna kontrole nad ukladem bitow.
 *
 *  -C style cast:
 *      (int) (double) itp. Rzadko uzywane, lepiej castowac uzywajac wbudowanych castow w C++.
 *
 * */

int main() {
    const int _temp = 3;
    int x = 3;
    double y = 4.44;
    int z = static_cast<int>(y);
    double a = static_cast<double>(x);
    int _temp2 = const_cast<int&>(_temp); //do const cast trzeba uzyc referencji.

    a += 0.00001;
    _temp2 += 4;
    std::cout << "const _temp " <<  _temp << std::endl;
    std::cout << "_temp2 " << _temp2 << std::endl;
    std::cout << "x " << x << std::endl;
    std::cout << "y " << y << std::endl;
    std::cout << "z " << z << std::endl;
    std::cout << "a " << a << std::endl;

    return 0;
}