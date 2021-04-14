#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
struct points{
    int l;
    int r;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<points> vec(n);
        rep(i,0,n){
            cin>>vec[i].l;
            cin>>vec[i].r;
        }
        sort(vec.begin(), vec.end(),[&](points &a, points &b){
            if(a.l==b.l) return a.r < b.r;
            return a.l<b.l;
        });
        vector<int> starts(n);
        vector<int> ends(n);
        rep(i,0,n){
            starts[i] = vec[i].l;
        }
        rep(i,0,n){
            ends[i] = vec[i].r;
        }
        int minreductions = n-1;
        for(int i=0;i<n;i++){
    
            //selection of ith as center
            int tend1 = (int)(lower_bound(starts.begin(), starts.end(),vec[i].r) - starts.begin());
            int tend2 =(int) (upper_bound(starts.begin(), starts.end(),vec[i].r) - starts.begin());
            int tstart1 = (int) (lower_bound(ends.begin(), ends.end(),vec[i].l) - ends.begin());
            int tstart2 = (int)(lower_bound(ends.begin(), ends.end(),vec[i].l) - ends.begin());

            if(tend2!=n && starts[tend2]!=vec[i].r) tend2--;
            if(ends[tstart1]!=vec[i].l) tstart1++;
            // cout<<tend2 - tstart1<<endl;
            minreductions = min(minreductions, n - (tend2 - tstart1));
        
        }
        cout<<minreductions<<"\n";
        
    }
    return 0;
}