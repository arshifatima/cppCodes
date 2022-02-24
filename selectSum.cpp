#include<bits/stdc++.h>
using namespace std;
void recc(int n,vector<int>v){
    if(n==0){
        for(int x:v) cout << x << " "; cout << "\n";
        return ;
    }
    for(int i=1;i<=n;i++){int x = i - 1;
        v.push_back(i);
        recc(n - i,v);
        v.pop_back();
    }
    return ;
}
int main(){
    int n; cin >> n;
    vector<int>v; v.reserve(100);
    recc(n,v);
    return 0;
}