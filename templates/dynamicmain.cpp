#include "dynamic.h"

int main()
{
    int arr[] = {1, 4, 6, 2, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    DynamicArray<int> di(arr, size);
    di.print();
    di.pushback(5);
    di.print();
    di.pushback(10);
    di.print();
    di.pushback(90);
    di.print();
    di.pushback(100);
    di.print();
    di.pushback(3);
    di.print();
    di.pushback(8);
    di.print();
    di.insert(7, 1);
    di.print();
    di.remove(8);
    di.print();

    char arr_char[] = "karla";
    int size_char = sizeof(arr_char) / sizeof(arr_char[0]);

    DynamicArray<char> dic(arr_char, size_char);
    dic.print();
    dic.pushback(' ');
    dic.pushback('c');
    dic.pushback('o');
    dic.pushback('r');
    dic.pushback('n');
    dic.pushback('e');
    dic.pushback('j');
    dic.pushback('o');
    dic.print();
    dic.pushback(' ');
    dic.pushback('h');
    dic.print();
    dic.remove(15);
    dic.print();
    dic.insert('p' , 15);
    dic.print();

    return 0;
}