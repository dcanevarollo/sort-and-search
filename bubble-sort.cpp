/* BubbleSort
 * Author: Douglas Canevarollo */

/* A O(n²) time complexity class sorting algorithm. */

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &array) {
    int i, j, size, temp;

    size = array.size();
    for (i = 0; i < size; i++)
        for (j = size - 1; j > i; j--)
            if (array[j-1] > array[j]) {
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
}