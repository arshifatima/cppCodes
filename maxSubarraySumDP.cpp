#include<bits/stdc++.h>
using namespace std;
int maxSum(int *a,int n){
    int dp[100] = {0};
    dp[0] = a[0]>0?a[0]:0;
    //dp[i] stores the max sum which cud be formed till i
    int max_so_far = dp[0];
    for(int i=1;i<n;i++){
        dp[i] = a[i] + dp[i-1];
        if(dp[i]<0) dp[i] = 0;
        max_so_far = max(max_so_far,dp[i]);
    }
    return max_so_far;
}
//maxSum Sapce optimised solution is KADANE'S

int main(){
    int a[] = {-3,-1,12,4,1,-20};
    int n = sizeof(a)/sizeof(a[0]);
    cout << maxSum(a,n);
}