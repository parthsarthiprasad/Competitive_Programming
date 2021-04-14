#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>vec(n+1);
        rep(i,0,n+1){
            int temp;
            cin>>temp;
            vec[i] = {temp,i};
        }
        sort(vec.begin(),vec.end());
        if(n==2){
        cout<<vec[0].second<<" "<<vec[0].first<<" "<<vec[2].second<<" "<<k-vec[0].first<<"\n";
        cout<<vec[1].second<<" "<<vec[1].first<<" "<<vec[2].second<<" "<<k-vec[1].first<<"\n";
        continue;
        }

        for(int i=n;i>0;i--){
        cout<<vec[i].second<<" "<<min(k,vec[i].first)<<" "<<vec[i-1].second<<" "<<k-min(k,vec[i].first)<<"\n";
        vec[i-1].first-=(k-min(k,vec[i].first));
        }
        
    }
    return 0;
}