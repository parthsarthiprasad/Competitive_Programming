#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
using namespace std;
int nonzero(vector<pair<int,int>> vec, int i){
    while(vec[i].second==0){
        i++;
    }
    return i;
}
int findsteps(pair<int,int> a, pair<int,int> b){
    int minsteps= min(a.second,b.second);
    int maxsteps = max(a.second, b.second);
    int numsteps = maxsteps/minsteps + (maxsteps%minsteps)*2;
    return numsteps;
}
ll solve(){

    int n;
    cin>>n;
    vector<int> a1(n);
    vector<int> b1(n);
    map<int,int> a,b;
    vector<pair<int,int>> vec;
    vector<int> ans[n+1];
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a1[i] = temp;
        if(a.find(temp) == a.end()){
            a[temp]=1;
        }
        else{
            a[temp]++;
        }
    }
    
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        b1[i]=temp;
        if(b.find(temp) == b.end()){
            b[temp]=1;
        }
        else{
            b[temp]++;
        }
    }
    int sum=0;
    bool isidentical = true;
    map<int,int>::iterator it;
    for(it=a.begin();it!=a.end();++it){
        int temp1 = b[it->first];
        int temp2 = it->second;
        if(((temp1!=temp2) && (temp1-temp2)&1)){
            isidentical = false;
            break;
        }
        if(temp1!=temp2){
            vec.pb(mp(it->first,abs((temp1-temp2)/2)));
        }
    }
    if(isidentical==false){
        sum=-1;
        return sum;
    }

    for(int i=0;i<vec.size();++i){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    cout<<endl;

    // for(int i=n-1;i>0;i--){
    //     if(vec[i-1].first>vec[0].first*2){
    //         int numsteps = findsteps(vec[i],vec[0]);
    //         sum+=vec[0].first*numsteps;
    //     }
    //     else{
    //         int numsteps = findsteps(vec[i],vec[i-1]);
    //         sum+=vec[i-1].first*numsteps;
    //         i--;
    //     }
    // }
     return sum;

    
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}