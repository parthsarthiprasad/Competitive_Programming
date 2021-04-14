#include<bits/stdc++.h>
using namespace std;
const int nax = 1e3+1;
vector<int> G[26];
bool bfs(int src, int end){
    queue<int> q;
    q.push(src);
    bool visited[26];
    for(int i=0;i<26;i++) visited[i] = false;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        if(val==end){ return true;}
        visited[val] = true;
        for(auto a:G[val]){
            if(visited[a]==false){
                visited[a] = true;
                q.push(a);
            }
        }

    }
    return false;
}
string solve(){
    string s,t;
    cin>>s>>t;
    int m; cin>>m;
    for(int i=0;i<26;i++){
        G[i].clear();
    }
    for(int i=0;i<m;i++){
        string a;
        cin>>a;
        int A1 = a[0] - 'a';
        int A2 = a[3] - 'a';
        //cout<<A1<<" "<<A2<<endl;
        G[A1].push_back(A2);
        //G[A2].push_back(A1);
    }
    
    if(s.size()!=t.size()) return "NO";
    bool ans = true;
    for(int i=0;i<s.size();++i){
        if(ans==false) break;
        ans = ans && bfs(s[i]-'a' , t[i]-'a');
    }
    if(ans) return "YES";
    return "NO";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p;
    cin>>p;
    while(p--){
        cout<<solve()<<endl;
    }
}