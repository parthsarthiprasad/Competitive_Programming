#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
//#define for(a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define pll pair<long, long>

vector<ll> primeFactors(ll n) 
{   
    vector<ll> factors;
	// Print the number of 2s that divide n 
	while (n % 2 == 0) 
	{ 
		factors.push_back(2);
		n = n/2; 
	} 

	for (ll i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		
		while (n % i == 0) 
		{ 
			factors.push_back(i);
			n = n/i; 
		} 
	} 

	if (n > 2) 
		factors.push_back(n);
    return factors;
} 

void solve(){
    ll k;
    cin>>k;
    //constuction of string
    // vector<int> vec(10,0);
    // for(int i=0;i<10;i++)
    //     vec[i]=0;
    ll temp=k;
    string s="codeforces";
    vector<ll> fact = primeFactors(k);
    vector<ll>::iterator it=fact.begin();
    // for(it=fact.begin(); it!=fact.end(); ++it)
    //     cout<<*it<<endl;
    while(fact.size()>10){
        fact[1]=fact[1]*fact[0];
        fact.erase(fact.begin());
        sort(fact.begin(),fact.end());
        //cout<<fact.size()<<endl;
    }
    // for(it=fact.begin(); it!=fact.end(); ++it)
    //     cout<<*it<<endl;
    for(int i=0;i<10;i++){
        if(i>=fact.size()){
            cout<<s[i];
            continue;
        }
       for(int j=0;j<fact[i];j++)
        cout<<s[i];
    }
    cout<<endl;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}