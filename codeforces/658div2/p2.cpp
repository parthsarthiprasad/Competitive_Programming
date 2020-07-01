#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
void solve(){
        ll num1=0;
		ll n;
		cin>>n;
		bool ispossible=true;
		for(ll i=0;i<n;i++){
			ll x;
			cin>>x;
			if(ispossible&&x==1){
				num1++;
			}
			if(x!=1){
				ispossible=false;
			}
		}
		if(n==1){
			cout<<"First"<<endl;
		}
		else if(num1==n){
			if(n&1){
                //n is odd
				cout<<"First"<<endl;
			}
			else{
				cout<<"Second"<<endl;
			}
		}
		else{
			if(num1&1){
				cout<<"Second"<<endl;
			}
			else{
				cout<<"First"<<endl;
			}
		}
}
int main(){
	ll t;
	cin>>t;
	while(t--){
        solve();	
	}
	return 0;
}