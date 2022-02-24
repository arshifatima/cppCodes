

//  #Inserion = #Deletion = len(S) - LPS;
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length(),m=n;
        string t = s;
        reverse(t.begin(),t.end());
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j]=0;
                else if(s[i-1]==t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int v = 2*n - dp[n][m];
        return v - n;
    }
};