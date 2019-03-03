/* Binary search
 * Author: Douglas Canevarollo */

#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int> &array, int target) {
    int left, middle, right;

    left = 0;
    right = array.size() - 1;
    while (left <= right) {
        middle = (left + right)/2;

        if(array[middle] == target)
            return true;

        if (array[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return false;
}