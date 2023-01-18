#include "../allheaders.h";
using namespace std;

#define INPUT_SIZE 50

/*
TIme: O(NlogN)  Could get bad as O(N^2) if choosing of partition idx value ends up being the smallest ones each time
Space: O(logN)  Could get O(N)
*/

void quickSort(vector<int>& values, int startIdx, int endIdx) {

    // Find a partition -> Compare values to the partition -> Repeat on sub problem on new partitions
    if (startIdx >= endIdx) return;

    int partitionIdx = startIdx;   //choose any mechanism -> start, end, or random idx
    int leftCursorIdx = startIdx + 1;
    int rightCursorIdx = endIdx;

    while (leftCursorIdx <= rightCursorIdx) {
        if (values[leftCursorIdx] > values[partitionIdx] && values[rightCursorIdx] < values[partitionIdx]) {
            //swap
            swap(values[leftCursorIdx], values[rightCursorIdx]);
        }
        if (values[leftCursorIdx] <= values[partitionIdx]) {
            leftCursorIdx += 1;
        }
        if (values[rightCursorIdx] >= values[partitionIdx]) {
            rightCursorIdx -= 1;
        }

    }

    //swap partitionIdx into rightIdx (partitionIdx's right place)
    swap(values[partitionIdx], values[rightCursorIdx]);

    //Split into subproblems (TODO: Few known optimizations available on choosing the partitions to start sort with. )
    quickSort(values, startIdx, rightCursorIdx - 1);
    quickSort(values, rightCursorIdx + 1, endIdx);

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
    quickSort(values, 0, values.size() - 1);

    cout << endl << "After sorting" << endl;
    for (auto x : values) {
        cout << x << " ";
    }

    return 0;
}