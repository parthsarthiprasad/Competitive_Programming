#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, begin, end) for(__typeof(end) i=begin; i<end; i++)
#define per(i, begin, end) for(__typeof(end) i=begin; i>=end; i--)

const int nax=1e5+5;
vector<int> g[nax];
vector<int> dp(nax), topo, vis(nax);
 
void dfs(int u){
	vis[u] = 1;
	for(int v:g[u])	if(!vis[v])
		dfs(v);
	topo.pb(u);
}
 
int main()
{
	#include<bits/stdc++.h>
    using namespace std;
    
	int n, m, u, v;
	cin >> n >> m;
	rep(i, 0, m){
		cin >> u >> v;
		g[u].pb(v);
	}
	for(int i=1; i<=n; i++)	if(!vis[i])
		dfs(i);
	reverse(topo.begin(), topo.end());
	for(auto u:topo){
		for(int v:g[u])
			dp[v] = max(dp[v], 1+dp[u]);
	}
	printf("%d\n", *max_element(dp.begin(), dp.end()));
}
 