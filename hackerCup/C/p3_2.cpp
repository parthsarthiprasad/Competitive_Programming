// this is second clean attempt for timber
#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
using namespace std;
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
ll solve(){
    int n;
    cin>>n;
    vector<pair<int,int> > vec(n) , ls(n), rs(n);
    map<pair<int,int>, int> lsmap , rsmap;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec[i] = mp(a,b);
        ls[i] = mp(a-b,a);
        rs[i] = mp(a,a+b);
        lsmap[rs[i]] =i;
        rsmap[ls[i]] =i;
    }
    sort(ls.begin(), ls.end(), comp);
    sort(rs.begin(), rs.end(), comp);
    for(int i=0;i<n;i++) cout<<vec[i].first<<" "<<vec[i].second<<endl;
    cout<<endl;
    for(int i=0;i<n;i++) cout<<ls[i].first<<" "<<ls[i].second<<endl;
    cout<<endl;
    for(int i=0;i<n;i++) cout<<rs[i].first<<" "<<rs[i].second<<endl;
    cout<<endl;
    cout<<"showing mapping"<<endl;
    map<pair<int,int>, int>::iterator it;
    for(it=lsmap.begin(); it!=lsmap.end(); it++){
        cout<<it->first.first<<" "<<it->first.second<<"    "<<it->second<<"\n";
    }
    cout<<endl;
    for(it=rsmap.begin(); it!=rsmap.end(); it++){
        cout<<it->first.first<<" "<<it->first.second<<"    "<<it->second<<"\n";
    }
    cout<<endl;




return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i++<<":\n";
        solve();
    }
    return 0;
}