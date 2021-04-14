#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
bool comp(const int &a, const int &b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int n = a;
    vector<int> s;
    int ptr[a];
    for(int i=0;i<a;i++){
        cin>>ptr[i];
        
    }
    sort(ptr,ptr+a);
    
    for(int i=n-1;i>=0 && ptr[i]>c;i--){
        s.pb(ptr[i]);
    }
    sort(s.begin(), s.end());
    int elements = (a+1)/(b+1);
    if((a+1)%(b+1)) elements++;


    ll sum =0;

    vector<int>::iterator it = s.end();
    it--;
    for(int i=s.size()-1;  i>=s.size()-1-elements && i>=0; i--){
        sum+= s[i];
    }
    cout<< sum; 
    return 0;
}