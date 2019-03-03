/* InsertionSort
 * Author: Douglas Canevarollo */

/* An O(n²) time complexity class sorting algorithm.
 * Note: for already asc ordered arrays this algorithm becomes an O(n). */

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &array) {
    int i, j, key;

    for (i = 1; i < array.size(); i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = key;
    }
}