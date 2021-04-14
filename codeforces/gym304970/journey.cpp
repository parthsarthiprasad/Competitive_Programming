#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5+1;
vector<pair<int,int>> G[nax];

int dfs(int src, vector<int> &answer, int parent = -1){
    int prod = 1;
    for(auto a:G[src]){
         prod*=a.second;
        if(a.first!=parent){
            dfs(a.first, answer, src);
        }
    }

    if(prod && parent!=-1){
        answer.push_back(src+1);
        return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)G[i].clear();
    int parent = -1;
    for(int i=0;i<n;i++){
        int p,q;
        cin>>p>>q;
        if(p!=-1){
        G[i].push_back({p-1,q});
        G[p-1].push_back({i,q});
        }else{
            parent = i;
        }
    }

    vector<int> answer;
    dfs(parent,answer);
    sort(answer.begin(), answer.end());
    if(answer.size()==0){
      cout<<-1<<endl;
    }
    for(auto a:answer){
        cout<<a<<"\n";

    }
    return 0;

}