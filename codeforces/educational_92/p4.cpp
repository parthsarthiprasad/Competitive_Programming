#include <bits/stdc++.h>
using namespace std;
#define ll int
//last=-1-> start, last=1->right, last=0->left
/*ll fn(vector<ll>& a,vector<vector<ll> > & dp,ll i, ll last, ll llen, ll k, ll n, ll z){
	if(i>=n||i<0) return 0;
	if(z<0) return 0;
	if(k==0) return a[i];
	if(dp[i][k]!=-1) return dp[i][k];
	ll op=a[i];
	ll op1=0;
	if(i>0&&llen<2)
		op1=fn(a,dp,i-1,0,llen+1,k-1,n,z-1);
	ll op2=fn(a,dp,i+1,1,0,k-1,n,z);
	op=op+max(op1,op2);
	dp[i][k]=op;
	return op;
}*/
ll fn(vector<ll>& a,map<pair<int,int>,int> & dp,ll i, ll last, ll llen, ll k, ll n, ll z){
	if(i>=n||i<0) return 0;
	if(z<0) return 0;
	if(k==0) return a[i];
	if(dp.find({i,k})!=dp.end()) return dp[{i,k}];
	ll op=a[i];
	ll op1=0;
	if(i>0&&llen<2)
		op1=fn(a,dp,i-1,0,llen+1,k-1,n,z-1);
	ll op2=fn(a,dp,i+1,1,0,k-1,n,z);
	op=op+max(op1,op2);
	dp[{i,k}]=op;
	return op;
}
int main(){
	ll tt;
	cin>>tt;
	while(tt--){
		ll n,k,z;
		cin>>n>>k>>z;
		vector<ll> a(n);
		//vector<vector<ll> > dp(n,vector<ll>(k+1,-1));
		map<pair<int,int>,int> dp;
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		ll op=fn(a,dp,0,-1,0,k,n,z);
		cout<<op<<endl;
	}
	return 0;
}