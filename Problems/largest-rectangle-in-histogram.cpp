#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {

		stack<int> st; 
		int ans=0; 
		for(int i=0;i<heights.size();i++)
		{
			while(!st.empty() && heights[i]<heights[st.top()])
			{
				int curIDX=st.top();
				st.pop();
				int left=st.empty() ? 0:st.top()+1;
				int res=heights[curIDX]*(i-1-left+1);  //right-left+1
				ans=max(ans,res);
			}
			st.push(i);
		}

		while(!st.empty())
		{
			int curIDX=st.top();
			st.pop();
			int left=st.empty() ? 0:st.top()+1;
			int res=heights[curIDX]*(heights.size()-1-left+1);
			ans=max(ans,res);
		}

		return ans;

	}
};