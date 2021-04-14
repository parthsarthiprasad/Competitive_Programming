#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5+1;
const int mod = 1e9+7;
#define ll long long 
#define pb push_back
#define mp make_pair
ll solve(){
    int n, temp;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>temp;
        m[temp]++;
    }
    map<int,int>::iterator it;
    int msize = 0;
    for(it = m.begin(); it!=m.end(); it++){
        msize = max(msize, it->second);
    }
    int msizecount = 0;
    for(it = m.begin(); it!=m.end(); it++){
        if(it->second == msize) msizecount++;
    }
    //cout<<msizecount<<endl;
    int numref = n - msize;
    int ans ;
    ans = numref/msize;
    if(msizecount==1)
        msize--;
    
    // if(msize!=1 && ){
    //     //ans++;
    // }
    return ans;
    
    
    // //vector<int> vec(msize,0);
    // int vec[msize] = {0};
    // it=m.begin();
    // int start=0;
    // while(it!=m.end()){
    //     int val = it->second;
    //     while(val--){
    //     vec[start]++;
    //     start++;
    //     if(start>=msize) start-=msize;
    //     }
    //     it++;
    // }
    // int minval = INT_MAX;
    // if(msizecount=1){ }
    // else msize--;
    // // for(int i=0;i<msize; i++){
    // //     cout<<vec[i]<<" ";
    // // }
    // cout<<endl;
    // for(int i=0;i<msize;i++){
    //     minval = min(minval, vec[i]);
    // }
    // return minval;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}