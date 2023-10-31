//* https://leetcode.com/problems/word-ladder/
//* https://youtu.be/tRPda0rcf8E

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return ladderLength_util(beginWord, endWord, wordList);
    }

    int ladderLength_util(string beginWord, string endWord, vector<string> wordList){

        // copying list into a set
        unordered_set<string> wList(wordList.begin(), wordList.end());

        // {word, steps}
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto curr = q.front(); q.pop();
            string currWord = curr.first;
            int steps = curr.second;

            // return steps, as soon as endWord reached
            if(currWord == endWord){
                return steps;
            }

            int len = currWord.size();
            for(int i = 0; i < len; i++){
                string temp = currWord;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp[i] = ch;

                    // if it exists in my set
                    if(wList.find(temp) != wList.end()){
                        wList.erase(temp);
                        q.push({temp, steps + 1});
                    }
                }
            }
        }

        return 0;
    }
};