// LeetCode Problem Link :- https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/description/
// Author :- Jayant Paditar

class Solution {
public:
    // Create a new Function to get the slope.
    vector<int> getSlope(vector<vector<int>>& stockPrices, int i){
        // Using the formula (y2-y1), (x2-x1) for getting the 
        // numerator & denominator of the slope formula.
        return {stockPrices[i][1]-stockPrices[i-1][1], stockPrices[i][0]-stockPrices[i-1][0]};
    }

    int minimumLines(vector<vector<int>>& stocks) {
        // for single stock.
        if(stocks.size() == 1){
            return 0;
        }
        // sort the stocks
        sort(stocks.begin(), stocks.end());
        
        // get previous slope using the 0th & 1st points.
        vector<int> prevSlope = getSlope(stocks, 1);
        int ans = 1;
        // now start from 3rd index i.e i=2.
        for(int i=2;i<stocks.size();i++){
            // get the slope of 1st & 2nd index.
            vector<int> slope = getSlope(stocks, i);

            // check the equality of two slopes. If not equal then..
            if((long long int)slope[0] * prevSlope[1] != (long long int)slope[1] * prevSlope[0]){
                // update the prevSlope to current slope & 
                // increment the answer by 1.
                prevSlope = slope;
                ans++;
            }
        }
        // return answer;
        return ans;
    }
};
