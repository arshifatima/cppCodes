#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    //https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/?ref=gcse
    int countSubstrings(string s,int dp[1005][1005]) {
        int cnt = 0,n=s.length();
        int i,j;
        //memset(dp,-1,sizeof(dp));
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
    string longestPalindrome(string s) {
        int dp[1005][1005] = {0},n = s.length();
        countSubstrings(s,dp);
        int maxLen = 1,start=0,end=0,i,j;
        //check for len 2
        for(int i=0;i<n-1;i++){
            if(dp[i][i+1]==1){
                start = i,end = i+1; break;
            }
        }
        for(int gap = 2;gap<n;gap++){
            for(i=0,j=gap;j<n;j++,i++){
                if(dp[i][j]==1){ 
                    start = i; end = j;
                    maxLen = max(maxLen,(end - start+1));
                }
            }
        }//cout << start << " " << end;
        maxLen = end - start + 1;
        string st = s.substr(start,maxLen);
        return st;
    }
};