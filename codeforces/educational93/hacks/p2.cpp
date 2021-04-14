#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    //code goes here
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
    cout.tie(NULL);
	ll int t;
    cin>>t;
    while(t--)
    {
        ll int n;
	    cin>>n;
	    ll int a[n];
	    
	    for(ll int i=0 ; i<n ; i++){
	        cin>>a[i];
	    }
	    
	    vector<ll int> v(a, a+n);
	    
	    int f = 0, i=0, j=1, k=2;
	    
	    while(k < n){
	        if(v[i] + v[j] <= v[k]){
	            cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
	            f = 1;
	            break;
	        }
	        else{
	            k++;
	        }
	    }
	    
	    if(f == 0){
	        cout<<-1<<endl;
	    }
        
        
    }
	return 0;
}
