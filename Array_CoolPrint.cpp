/* 
Построчная выводилка элементов массива.
В примере вывод 100 элементов значением 10, ввиде 10 строк по 10 элементов в строке
 */

#include <iostream>

void printarray(int* array, int size) {
    for (int i = 0, k = 10; i < size; i++, k -= 1) { // Задаем кол-во элементов в строке через k тут
        if (k > 0) {
            std::cout << *(array + i) << " ";
        }
        else {
            std::cout << std::endl;
            std::cout << *(array + i) << " ";
            k = 10; // И тут
        }
    } std::cout << std::endl;
}

int main() {
    int N = 100; // кол-во элементов массива 
    int number = 10; // содержимое элемента массива
    int* parr = new int[N];
    for (int i = 0; i < N; i++) {
        *(parr + i) = number;
    }
    printarray(parr, N);
    return 0;
}