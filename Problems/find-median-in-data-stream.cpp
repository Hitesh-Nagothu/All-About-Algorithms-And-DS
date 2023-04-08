//TC : (number of operations) * LogN, SC: (size of two heaps)

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    priority_queue<int> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        this->maxHeap.push(num);

        //balance
        this->minHeap.push(this->maxHeap.top());
        this->maxHeap.pop();

        if(this->maxHeap.size()<this->minHeap.size()){
            //need to always keep the maxHeap size equal or greater than what minHeap has
            this->maxHeap.push(this->minHeap.top());
            this->minHeap.pop();
        }
    }
    
    double findMedian() {
        if(this->minHeap.size()==this->maxHeap.size()){
            return (double)(this->minHeap.top()+this->maxHeap.top())/2.0;
        }
        return this->maxHeap.top();
    }
};