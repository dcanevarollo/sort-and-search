/* SelectionSort
 * Author: Douglas Canevarollo */

/* An O(n²) time complexity class sorting algorithm. */

#include <iostream>
#include <vector>
using namespace std;

void selectionSott(vector<int> &array) {
    int i, j, size, smallest, index;
    bool swap;

    size = array.size();
    for (i = 0; i < size - 1; i++) {
        smallest = array[i];
        index = i;
        swap = false;

        for (j = i + 1; j < size; j++)
            if(array[j] < smallest) {
                smallest = array[j];
                index = j;
                swap = true;
            }

        if (swap) {
            array[index] = array[i];
            array[i] = smallest;
        }
    }
}