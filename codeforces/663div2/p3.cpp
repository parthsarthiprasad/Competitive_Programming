#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
#define ll long long 

#define forn(i,a,b) for(int i=a;i<=b;i++)
int solve(){
    int n;
    cin>>n;
    n%=m;
    if(n<0) return 0;
    switch(n){
        case 3: return 2;
        case 4: return 16;
    }
	
	ll curr=16;
	ll prev=16;
	ll factn1=24;
    forn(i,5,n){
        long long factn=(factn1*i)%m;
		curr=(((factn1*i))+(prev%m)-(factn1%m)+(prev%m)-(factn1%m))%m;
		factn1=factn;
		prev=curr;
    }
	
	return curr;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
	return 0;
}