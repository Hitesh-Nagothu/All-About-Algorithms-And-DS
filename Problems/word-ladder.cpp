//Time : Number of words * length of largest word^2 (iterate over size and copy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(!wordSet.count(endWord))return false;
        
        wordSet.erase(beginWord);

        while(!q.empty()){
            int qSize = q.size();

            while(qSize--){
                auto currentQueueNode = q.front();
                q.pop();
                string currentWord = currentQueueNode.first;
                int currentSteps = currentQueueNode.second;

                if(currentWord==endWord) return currentSteps;

                for(int i=0; i<currentWord.size(); i++){
                    string newWord = currentWord;
                    for(char k ='a'; k <='z'; k++){
                        newWord[i]=k;

                        if(wordSet.find(newWord)!=wordSet.end()){
                            q.push({newWord, currentSteps+1});
                            wordSet.erase(newWord);
                        }
                    }
                }

            }
        }

        return 0;
    }
};