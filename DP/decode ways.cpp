#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //https://www.geeksforgeeks.org/subset-sum-problem-dp-25/?ref=gcse
    int numDecodings(string s) {
        int n = s.length();
        int dp[n+1][n+1];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            if(s[i]=='0') dp[i][i] = 0;
            else dp[i][i] = 1;
        }
        for(int i = 0,j=1;i<n-1;i++,j++){
            if(s[i]=='0') dp[i][j] = 0;
            else{
            string d = s.substr(i,2);
            int check = stoi(d);
            if(check<=26 && check>=1 && check!=10 && check!=20) dp[i][j] = 2;
            else if(check==10 || check==20)dp[i][j] = 1;
            else if(check%10 == 0) dp[i][j] = 0;
            else dp[i][j]=1;
            }   
        }
        //cout << dp[0][1] << " " << dp[1][2];
        for(int gap = 2;gap<n;gap++){
            for(int i=0,j=gap;j<n;j++,i++){
                if(s[i]=='0') dp[i][j] = 0;
                else {
                    string d = ""; d+=s[i]; d+=s[i+1];
                    int check = stoi(d);
                    if(s[i]!='0')
                    dp[i][j] = dp[i+1][j];
                    if(check<=26 && check>=1)
                    dp[i][j] += dp[i+2][j];
                }
            }
        } 
        //cout << dp[1][3] << " " << dp[2][3];
        return dp[0][n-1];
        
    }
};