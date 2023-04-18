/*
Sorting algorithms tests :
1- LineSort
2- BubbleSort2
3- MergeSort
*/

#include <iostream>
long merge(int* array1, int n1, int* array2, int n2, int* target) {
    long mergecounter = 0;
    while ((n1 != 0) && (n2 != 0)) {
        if (array1[0] >= array2[0]) {
            target[0] = array1[0];
            mergecounter++;
            array1++;
            n1--;
        }
        else {
            target[0] = array2[0];
            mergecounter++;
            array2++;
            n2--;
        }
        target++;
    }
    if (n1 == 0) {
        for (int i = 0; i < n2; i++) {
            target[i] = array2[i];
            mergecounter++;
        }
    }
    else {
        for (int i = 0; i < n1; i++) {
            target[i] = array1[i];
            mergecounter++;
        }
    }
    return mergecounter;
}

long mergesort(int* array, int n, int* target) {
    long mergesortcounter = 0;
    if (n == 0) return mergesortcounter;
    if (n == 1) {
        target[0] = array[0];
        mergesortcounter++;
        return mergesortcounter;
    }
    for (int i = 0; i < n; i++) { //Making full copy of array to target for work with halfs of arrays
        target[i] = array[i];
        mergesortcounter++;
    }
    int* left = target;
    int left_lenght = n / 2;
    int* right = array + left_lenght;
    int right_lenght = n - left_lenght;
    long a = mergesort(left, left_lenght, array);
    long b = mergesort(right, right_lenght, target + left_lenght);
    long c = merge(array, left_lenght, target + left_lenght, right_lenght, target);
    return mergesortcounter + a + b + c;
}

int main() {
    int const arSize = 1000;
    int const numberLimit = 5000;
    int arr[arSize];
    int array[arSize];
    int mergearr[arSize];
    int mergearrtarget[arSize];
    int testarrays = 10; // кол-во тестовых массивов
    long counterv1 = 0;
    long counterv2 = 0;
    long counterv3 = 0;

    while (testarrays > 0) {

        for (int i = 0; i < arSize; i++) // Рандомный массив из 1000 элементов
        {
            arr[i] = rand() % (numberLimit + 1);
        }

        for (int i = 0; i < arSize; i++) {
            int mx = 0;
            counterv1++;
            for (int j = i; j < arSize; j++) {
                counterv1++;
                if (arr[mx] < arr[j]) {
                    mx = j;
                }
            }
            int c = arr[i];
            arr[i] = arr[mx];
            arr[mx] = c;
        }
        testarrays--;
    }

    testarrays = 10;
    while (testarrays > 0) {

        for (int i = 0; i < arSize; i++) // Рандомный массив из 1000 элементов
        {
            array[i] = rand() % (numberLimit + 1);
        }

        // Наша сортировка пузырек с 2 модами
        int fst = 0;
        for (int j = 0; j < arSize - 1; j++) {
            counterv2++;
            bool flag = true;
            for (int i = fst; i < arSize - 1 - j; i++) {
                counterv2++;
                if (array[i] < array[i + 1]) {
                    int b = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = b;
                    if (flag) {
                        fst = i - 1;
                        if (fst < 0) {
                            fst = 0;
                        }
                        flag = false;
                    }
                }
            }
            if (flag) break;
        }
        testarrays--;
    }

    testarrays = 10;
    while (testarrays > 0) {
        for (int i = 0; i < arSize; i++) // Рандомный массив из 1000 элементов
        {
            mergearr[i] = rand() % (numberLimit + 1);
        }

        counterv3 = mergesort(&mergearr[0], 1000, &mergearrtarget[0]);
        testarrays--;
    }

    std::cout << "Middle iterations LineSort:" << (counterv1 / 10) << "\n"; //делим на количество тестовых массивов
    std::cout << "And last sorted array>>>" << "\n";
    for (int i = 0; i < arSize; i++) { //Смотрим на последний отсортированный массив по методу 1
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Middle iterations BubbleSort:" << (counterv2 / 10) << "\n"; //делим на количество тестовых массивов
    std::cout << "And last sorted array>>>" << "\n";
    for (int i = 0; i < arSize; i++) { //Смотрим на последний отсортированный массив по методу 2
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Middle iterations MergeSort:" << (counterv3 / 10) << "\n"; //делим на количество тестовых массивов
    std::cout << "And last sorted array>>>" << "\n";
    for (int i = 0; i < arSize; i++) { //Смотрим на последний отсортированный массив по методу 2
        std::cout << mergearrtarget[i] << " ";
    }
    std::cout << "\n\n";
    return 0;
}