#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t(s.begin(),s.end());
        reverse(t.begin(),t.end());
        int n = s.length(),m=t.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j] = 0;
                else if(s[i-1]==t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
    //equivalent to LCS(s,t) where t is reverse of s
    int minDeletionsToMakePalindrome(string s, int n) { 
        
        string t(s.begin(),s.end());
        reverse(t.begin(),t.end());
        int m=t.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j] = 0;
                else if(s[i-1]==t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return n - dp[n][m];
     
} 
};