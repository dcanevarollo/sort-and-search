/* CountingSort
 * Author: Douglas Canevarollo */

/* The CountSort is a linear time complexity sorting algorithm, like BucketSort. Its complexity class
 * is O(n+k), where n is the number of elements in the input array and k is range of the input (in our case, 255).
 * The idea here is similar to hash: we apply some math (O(1)) on our input array elements to define at which position
 * of the output array this element will be. */

/* More information in: https://www.geeksforgeeks.org/counting-sort/ */

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

#define range 255

int getRandom() {
    return 1 + (rand() % static_cast<int> (100));
}

void countSort(vector<int> &array) {
    int i;
    /* The two help arrays are the output (that will be copied to the original array)
     * and the counter range that stores the count of elements in a certain position. */
    vector<int> output(array.size()), counter(range);

    /* Initializes the count array with the occurrences of each element in the entry array.
     * For instance, if the element 4 appears 3 times on our input, the count array at
     * position 4 should store the value 3. */
    for (i = 0; i < array.size(); i++)
        counter[array[i]]++;

    /* Here we modify the count array such that each element at each index
     * stores the sum of previous counts. This will be the real element position
     * on the output array. */
    for (i = 1; i < counter.size(); i++)
        counter[i] += counter[i-1];

    /* Constructs the output sorted array. To do that (it's a little confusing), we get the counter array
     * at original array value - 1 position as the index of the output array. That entry on the output
     * array will store the original array value. */
    for (i = array.size() - 1; i >= 0; i--) {
        output[counter[array[i]]-1] = array[i];
        counter[array[i]]--;
    }

    /* Copies the output array to the input array. */
    for (i = 0; i < array.size(); i++)
        array[i] = output[i];
}

int main() {
    int i, size;
    srand(static_cast<unsigned int> (clock()));

    cout << "Array size" << endl << "> ";
    cin >> size;

    vector<int> array(static_cast<unsigned int> (size));

    cout << endl << "Original array" << endl << "> ";
    for (i = 0; i < array.size(); i++) {
        array[i] = getRandom();
        cout << array[i] << " ";
    }
    cout << endl << endl;

    countSort(array);

    cout << "Sorted array" << endl << "> ";
    for (int value : array)
        cout << value << " ";
    cout << endl << endl;

    return 0;
}
