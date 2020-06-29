#include <bits/stdc++.h>
#include <string>
using namespace std;
 vector<pair<int,int> > ans;

void fnd(int siz,int tar,int curr,string & op,string& temp){
	if(curr>=siz||tar<0) return;
	if(tar==0){
		if(op=="0"){
			op=temp;
		}
		else if(temp.compare(op)>0){
			op=temp;
		}
		return;
	}
	fnd(siz,tar,curr+1,op,temp);
	temp.push_back('a'+(ans[curr].second));
	fnd(siz,tar-ans[curr].first,curr,op,temp);
	temp.pop_back();
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cost[26];
	for(int i=0;i<26;i++) cin>>cost[i];
    map<int,int> t;
    for(int i=0;i<26;i++){
        if(t.find(cost[i])==t.end()){
            t.insert({cost[i],i});
        }else{
            t[cost[i]]=i;
        }
    }
   
    map<int,int>::iterator it;
    for(it = t.begin(); it!=t.end();it++){
        ans.push_back({it->first,it->second});
    }
    

	int tar;
	cin>>tar;
	int curr=0;
	string op="0";
	string temp="";
	fnd(ans.size(),tar,curr,op,temp);
	cout<<op<<endl;
}