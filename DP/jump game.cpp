#include<bits/stdc++.h>
using namespace std;


class Solution {
    int fun(vector<int>&nums,int n, vector<int>&dp, int i)
    {
        if(i >= n-1)
        return 0;
        if(nums[i] == 0)
        return 1e9+7;
        if(dp[i] != -1)
        return dp[i];
        int a= 1e9+7;
        for(int k=i+1; k<=i+nums[i]; k++)
        a = min(a, 1+fun(nums,n,dp,k));
        
        return dp[i] = a;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
          vector<int>dp(n+1, -1);
        return fun(nums,n,dp,0);
        
    }
};