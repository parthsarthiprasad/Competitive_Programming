#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin>>tt;
	while(tt--){
		long long n;
		cin>>n;
		if(n==1){
			cout<<"FastestFinger"<<endl;
			continue;
		}
		if(n==2){
			cout<<"Ashishgup"<<endl;
			continue;
		}
		if(n%2!=0){
			cout<<"Ashishgup"<<endl;
			continue;
		}
		long long no2=0;
		long long n1=n;
		long long temp=1;
		while(n1%2==0){
			no2++;
			n1/=2;
			temp*=2;
		}
		if(temp==n||no2&1){
			cout<<"FastestFinger"<<endl;
			continue;
		}
		else{
			cout<<"Ashishgup"<<endl;
			continue;
		}	
	}
}