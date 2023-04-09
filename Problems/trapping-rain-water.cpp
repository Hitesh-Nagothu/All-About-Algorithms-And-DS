#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //monotonic-decreasing
    int trap(vector<int>& height) {
        stack<int> stack; 
        int res = 0;
        for(int i=0; i < height.size(); i++){
            while(!stack.empty() && height[stack.top()] < height[i]){
                int prev_height = height[stack.top()];
                stack.pop();

                if(stack.empty()) continue; 
                int cur_height = min(height[stack.top()], height[i]) - prev_height;
                int cur_width = i - stack.top() - 1;
                res += cur_width * cur_height;        
            }
            stack.push(i);
        }
        return res;
    }
};

/*
TC: Each element in array is visited at most two times, while insertion and removal from monotonic stack. -> O(N)
SC: O(1)

*/