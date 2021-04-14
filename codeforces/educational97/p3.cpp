#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
const int N = 201;
int ptr[N];
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        forn(i,n){cin>>ptr[i];}
        sort(ptr,ptr+n);
        int count = 0;
        vector<pair<int,int>> segments;
        for(int i=0;i<n-1;){
            int count = 0;
            int j= i;
            while(j<n && ptr[i]==ptr[j]){
                j++;
                count++;
            }
            if(count>1){
                segments.push_back({ptr[i],count});
            }
            i = j;  
        }
        for(auto a:segments){
        cout<<a.first<<" "<<a.second<<endl;
    }

    }
    
}
