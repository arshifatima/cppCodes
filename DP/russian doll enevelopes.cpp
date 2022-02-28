#include<bits/stdc++.h>
using namespace std;
class Solution {
    // w  to be sorted and apply LIS in h to find the max count
    
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>b[1];
    }
    int maxEnvelopes(vector<vector<int>>& e) {
     sort(e.begin(),e.end(),cmp);
        int n=e.size();
        vector<int> dp;
        //LIS applied in O(NlogN) time 
        for(int i=0;i<n;i++){
            auto it=lower_bound(dp.begin(),dp.end(),e[i][1]);
            if(it==dp.end()) dp.push_back(e[i][1]);
            else *it=e[i][1];
        }
        return dp.size();   
    }
};