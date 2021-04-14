#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
#define ll long long int
#include<cstring>
using namespace std;

#include <bits/stdc++.h> 
#include<set>



int main(){
	 int t;
	 cin>>t;
	 while(t--){
	int n;
	cin>>n;
	if(n%2==0){
		int ans=(n>>1)+1;
		cout<<ans<<endl;
	}
	else{
		int ans=(n+1)>>1;
		cout<<ans<<endl;
	}

}

}