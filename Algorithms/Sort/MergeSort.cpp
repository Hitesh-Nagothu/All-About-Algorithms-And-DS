#include "../allheaders.h"
using namespace std;

#define INPUT_SIZE 50

/*
Time: O(NlogN)
Space: O(N) Extra space on creating merged arrays
*/

vector<int> mergeArrays(vector<int> arrayOne, vector<int> arrayTwo) {

    vector<int> sortedArray(arrayOne.size() + arrayTwo.size(), 0);

    int arrayOneIdx = 0;
    int arrayTwoIdx = 0;
    int sortedArrayIdx = 0;

    while (arrayOneIdx < arrayOne.size() && arrayTwoIdx < arrayTwo.size()) {
        if (arrayOne[arrayOneIdx] <= arrayTwo[arrayTwoIdx]) {
            sortedArray[sortedArrayIdx++] = arrayOne[arrayOneIdx++];
        }
        else {
            sortedArray[sortedArrayIdx++] = arrayTwo[arrayTwoIdx++];
        }
    }

    while (arrayOneIdx < arrayOne.size()) {
        sortedArray[sortedArrayIdx++] = arrayOne[arrayOneIdx++];
    }

    while (arrayTwoIdx < arrayTwo.size()) {
        sortedArray[sortedArrayIdx++] = arrayTwo[arrayTwoIdx++];
    }

    return sortedArray;
}

vector<int> mergeSort(vector<int> array) {

    if (array.size() <= 1) return array;

    int mid = array.size() >> 1;
    vector<int> leftSubProblem = vector<int>(array.begin(), array.begin() + mid);
    vector<int> rightSubProblem = vector<int>(array.begin() + mid, array.end());

    return mergeArrays(mergeSort(leftSubProblem), mergeSort(rightSubProblem));
}

int main() {

    const int lowerBound = -1000;
    const int upperBound = 1000;
    vector<int> values(INPUT_SIZE);

    //seed for random generator
    srand(time(0));

    for (int idx = 0; idx < INPUT_SIZE; idx++) {
        values[idx] = rand() % (upperBound - lowerBound + 1) + lowerBound;
    }

    cout << "Input Array Before sorting" << endl;
    for (auto x : values) {
        cout << x << " ";
    }
    cout << endl;

    //sort values
    vector<int> sorted = mergeSort(values);

    cout << endl << "After sorting" << endl;
    for (auto x : sorted) {
        cout << x << " ";
    }

    return 0;
}