#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // refer pepcoding video on youtube
    int countSubstrings(string s) {
        int cnt = 0,n=s.length();
        int dp[1001][1001] = {0},i,j;
        memset(dp,-1,sizeof(dp));
        for(int gap = 0;gap<n;gap++){
            for( i = 0,j = gap ; j < n ; i++,j++){
                if(gap==0) {dp[i][j] = 1; cnt++;}
                else if(gap==1 && s[i]==s[j]) {dp[i][j] = 1; cnt++;}
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]==1) {dp[i][j] = 1; cnt++;}
                }
        }
           
        }
        
        return cnt;
    }
};


  string longestPalindrome(string s) {
        int ans = 1,n=s.length();
        int dp[1001][1001] = {0},i,j;
        memset(dp,-1,sizeof(dp));
        for(int gap = 0;gap<n;gap++){
            for( i = 0,j = gap ; j < n ; i++,j++){
                if(gap==0) {dp[i][j] = 1; ans = max(ans,gap+1);}
                else if(gap==1 && s[i]==s[j]) {dp[i][j] = 1; ans = max(ans,gap+1);}
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]==1) {
                        dp[i][j] = 1;ans = max(ans,gap+1);
                }
        }
           
        } 
    } 
        int f = 0,st=0,e=0; 
        for(int gap = n-1;gap>=0;gap--){
            for( i = 0,j = gap ; j < n ; i++,j++){
                if(dp[i][j]==1){
                   st= i;e=j; f=1; cout << st << " " << e ;
                    break;
                }
                if(f==1) break;
            }
        }
        string t(s.begin() + st,s.begin() + e);
        return t;
    }