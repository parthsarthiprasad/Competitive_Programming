#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5+1;
const long int INF = 1e17;
vector<int> G[nax];
unordered_map<pair<int,int>,int> mp;
int main(){
    ios_base::sync_with_stdio(false);
    int n,m,a,b,w;
    cin>>n>>m;
    for(int i=0;i<n;i++) G[i].clear();
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        mp[{a,b}] = w;
        mp[{b,a}] = w;
    }

    vector<pair<long long int,int>> weights(n,{INF,-1});
    priority_queue<      pair<long long int,int >,
                  vector<pair<long long int,int>>,
                  greater<pair<long long int,int>>> pq;
    weights[0] = {0,-1};
    pq.push({0,0});
    while(!pq.empty()){
        pair<long long int,int> temp = pq.top();
        pq.pop();
        for(auto a:G[temp.second]){
            if(weights[a].first > weights[temp.second].first + mp[{temp.second,a}]){
                weights[a].first = weights[temp.second] + mp[{temp.second,a}];
                weights[a].second = temp.first;
                pq.push({weights[a].first,a});
            }
        }
    }

    vector<int> answer;
    int i = n-1;
    while(i>=0){
        answer.push_back(i);
        i = weights[i].second;
    }
    reverse(answer.begin(), answer.end());
    for(auto a:answer){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}