#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int r,c;
	cin>>r;
	cin>>c;
	for(int j=c;j>=1;j--){
		cout<<r<<" "<<j<<endl;
	}
	for(int j=c+1;j<=m;j++){
		cout<<r<<" "<<j<<endl;
	}
	int flag=0;
	for(int i=r-1;i>=1;i--){
		if(flag&1){
			for(int j=1;j<=m;j++) cout<<i<<" "<<j<<endl;
		}
		else{
			for(int j=m;j>=1;j--) cout<<i<<" "<<j<<endl;
		}
		flag++;
	}
	for(int i=r+1;i<=n;i++){
		if(flag&1){
			for(int j=1;j<=m;j++) cout<<i<<" "<<j<<endl;
		}
		else{
			for(int j=m;j>=1;j--) cout<<i<<" "<<j<<endl;
		}
		flag++;
	}
	return 0;
}