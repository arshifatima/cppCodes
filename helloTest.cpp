#include <bits/stdc++.h>
using namespace std;
float Round(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
int main() {
    int t; cin >> t;
    while(t--){
        float k1,k2,k3,v; cin >> k1 >> k2 >> k3 >> v;
        float res = k1*k2*k3*v;
        float ans = 100.0 / res; 
        float h =  Round(ans); 
        float dif = Round(abs(h-9.58)); 
        if(dif == 0) cout << "NO\n";
        else if(h < 9.58) cout << "YES\n";
        else cout << "NO\n";
    }
}
