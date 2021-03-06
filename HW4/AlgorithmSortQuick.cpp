#include "AlgorithmSortQuick.h"

AlgorithmSortQuick::AlgorithmSortQuick(int k) : SelectionAlgorithm(k) {
    cin >> N;
    arr = new int[N];
}

AlgorithmSortQuick::~AlgorithmSortQuick() {
    delete arr;
}

int AlgorithmSortQuick::select() {
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    return quickselect(arr, 0, N - 1, k);
}

int AlgorithmSortQuick::quickselect(int *arr, int left, int right, int k) {
    if (left + 10 <= right) {
        int pivot = median(arr, left, right);
        int i = left;
        int j = right - 1;

        while (true) {
            for (; arr[++i] < pivot;);
            for (; pivot < arr[--j];);
            if (i < j)
                swap(arr[i], arr[j]);
            else break;
        }
        swap(arr[i], arr[right - 1]); //restore the pivot.
        return (k <= i - 1) ? quickselect(arr, left, i - 1, k) : ((k == i) ? pivot : quickselect(arr, i + 1, right, k));
    } else
        insertionSort(arr, left, right);
    return arr[k];

}

int AlgorithmSortQuick::median(int *arr, int left, int right) {
    int center = (left + right) / 2;
    if (arr[center] < arr[left])
        swap(arr[left], arr[center]);
    if (arr[right] < arr[left])
        swap(arr[right], arr[left]);
    if (arr[right] < arr[center])
        swap(arr[center], arr[right]);

    swap(arr[center], arr[right - 1]);
    return arr[right - 1];
}

void AlgorithmSortQuick::insertionSort(int *arr, int left, int right) {
    for (int i = left + 1; i < right + 1; i++) {
        int j = i - 1;
        int key = arr[i];

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
