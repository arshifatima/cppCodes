#include<bits/stdc++.h>
using namespace std;
//o(N^2) approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        for(int i=0;i<n;i++) dp[i] = 1;
        //memset(dp,1,sizeof(dp));
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++) ans = max(ans,dp[i]);
        return ans;
    }
    //O(NlogN) approach
    int LIS(vector<int>& nums){
        int n = nums.size();
        int dp[n+1]; dp[0] = INT_MIN;
        for(int i=1;i<=n;i++){
            dp[i] = INT_MAX;
        }
        for(int i=0;i<n;i++){
            int idx = upper_bound(dp,dp+n+1,nums[i]) - dp;
            if(nums[i] > dp[idx-1]) dp[idx] = nums[i];
        }
        int ans = 1;
        for(int i = n;i>0;i--) if(dp[i]!=INT_MAX) {ans = dp[i]; break;}
    }
};