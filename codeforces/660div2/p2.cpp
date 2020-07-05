#include <bits/stdc++.h>
using namespace std;
int n;
string solve(){
    	cin>>n;
    	string a=""; 
        int temp=ceil(n/4.0);
		int l=n-temp;
		while(l--){
			a+='9';
		}
		while(temp--){
			a+='8';
		}
		return a;   
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<endl;
		
	}
	return 0;
}