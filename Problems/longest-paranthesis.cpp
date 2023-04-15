#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
    int n = s.length(),len =0,maxlen =0;
    stack<int> st;
    st.push(-1);
    for(int i =0;i<n;i++)
    {
        if(s[i] == '(')
            st.push(i);
        if(s[i] == ')')
        {
            st.pop();
            if(st.empty())
                st.push(i);
            len = i - st.top();
            maxlen = max(maxlen,len);
        }
    }
    return maxlen;
    }
};