//* https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii
//* Brute Force (TLE)-> https://youtu.be/DREutrv2XD0
//* Optimized-> https://youtu.be/AD4SFl7tu7I

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        
        return brute_force(beginWord, endWord, wordList);
    }
    
    vector<vector<string>> brute_force(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel{beginWord};
        int level = 0;

        vector<vector<string>> ans;

        while(!q.empty()){
            vector<string> vec = q.front(); q.pop();

            if(vec.size() > level){
                level++;

                for(string s : usedOnLevel){
                    // erasing all strings used on previous level
                    st.erase(s);
                }

                usedOnLevel.clear();
            }

            // adding shortest transformations to answer
            string lastWord = vec.back();
            if(lastWord == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }

                // if size of current sequence if equal to size of first pushed sequence
                else if (ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }


            int len = lastWord.size();
            for(int i = 0; i < len; i++){
                string temp = lastWord;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp[i] = ch;

                    // if it exists in my set
                    if(st.find(temp) != st.end()){
                        
                        vec.push_back(temp);
                        q.push(vec);
                        usedOnLevel.push_back(temp);
                        vec.pop_back();
                    }
                }
            }
        }

        return ans;
    }
};