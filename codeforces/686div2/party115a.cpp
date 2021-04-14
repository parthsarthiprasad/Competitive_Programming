#include<bits/stdc++.h>
using namespace std;
string weeds[150];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>weeds[i];
    vector<pair<int,int>> tmin;
    for(int i=0;i<n;i++){
        int minindex = n;
        int maxindex = -1;
        for(int j=0;j<m;j++){
            if(weeds[i][j]=='W'){
                maxindex = max(maxindex, j);
                minindex = min(minindex, j);
            }
        }
        tmin.push_back({minindex,maxindex});
    }
    int prow = 0;
    int64_t count = 0;
    bool right = true;
    int presentx = 0;
    while(prow<n){
        while(tmin[prow].first==n){
            prow++;
        }
        if(prow==n) break;
        int minindex = tmin[prow].first;
        int maxindex = tmin[prow].second;
        if(right){
            count+=abs(max(maxindex,(prow+1<n?tmin[prow+1].second:maxindex)-presentx));
            presentx = max(maxindex,(prow+1<n?tmin[prow+1].second:maxindex));
        }else{
            count+=abs(min(minindex,(prow+1<n?tmin[prow+1].first:minindex)-presentx));
             presentx = min(minindex,(prow+1<n?tmin[prow+1].first:minindex));
        }
        right = !right;
        prow++;
    }
    cout<<count<<endl;

}