/* Linear search
 * Author: Douglas Canevarollo */

#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int> &array, int target) {
    int i;

    for (i = 0; i < array.size(); i++)
        if (array[i] == target)
            return true;

    return false;
}