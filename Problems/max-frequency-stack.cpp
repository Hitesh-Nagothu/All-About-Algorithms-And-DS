#include<bits/stdc++.h>
using namespace std;

#define heapNode pair<int, pair<int, int>>

class FreqStack {
private:
    struct heapComparator {
        bool operator()(heapNode& node1, heapNode& node2){
            if(node1.first < node2.first) return true;
            else if(node1.first==node2.first) return node1.second.first < node2.second.first;
            return false;
        }
    };
    priority_queue<heapNode, vector<heapNode>, heapComparator> pq;
    unordered_map<int, int> freq;
    int positionOrder = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
       freq[val]+=1;
       pq.push({freq[val], {positionOrder, val}});
       positionOrder+=1;
    }
    
    int pop() {
        int mostFrequentValue = pq.top().second.second;
        pq.pop();
        freq[mostFrequentValue]-=1;
        return mostFrequentValue;
    }
};

