#include <array>
#include <iostream>
using namespace std;


void printArray(array<int ,12>, int size);
array <int,12> resetArray (array<int,12>&);
void bubbleSort (array <int, 12 >&,int size);
void selectionSort(array <int, 12 >&,int size);


int main() {
    array <int,12> arr = {54, 37, 81, 12, 95, 6, 23, 68, 47, 76, 29, 42};
    int size = sizeof(arr) / sizeof(arr.at(0));
    
    cout << "Array 1 Sin ordenar" << "\n" ;
    printArray(arr, size);
    
    bubbleSort(arr, size);
    cout << "Array 1 Ordenado" << "\n" ;
    printArray(arr, size);

    resetArray(arr);

    cout << "Array desordenado"<< "\n";
    printArray(arr,size);


   // selectionSort(arr, size);
    
}    


void printArray(array<int,12> arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr.at(i) << " ";
    }
    cout << endl;
}

array <int,12> resetArray (array<int,12> &arr){
    arr = {54, 37, 81, 12, 95, 6, 23, 68, 47, 76, 29, 42};
    return arr;
}

// Bubble Sort
void bubbleSort(array<int,12>& arr, int size) {
    for (int i {0}; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr.at(j) > arr.at(j+1)) {
                // Intercambiar los elementos
                int temp = arr.at(j);
                arr.at(j) = arr.at(j+1);
                arr.at(j+1) = temp;
            }
        }
    }
}


// Seleccion Sort

void selectionSort(array<int,12>& arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
