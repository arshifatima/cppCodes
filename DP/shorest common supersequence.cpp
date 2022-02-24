#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(),m = str2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0) dp[i][j] = j;
                else if(j==0) dp[i][j] = i;
                else if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ans = n + m - dp[n][m];
        //char s[ans+1]; s[ans] = '\0';
        string s = "";
        int i = n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s+=str1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){s+=str2[j-1]; j--;}
            else {s+=str1[i-1]; i--;}
        }
        while (i > 0)
    {
        s+=str1[i - 1];
        i--;
    }
 
    // If X reaches its end, put remaining characters
    // of Y in the result string
    while (j > 0)
    {
        s+=str2[j - 1];
        j--;
    }
 
    // reverse the string and return it
    reverse(s.begin(), s.end());
    
        return s;
    }
};