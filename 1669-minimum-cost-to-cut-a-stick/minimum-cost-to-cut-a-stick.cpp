class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> range = {0};
        for (int x : cuts)
            range.push_back(x);
        sort(range.begin(), range.end());
        range.push_back(n);
        vector<vector<int>> dp(range.size(), vector<int>(range.size(), -1));
        return minCostHelper(range, 0, range.size()-1, dp);
    }

    int minCostHelper(vector<int>& range, int start, int end, vector<vector<int>>& dp){
        //excludes the start and end
        if (start+1 == end){
            //there is no cut left
            return 0;
        }
        if (start+2 == end){
            //only 1 cut
            return range[end]-range[start];
        } 
        if (dp[start][end] != -1)
            return dp[start][end];
        int rslt = INT_MAX;
        for (int i=start+1; i<end; i++){
            //choose anyone in (start, end)
            rslt = min(rslt, minCostHelper(range, start, i, dp) + minCostHelper(range, i, end, dp));
        }
        return dp[start][end] = rslt + range[end]-range[start];
    }
};