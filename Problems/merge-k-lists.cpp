#include<bits/stdc++.h>
using namespace std;

class Solution {
private:

    struct ListNodeComparator {
       bool operator()(ListNode* node1, ListNode* node2){
            if(node1->val>node2->val) return true;
            return false;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> pq;
       ListNode dummy(0); //dummy head for result list
       ListNode* iterator = &dummy;

       for(auto node: lists){
           if(node) {  // added to avoid inserting nullptr into the priority_queue
               pq.push(node);
           }
       }

       while(!pq.empty()){
           auto current = pq.top();
           pq.pop();

           if(current->next!=nullptr) pq.push(current->next);

           iterator->next=current;
           iterator=iterator->next;
       } 
       
       return dummy.next;
    }
};

/*
TC: O(k) to form heap, number of nodes * logK for each pop to get min
SC: O(k) for heap 
*/