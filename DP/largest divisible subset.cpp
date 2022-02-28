#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(vector<int>a,vector<int>b){
        int as = a.size(),bs=b.size();
        return as>bs;
    }
    vector<int> largestDivisibleSubset(vector<int>&nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>dp(n);
        
        for(int i = n-1;i>=0;i--){
            // vector<int>w; w.push_back(nums[i]);
            // dp[i] = w;
            for(int j = i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(dp[j].size()>dp[i].size())
                    dp[i] = dp[j]; 
                }
            }
            dp[i].push_back(nums[i]);
        }
         
        sort(dp.begin(),dp.end(),comp);
      
        return dp[0];
    }
};