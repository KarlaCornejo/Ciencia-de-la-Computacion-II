// Programación Genérica -> Programación General
// General -> generalizar muchas varias
// Fin: No hacer el mismo codigo para muchos de variables

#include <iostream>

using namespace std;

template<class T>
class Print
{
    private:
        T x;

    public:
        Print() = default;
        Print(T x);
        void print_variable();
};

template<class T>
Print<T>::Print(T x)
{
    this -> x = x;
}

template<class T>
void Print<T>::print_variable()
{
    cout << x << " ";
}

int main()
{
    Print<int> p(20);
    p.print_variable();
}
