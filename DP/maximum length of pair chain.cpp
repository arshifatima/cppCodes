#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
       // return a[0]<b[0];
    }
    //[1,2] , [3,4] , [3,5] 
    //to be sorted in this manner
    //here the first element of current to be greater than last element of previous 
    int findLongestChain(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),cmp);
        int n=e.size();
        vector<int> dp(n,1);
        int ans = 1;
        //LIS applied which takes here O(N^2) time 
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(e[i][0] > e[j][1] ){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
           
    }
};