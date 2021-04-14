#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long 
#define pb push_back
#define mp make_pair
using namespace std;
ll solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    vector<pair<int,int>> temp;
    int count =0;
    for(int i=0;i<n;i++){
        int index=i;
        while(vec[index]==1){
            index++;
        }
        if(index!=i){
            temp.pb(mp(i,index));
            i=index;
        }
    }

    if(temp.size()==0){
        return 0;
    }
    if(temp.size()==1){
        return temp[0].second-temp[0].first;
    }
    
    vector<pair<int,int> >::iterator it = temp.begin();
    // while(it!=temp.end()){
    //     cout<<it->first<<" "<<it->second<<endl;
    //     it++;
    // }
    vector<pair<int,int> >::iterator it1 = temp.begin();
    it1++;
    int maxsofar = it->second - it->first;
    while(it!=temp.end() && it1!=temp.end()){
        if(it1->first- it->second <3){
            maxsofar=max(maxsofar, it1->second - it->first);
        }
        maxsofar = max(maxsofar, it1->second-it1->first);
        it++;
        it1++;
    }
    return maxsofar;
    // int maxsofar = 0;
    // int countseg1 =0;
    // for(int i=0;i<n;i++){
    //     int count = 0;
    //     while(vec[i]==1){ count++;i++;}
    //     if(countseg1==0){ countseg1=count;}
    //     int count2 =0;
    //     int index =i;
    //     while(vec[i]==0){count2++;i++;}
    //     if(count2>2){
    //         i--;
    //     }
    //     else{
    //         while(vec[])
    //     }
    // }
    
}
int main() {
    fio
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

	// Write your code here
}
