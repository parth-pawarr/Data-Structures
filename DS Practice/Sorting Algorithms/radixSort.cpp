#include <iostream>
#include <cmath>
using namespace std;

void countingSort(float arr[], int n, int exp) {
    float output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[int(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[int(arr[i] / exp) % 10] - 1] = arr[i];
        count[int(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(float arr[], int n) {
    float maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    for (int exp = 1; maxVal / exp > 1; exp *= 10) {
        countingSort(arr, n, exp);
    }
}
