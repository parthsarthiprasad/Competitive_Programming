#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
const int mod = 1e9+7;
const int nax = 1e5+1;
map<pair<int,int>, pair<int,int> > m;
vector<int> G[nax];
int moves = 0;
int s;
vector<int> par;
// void dfs(int src, int par, int dist = 0, int sum=0, pair<int,int> &msofar = mp(0,0)){
//     for(auto a: G[src]){
//         if()
//     }
// }
void dfs(int src, int parent){
    bool leaf = true;
    for(auto a: G[src]){
        if(a!=parent){
            leaf = false;
        }
    }
    if(leaf){
        if(par.size()<2) return ;
        if(par.size()==2){
            int v1= par[0];
            int v2 = par[1];
            int weight = m[mp(v1,v2)].first;
            int value = m[mp(v1,v2)].second;
            int num =0;
            while(weight>(s/(par.size() -1))){
                num++;
                weight/=2;
            }
            m[mp(v1,v2)] = mp(weight, value);
            m[mp(v2,v1)] = mp(weight, value);
            moves+=num;
            
            return ;
        }
        for(int i=0;i<par.size()-1;i++){
            int v1= par[i];
            int v2 = par[i+1];
            int weight = m[mp(v1,v2)].first;
            int value = m[mp(v1,v2)].second;
            int num =0;
            while(weight>(s/(par.size() -1))){
                num++;
                weight/=2;
            }
            m[mp(v1,v2)] = mp(weight, value);
            m[mp(v2,v1)] = mp(weight, value);
            moves+=num;
        }
        return;
    }
    else{
        for(auto a: G[src]){
            if(a!=parent){
                par.pb(a);
                dfs(a,src);
                par.pop_back();
            }
        }
    }
}
ll solve(){
    m.clear();
    moves=0;
    int n;
    cin>>n>>s;
    for(int i=0;i<=n;i++) G[i].clear();
    //s is the chutiya cheez
    int a1,a2,a3;
    //second pair is for weight and value
    for(int i=1;i<n;i++){
        cin>>a1>>a2>>a3;
        a1--;
        a2--;
        G[a1].pb(a2);
        G[a2].pb(a1);
        m[mp(a1,a2)] = mp(a3,1);
        m[mp(a2,a1)] = mp(a3,1);   
    }
    
    par.pb(0);
    dfs(0,-1);
    if(n&1) return moves;
    else return moves-1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}