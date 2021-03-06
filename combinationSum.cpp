#include<bits/stdc++.h>
using namespace std;
void findNumbers(vector<int>&ar,int sum,vector<vector<int> > &res,vector<int>r,int i){
    if(sum==0){
        res.push_back(r); return ;
    }
    while(i<ar.size() && sum - ar[i]>=0){
        r.push_back(ar[i]);
        findNumbers(ar,sum - ar[i],res,r,i); 
        i++;
        r.pop_back();
    }
    return ;
}
vector<vector<int> > combinationSum(vector<int>&ar,int sum){
    sort(ar.begin(), ar.end());
 
    // remove duplicates
    ar.erase(unique(ar.begin(), ar.end()), ar.end());
 
    vector<int> r;
    vector<vector<int> > res;
    findNumbers(ar, sum, res, r, 0);
 
    return res;
}
int main(){
    vector<int> ar;
    ar.push_back(2);
    ar.push_back(4);
    ar.push_back(6);
    ar.push_back(8);
    int n = ar.size();
    int sum = 8; // set value of sum
    vector<vector<int> > res = combinationSum(ar, sum);
    for(auto x : res){
        for(int y:x) cout << y << " "; cout << "\n"; 
    }
}