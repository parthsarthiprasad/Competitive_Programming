#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        vector<int> minarr(n,0), maxarr(n,0);
        minarr[0] = vec[0];
        maxarr[0] = vec[0];
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(i+1);
        }
        s.erase(vec[0]);
        for(int i=1;i<n;i++){
            if(vec[i]!=vec[i-1]){
                minarr[i]=vec[i];
                maxarr[i]=vec[i];
                s.erase(vec[i]);
            }
        }
        set<int,greater<int>> stemp(s.begin(),s.end());
        for(int i=0;i<n;i++){
            if(minarr[i]==0){
                minarr[i] = *s.begin();
                s.erase(s.begin());
                auto val = stemp.lower_bound(vec[i]);
                maxarr[i] = *val;
                stemp.erase(val);
            }
        }
        for(auto a:minarr){
            cout<<a<<" ";
        }
        cout<<endl;
         for(auto a:maxarr){
            cout<<a<<" ";
        }
        cout<<endl;


    }
}