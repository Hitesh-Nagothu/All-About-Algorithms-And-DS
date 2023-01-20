#include "../allheaders.h"
using namespace std;

#define INPUT_SIZE 50

/*
Time : O(NlogN)
Space : O(1)  //in place sorting
*/

void siftDown(int startIdx, int endIdx, vector<int>& heap) {
    int leftChildIdx = startIdx * 2 + 1;
    //out of bound check
    while (leftChildIdx <= endIdx) {
        int rightChildIdx = startIdx * 2 + 2;
        if (rightChildIdx > endIdx) {
            rightChildIdx = -1;
        }

        int childIdxToSwap;
        if (rightChildIdx != -1 && heap[rightChildIdx] > heap[leftChildIdx]) {
            childIdxToSwap = rightChildIdx;
        }
        else {
            childIdxToSwap = leftChildIdx;
        }

        if (heap[childIdxToSwap] > heap[startIdx]) {
            //swap child to parent
            swap(heap[childIdxToSwap], heap[startIdx]);
            startIdx = childIdxToSwap;
            leftChildIdx = 2 * startIdx + 1;
        }
        else {
            //parent remains at same idx
            return;
        }
    }
}

void buildMaxHeap(vector<int>& values) {
    int parentIdx = (values.size() - 2) >> 1;
    for (int idx = parentIdx; idx >= 0; idx -= 1) {
        siftDown(idx, values.size() - 1, values);
    }
}

vector<int> heapSort(vector<int> array) {

    buildMaxHeap(array);
    for (int idx = array.size() - 1; idx >= 0; idx--) {
        swap(array[0], array[idx]);
        siftDown(0, idx - 1, array);

    }

    return array;
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
    vector<int> sorted = heapSort(values);

    cout << endl << "After sorting" << endl;
    for (auto x : sorted) {
        cout << x << " ";
    }

    return 0;
}