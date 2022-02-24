#include<bits/stdc++.h>
using namespace std;
int placeQueenBoxCombination(bool box[],int n,int idx,int tnq,int qpsf,string ans){
    if(qpsf==tnq){
        //cout << ans << endl;
        return 1;
    }
    int count = 0;
    for(int i=idx;i<n;i++){
        if(!box[i]){
            box[i] = true;
            string h = to_string(i);string j = to_string(qpsf);
            count+=placeQueenBoxCombination(box,n,i+1,tnq,qpsf+1,ans+"b"+h+"q"+j);
            box[i] = false;
        } 
    }
    return count;
}
int main(){
    bool box[6];
    memset(box,false,sizeof(box));
    int tnq = 3; string ans = "";
    cout << placeQueenBoxCombination(box,6,0,tnq,0,ans);
}