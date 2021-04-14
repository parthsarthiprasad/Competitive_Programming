//dp question again
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long 

ll findans(vector<pair<int,int> > &vec, int value[], int start, int end, int n, int m){
    if(vec[n-1].first<start || vec[0].first>=end) return 0;
    ll ans=0;
    for(int k=0; vec[k].first>=start && vec[k].second<=end && k<n;k++){
        if(vec[k].first>=start && vec[k].second<=end){
            ans = max(ans, 
                  value[k] + findans(vec,value,start, vec[k].first-1,n, m)
                           + findans(vec,value, vec[k].second+1, end,n, m)
                    );
        }
    }
     return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n,a,b;
    cin>>m>>n;
    vector<pair<int,int> > vec(n);
    int value[n];
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec.pb(mp(a,b+4));
    }

    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    sort(vec.begin(), vec.end());
    cout<< findans(vec, value,0,m+4,n,m)<<endl;
    
}