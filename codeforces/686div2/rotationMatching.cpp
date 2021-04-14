#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<k;i++)
using namespace std;
vector<int> ptr[70];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int64_t> vec(n);
    rep(i,0,n)cin>>vec[i];
    rep(i,0,70){
        ptr[i].clear();
    }
    rep(i,0,n){
        rep(j,0,64)
        if(vec[i] & (1LL<<j)){
            ptr[j].push_back(i);
        }
    }
    int maxindex = 0;
    set<int64_t> answer;
    rep(i,0,64){
        if(ptr[i].size()>0){
            maxindex = i;
        }
    }
    for(auto a:ptr[maxindex]){
        answer.insert(a);
    }
    int maxsize = answer.size()+2;
    int64_t finans = (1LL<<maxindex);
    int permissible = 2;
    for(int i=maxindex-1;i>=0;i--){
        set<int64_t> s;
        for(auto a:answer){
            s.insert(a);
        }
        for(auto a:ptr[i]){
            s.insert(a);
        }
        if(s.size()<=maxsize){
            answer = s;
            finans+= (1LL<<i);

        }
    }
    cout<<finans<<endl;


    return 0;

    
}
/*

10
582366931603099761 314858607473442114 530263190370309150 871012489649491233 877068367969362781 671646356752418008 390155369686708364 958695211216189893 919124874293325142 196726357117434998
*/