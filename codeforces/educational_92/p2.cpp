#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll int

vector<ll> a;
map<pair<int,int>, int>  smat;
int n,k,z;
const int MxN = 10000;
bool checkeqist(int i,int demp){
    return (smat.find({i,demp})!=smat.end())  ;
}
ll recurfunc(ll i, ll last, ll llen, ll demp, ll lbq){
	if(i>=n||i<0) return 0;
    else if(lbq<0) return 0;
    else if(demp==0) return a[i];
    
    else if(checkeqist(i, demp)) return smat[{i,demp}];
	ll yu=a[i];
	ll yu1=0;
	if(i>0&&llen<2)
		yu1=recurfunc(i-1,0,llen+1,demp-1,lbq-1);
	    ll yu2=recurfunc(i+1,1,0,demp-1,lbq);
	    yu=yu+max(yu1,yu2);
	
    smat[{i,demp}]=yu;
	return yu;
}
void input(int n){
        for(ll i=0;i<n;i++){
			int temp;
            cin>>temp;
            a.pb(temp);
		}
    return;
}
ll solve(){
		cin>>n>>k>>z;
		a.clear();
		smat.clear();
        input(n);
		
		return recurfunc(0,-1,0,k,z);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
        cout<<solve()<<endl;
		
	}
	return 0;
}