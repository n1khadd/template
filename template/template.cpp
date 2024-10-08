#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
void fillList(T list[], int size, T minValue, T maxValue) {
    for (int i = 0; i < size; ++i) {
        list[i] = minValue + std::rand() % (maxValue - minValue + 1);
    }
}

template<typename T>
void printList(const T list[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void selectionSort(T list[], int size, bool ascending) {
    for (int i = 0; i < size - 1; ++i) {
        int extremeIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if ((ascending && list[j] < list[extremeIndex]) || (!ascending && list[j] > list[extremeIndex])) {
                extremeIndex = j;
            }
        }
        std::swap(list[i], list[extremeIndex]);
    }
}

template<typename T>
void bubbleSort(T list[], int size, bool ascending) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if ((ascending && list[j] > list[j + 1]) || (!ascending && list[j] < list[j + 1])) {
                std::swap(list[j], list[j + 1]);
            }
        }
    }
}

template<typename T>
void insertionSort(T list[], int size, bool ascending) {
    for (int i = 1; i < size; ++i) {
        T key = list[i];
        int j = i - 1;
        while (j >= 0 && ((ascending && list[j] > key) || (!ascending && list[j] < key))) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

int main() {
    std::srand(std::time(nullptr));

    const int size = 10;
    int minValue = 1;
    int maxValue = 100;
    int list[size];

    fillList(list, size, minValue, maxValue);
    std::cout << "Doldurulmuş list: ";
    printList(list, size);

    selectionSort(list, size, true);
    std::cout << "Seçim Sortu (Artan): ";
    printList(list, size);

    fillList(list, size, minValue, maxValue);
    std::cout << "Doldurulmuş list: ";
    printList(list, size);

    bubbleSort(list, size, false);
    std::cout << "Bubble Sort (Azalan): ";
    printList(list, size);

    fillList(list, size, minValue, maxValue);
    std::cout << "Doldurulmuş list: ";
    printList(list, size);

    insertionSort(list, size, true);
    std::cout << "İnsert Sort (Artan): ";
    printList(list, size);
}
