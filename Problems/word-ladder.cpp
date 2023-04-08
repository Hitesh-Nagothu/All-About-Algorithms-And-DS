//Time : Number of words * length of largest word^2 (iterate over size and copy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> seenWords;
        unordered_set<string> wordSet;
        seenWords.insert(beginWord);

        for(const auto& word: wordList) wordSet.insert(word);

        while(!q.empty()){
            int qSize = q.size();

            while(qSize>0){
                pair<string, int> currentQueueNode = q.front();
                q.pop();
                string currentWord = currentQueueNode.first;
                int currentSteps = currentQueueNode.second;

                if(currentWord==endWord) return currentSteps;

                for(int i=0; i<currentWord.size(); i++){
                    string newWord = currentWord;
                    for(char k ='a'; k <='z'; k++){
                        newWord[i]=k;

                        if(wordSet.find(newWord)!=wordSet.end() && seenWords.find(newWord)==seenWords.end()){
                            q.push({newWord, currentSteps+1});
                            seenWords.insert(newWord);
                        }
                    }
                }

                qSize-=1;
            }
        }

        return 0;
    }
};