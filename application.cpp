#include<bits/stdc++.h> 
#include<algorithm>
using namespace std;
typedef long long ll;

class Country{
  private:
    vector<string> number;
    string name;
  public:
    Country(string name) {
        this->name = name;
    }
    
    int totalNumber(){
        return this->number.size();
    }
    
    string getName() {
        return this->name;
    }

    void pushNumber(string num) {
        this->number.push_back(num);
    }

string getFirstNumber() {
return number[0];
}
};

void getUniqueCountryNames(vector<Country> &v) {
for(int i=0;i<v.size();++i) {
cout<<v[i].getFirstNumber()<<" -> "<<v[i].getName()<<endl;
}
}

void getCountryNamesSorted(vector<Country> &v) {
map<int,string> mp;
for(int i=0;i<v.size();++i) {
mp[v[i].totalNumber()] = v[i].getName();
}
string ans="";
auto itr = mp.begin();
while(itr!=mp.end()) {
ans+=itr->second;
ans+=',';
}
ans.pop_back();
cout<<ans<<endl;
}

void getCountryHavingHighestPhoneNumber(vector<Country> &v) {
int maxi = INT_MIN;
for(int i=0;i<v.size();++i) {
maxi = max(v[i].totalNumber(),maxi);
}
for(int i=0;i<v.size();++i) {
if(v[i].totalNumber()==maxi) {
cout<<v[i].getName()<<endl;
}
}
}

int main()
{
    vector<string> allNumber;
    ifstream file("sampleInput_oct21.txt");
    string data = "";
    while(getline(file, data,','))
    {
       allnumber.push_back(data) ;
    }
    file.close();
map<string,string> countryCodeName;
    string s;
    map<string,int> countries;
    vector<Country> allCountries;
    for(int i=0;i<allNumber.size();++i) {
        string countryName;
        s="";
        s+=allNumber[1];
        s+=allNumber[2];
        if(m.find(s)!=m.end()) {
            countryName=m[s];
        }
        else {
            s+=allNumber[3];
            if(m.find(s)!=m.end()) {
                countryName=m[s];
            }
            else {
                s+=allNumber[4];
                s+=allNumber[5];
                countryName=m[s];
            }
        }
        if(countries[countryName]==0) {
            Country c(countryName);
c.pushNumber(allNumber[i]);
allCountries.push_back(c);
        }
        else {
            for(int i=0;i<allCountries.size();++i){
if(allCountries[i].getName()==countryName) {
allCountries[i].pushNumber(allNumber[i]);
break;
}
}
        }
    }
while(1) {
int choice;
cout<<"Select Operation :-" <<endl;
cout<<"1. Get all Unique Country Names "<<endl;
cout<<"2. Get Country Names sorted by their count"<<endl;
cout<<"3. Get the Country name(s) having the highest number of phone numbers"<<endl;
cin>>choice;
switch(choice) {
case 1: getUniqueCountryNames(allCountries);
break;
case 2: getCountryNamesSorted(allCountries);
break;
case 3: getCountryHavingHighestPhoneNumber(allCountries);
break;
default: exit(0);
}
}
    return 0;
}
