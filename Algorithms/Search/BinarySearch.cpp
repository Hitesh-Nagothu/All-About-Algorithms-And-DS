#include "../allheaders.h"
using namespace std;

/**
 * Recursive Binary Search
 * Time: O(logN)
 * Space O(logN)
 * @param values reference array of values
 * @param size array size
 * @param target target to find in given values
 * @return 0-indexed position of the target in the array input. -1 if not found
 */
int recursiveBinarySearch(int values[], int low, int high, int target) {


    if (low > high) return -1;

    int mid = (low + high) >> 1;

    if (values[mid] == target) return mid;
    else if (values[mid] > target) return recursiveBinarySearch(values, low, mid - 1, target);
    else return recursiveBinarySearch(values, mid + 1, high, target);

}

/**
 * Iterative Binary Search
 * Time: O(logN)
 * Space O(1)
 * @param values reference array of values
 * @param size array size
 * @param target target to find in given values
 * @return 0-indexed position of the target in the array input. -1 if not found
 */
int iterativeBinarySearch(int values[], int low, int high, int target) {

    int left = low;
    int right = high;

    while (left <= right) {
        int mid = (left + right) >> 1;
        if (values[mid] == target) {
            return mid;
        }
        else if (values[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {

    //initialize
    int searchSize;
    int target;
    const int lowerBound = 0;
    const int upperBound = 1000;

    srand(time(0));

    //User input
    cout << "Enter number of values to search" << endl;
    cin >> searchSize;

    int values[searchSize];

    for (int idx = 0; idx < searchSize; idx++) {
        values[idx] = rand() % (upperBound - lowerBound + 1) + lowerBound;
    }

    sort(values, values + searchSize);

    for (auto x : values) {
        cout << x << " ";
    }

    cout << endl << "Choose a target value" << endl;
    cin >> target;

    //search Iterative
   // int targetFoundPosition = iterativeBinarySearch(values, 0, searchSize, target);

    //search recursive
    int targetFoundPosition = recursiveBinarySearch(values, 0, searchSize, target);

    //result
    cout << (targetFoundPosition == -1 ? "Not Found" : "Found at position") << targetFoundPosition + 1;  //1-indexed

    return 0;
}