/* QuickSort
 * Author: Douglas Canevarollo */

/* An O(nlog(n)) time complexity class sorting algorithm. */

#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &array, int left, int right) {
    int i, j, pivot, temp;

    i = left;
    j = right;
    pivot = array[right];
    do {
        while (array[i] < pivot)
            i++;

        while (array[j] > pivot)
            j--;

        if(i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            i++;
            j--;
        }
    } while (i < j);

    if(left < j)
        quickSort(array, left, j);

    if(right > i)
        quickSort(array, i, right);
}