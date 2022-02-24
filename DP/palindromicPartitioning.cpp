
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[2002][2002];
    int isPalindrome(string s,int i,int j){
        int k = i,l = j;
        while(l>k){
            if(s[k]!=s[l]) return false;
            k++;l--;
        }
        return true;
    }
    int solve(string s,int i,int j){
        int left,right;
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn = INT_MAX;
        for(int k = i;k<=j-1;k++){
            if(dp[i][k]!=-1) left = dp[i][k];
            else{
                left = solve(s,i,k);
                dp[i][k] = left;
                 }
            if(dp[k+1][j]!=-1) right = dp[k+1][j];
            else{
                right = solve(s,k+1,j);
                dp[k+1][j] = right;
            }
            int temp = 1 + left + right;
            mn = min(mn,temp);
        }
        return dp[i][j] = mn;
    }
    int minCut(string s) {
        int n = s.length();
        int i=0,j=n-1;
        memset(dp,-1,sizeof(dp));
        return solve(s,i,j);
    }
};