#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define ll long long int 
const int nax = 2e5+5;
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int wire[6];
    forn(i,6)cin>>wire[i];
    sort(wire,wire+6);
    int n;
    cin>>n;
    vector<int> vec(n);
    forn(i,n)cin>>vec[i];
    sort(vec.begin(), vec.end());
    int maxfret = INT_MAX;
    int minfret = 0;
    minfret = vec[0] - wire[0];
    maxfret = minfret;
    forn(i,n){
        int diff = INT_MAX;
        forn(j,6){
            if(vec[i]-wire[j]>=minfret)
            diff = min(diff,(vec[i]-wire[j]));
        }
        if(diff==INT_MAX){
            forn(j,6){
            diff = min(diff,(vec[i]-wire[j]));
            }
        minfret = diff;
        }
        maxfret = max(maxfret,diff);

    }
    // forn(i,6)cout<<wire[i]<<" ";
    // cout<<endl;
    // forn(i,n)cout<<vec[i]<<" ";
    // cout<<endl;
    cout<<maxfret-minfret<<endl;


    return 0;
}