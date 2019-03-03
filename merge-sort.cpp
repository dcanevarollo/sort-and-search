/* MergeSort
 * Author: Douglas Canevarollo */

/* An O(nlog(n)) time complexity class sorting algorithm. */

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &array, int left, int middle, int right) {
    int i, j, k;
    vector<int> temp(static_cast<unsigned int> (right - left));

    i = left;
    j = middle;
    k = 0;
    while (i < middle && j < right)
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];

    while (i < middle)
        temp[k++] = array[i++];

    while (j < right)
        temp[k++] = array[j++];

    for (i = 0; i < k; i++)
        array[left+i] = temp[i];
}

void mergeSort(vector<int> &array, int left, int right) {
    if (left < right-1) {
        int middle = (left + right)/2;

        mergeSort(array, left, middle);
        mergeSort(array, middle, right);
        merge(array, left, middle, right);
    }
}
