//TC: O(N), visits each char at most 2 times. SC: O(1), constant space for maps storing alphabets

#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    string minWindow(string s, string t) {
        string answer;
        int bestLen=1e5;
        pair<int, int> resultWindow = {-1,-1};
        unordered_map<char, int> tCount;
        unordered_map<char, int> windowCount;

        for(auto character:t) tCount[character]+=1;
        int required = tCount.size();
        int collected = 0;
        int left=0, right=0;

        while(right<s.size()){
            char currentChar = s[right];
            windowCount[currentChar]+=1;

            if(tCount[currentChar]>0){
                if(tCount[currentChar]==windowCount[currentChar]) collected+=1;
            }

            while(collected==required){
                int currentLen = right-left+1;
                if(currentLen < bestLen ){
                    bestLen = currentLen;
                    resultWindow.first = left;
                    resultWindow.second = right;

                    // cout << resultWindow.first << "-" << resultWindow.second <<endl;
                }

                windowCount[s[left]]-=1;
                if(tCount[s[left]]>0 && windowCount[s[left]]<tCount[s[left]]){
                    collected-=1;
                }
                left+=1;
            }

            right+=1;
        }

        if(resultWindow.first==-1 || resultWindow.second==-1) return "";
        return s.substr(resultWindow.first, resultWindow.second-resultWindow.first+1);
    }
};