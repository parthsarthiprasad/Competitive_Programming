#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(a,b,c) for(int j=a;i<=b;i++)

int n,m,x,y;
int ispossible=0;
vector<pair<int,int> > ans;
void process1(){
for(int i=x-1;i>=1;i--){
		if(ispossible&1){
			for(int j=1;j<=m;j++){ ans.pb({i,j});} 
		}
		else{
			for(int j=m;j>=1;j--){ ans.pb({i,j});} 
		}
		ispossible++;
	}

}
void process2(){
for(int i=x+1;i<=n;i++){
		if(ispossible&1){
			for(int j=1;j<=m;j++) { ans.pb({i,j});} 
		}
		else{
			for(int j=m;j>=1;j--) { ans.pb({i,j});} 
		}
		ispossible++;
	}
}
void PRINT(){
for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
void solve(){
    
	cin>>n>>m>>x>>y;
    ans.clear();
	for(int j=y;j>=1;j--){
        ans.pb({x,j});
		
	}
	for(int j=y+1;j<=m;j++){
		ans.pb({x,j});
	}
    ispossible=0;
	
    process1();
	process2();
    PRINT();

    
}
int main(){
    solve();
	return 0;
}