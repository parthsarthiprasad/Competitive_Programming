#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
map<int,int> m;
int four=0,t=0;
void process(){
     map<int,int>::iterator itr;
    for( itr=m.begin();itr!=m.end();itr++){
		int c=itr->second/4;
		four+=c;
		int tempcount=itr->second%4;
		tempcount=tempcount/2;
		t+=tempcount;
	}
}
int main(){
	int n;
	cin>>n;
	m.clear();
	for(int i=0;i<n;i++){
		int ch;
		cin>>ch;
		m[ch]++;
	}
	
   
    process();
	
	int q;
	cin>>q;
	while(q--){
		char ch; int d;
		cin>>ch; cin>>d;
		int c=m[d];
		int tempcount=c/4;
		four-=tempcount;
		tempcount=m[d]%4;
		tempcount=tempcount/2;
		t-=tempcount;
        switch(ch){
            case '+': m[d]++;
			c=m[d];
			tempcount=c/4;
			four+=tempcount;
			tempcount=m[d]%4;
			tempcount=tempcount/2;
			t+=tempcount;
            break;
            case '-' : m[d]--;
			c=m[d];
			tempcount=c/4;
			four+=tempcount;
			tempcount=m[d]%4;
			tempcount=tempcount/2;
			t+=tempcount;
        }
		
		bool ispossible=false;
		if(four>=2){
			ispossible=true;
		}
		else if(four<1){
			ispossible=false;
		}
		else if(four==1){
			if(t>=2) ispossible=true;
			else ispossible=false;
		}
		if(ispossible){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}