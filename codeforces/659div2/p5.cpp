#include <bits/stdc++.h>
#define ll long long 
using namespace std;
string temp1,temp2;
int solve(){
    ll n;
		cin>>n;
		cin>>temp1>>temp2;
		bool ispossible=true;
        
		for(int i=0;temp1[i];i++){
			if(temp1[i]!=temp2[i]&&temp2[i]<temp1[i]){
				ispossible=false;
				break;
			}
		}
		if(!ispossible){
			return -1;
			continue;
		}

		long long ans=0;
		for(char temp='a';temp<='t';temp++){
			char mini='@';
			for(int i=0;i<n;i++){
				if(temp1[i]==temp2[i]) continue;
				else if(temp1[i]==temp){
					if(mini=='@') mini=temp2[i];
					else{
						mini=min(mini,temp2[i]);
					}
				}
			}
			if(mini=='@') continue;
			else{
				for(int i=0;i<n;i++){
					if(temp1[i]==temp2[i]) continue;
					else if(temp1[i]==temp){
						temp1[i]=mini;
					}
				}
                ans++;
			}
		}
		return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}