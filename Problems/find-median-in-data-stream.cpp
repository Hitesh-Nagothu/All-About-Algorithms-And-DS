//TC : (number of operations) * LogN, SC: (size of two heaps)

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

         maxHeap.push(num);

        //balance
         minHeap.push( maxHeap.top());
         maxHeap.pop();

        if( maxHeap.size()< minHeap.size()){
            //need to always keep the maxHeap size equal or greater than what minHeap has
             maxHeap.push( minHeap.top());
             minHeap.pop();
        }
    }
    
    double findMedian() {
        if( minHeap.size()== maxHeap.size()){
            return (double)( minHeap.top()+ maxHeap.top())/2.0;
        }
        return  maxHeap.top();
    }
};