#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll solve(){
    int n;
    cin>>n;
    map<int,int> a,b;
    map<int,int> a;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(a.find(temp) == a.end()){
            a[temp]=1;
        }
        else{
            a[temp]++;
        }
    }
    
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(b.find(temp) == b.end()){
            b[temp]=1;
        }
        else{
            b[temp]++;
        }
    }
    int sum=0;
    bool isidentical = true;
    int minelment=INT_MAX;
    map<int,int>::iterator it;
    for(it=a.begin();it!=a.end();++it){
        int temp1 = b[it->first];
        int temp2 = it->second;
        if(temp1==0 || ((temp1!=temp2) && (temp1-temp2)&1)){
            isidentical = false;
            break;
        }
        if(temp1!=temp2){
            minelment=min(minelment,it->first);
            sum+=minelment*abs((temp1-temp2)/2);
        }
    }
    if(isidentical==false){
        sum=-1;
    }
    return sum;

    
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}