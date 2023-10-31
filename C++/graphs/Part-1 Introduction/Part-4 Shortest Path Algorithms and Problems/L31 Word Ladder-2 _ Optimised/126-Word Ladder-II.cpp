//* https://leetcode.com/problems/word-ladder-ii/
//* Brute Force (TLE)-> https://youtu.be/DREutrv2XD0
//* Optimized-> https://youtu.be/AD4SFl7tu7I


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        // return brute_force(beginWord, endWord, wordList);

        Optimised obj;
        return obj.optimised_approach(beginWord, endWord, wordList);
    }

    //* Brute force gives TLE
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

    
    //* Optimised Approach
    class Optimised{
        vector<vector<string>> ans; // storing the answer, that is set of valid sequences
        unordered_map<string, int> mpp; // word->level, tells on which level will the word comes after the transformation
        string b; // contains beginWord
    private:
        void dfs(string word, vector<string>& seq){
            
            if(word == b){
                reverse(seq.begin(), seq.end());
                ans.push_back(seq);
                reverse(seq.begin(), seq.end());
                return;
            }

            int sz = word.size();
            int steps = mpp[word];

            for(int i = 0; i < sz; i++){
                string temp = word;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp[i] = ch;

                    if(mpp.find(temp) != mpp.end() && (mpp[temp] + 1 == steps)){
                        
                        seq.push_back(temp);
                        dfs(temp, seq);
                        seq.pop_back();
                    }
                }
            }

        }
    public:
        vector<vector<string>> optimised_approach(string beginWord, string endWord, vector<string>& wordList){
            unordered_set<string> st(wordList.begin(), wordList.end());
            
            b = beginWord;
            queue<string> q;
            q.push({beginWord});
            
            mpp[beginWord] = 1; // level 1
            int sz = beginWord.size();
            st.erase(beginWord);

            while(!q.empty()){
                string word = q.front();
                q.pop();
                int steps = mpp[word];

                // break out when we reaches the end point
                if(word == endWord){
                    break;
                }

                for(int i = 0; i < sz; i++){
                    string temp = word;
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        temp[i] = ch;
    
                        // if it exists in my set
                        if(st.find(temp) != st.end()){
                            
                            q.push(temp);
                            st.erase(temp);
    
                            mpp[temp] = steps + 1;
                        }
                    }
                }
            }

            if(mpp.find(endWord) != mpp.end()){
                vector<string> seq;
                seq.push_back(endWord);
                dfs(endWord, seq);
            }

            return ans;
        }
    };
};