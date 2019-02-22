/* The bucket sort consists in sort the original data array with a time
 * complexity class O(n), that is, linear complexity.
 * It's possible and simple. To do so, we create n buckets to an array with n elements.
 * Then, we redistribute the elements into their corresponding buckets using index = n * array[i].
 * Thus, just apply some sort algorithm on the buckets (that contains a relative small number of elements)
 * and concatenates all the buckets back in the original array. */

/* More information in https://www.geeksforgeeks.org/bucket-sort-2/ */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Generates random numbers in the interval [0, 1). */
double getRandom() {
    return double (rand()) / (double (RAND_MAX) + 1.0);
}

void bucketSort(double *array, int size) {
    int i, j, index, bucketIndex;

    /* Creates n empty buckets */
    vector<double> buckets[size];

    /* Put the array elements in their corresponding buckets. */
    for (i = 0; i < size; i++) {
        bucketIndex = static_cast<int> (size * array[i]);
        buckets[bucketIndex].push_back(array[i]);
    }

    /* Sort each bucket. */
    for (i = 0; i < size; i++)
        sort(buckets[i].begin(), buckets[i].end());

    /* Concatenates all the buckets back in the original array. */

    /* Even if we have 2 nested loops we will run through them 'size' times,
     * cause the sum of items in all buckets will be 'size'. */
    index = 0;
    for (i = 0; i < size; i++)
        for (j = 0; j < buckets[i].size(); j++)
            array[index++] = buckets[i][j];
}

int main() {
    int i, size;
    srand(static_cast<unsigned int>(clock()));

    cout << "Array size" << endl << "> ";
    cin >> size;

    double array[size];

    cout << endl << "Original array" << endl << "> ";
    for (i = 0; i < size; i++) {
        array[i] = getRandom();
        cout << array[i] << " ";
    }
    cout << endl << endl;

    bucketSort(array, size);

    cout << "Sorted array" << endl << "> ";
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl << endl;

    return 0;
}