#include <bits/stdc++.h>
using namespace std;

void fn(vector<long long> a,long long & op){
    if(a.size()==0) return;
    if(a.size()==1) return;
    if(a.size()==2){
        op+=a[0]+a[1];
        return;
    }
    int n=a.size();
    for(int i=0;i<n-1;i++){
        op=op+a[i]+a[i+1];
        vector<long long> rectemp;
        for(int j=0;j<i;j++) rectemp.push_back(a[j]);
        rectemp.push_back(a[i]+a[i+1]);
        for(int j=i+2;j<n;j++) rectemp.push_back(a[j]);
        for(int i=0;i<rectemp.size();i++){
            cout<<rectemp[i]<<" ";
        }
        cout<<endl;
        fn(rectemp,op);
    }
    return;
}
long long NOR(int x){
    if(x==0) return 1;
    long long op=1;
    for(int i=1;i<=x;i++) op=op*i;
    return op;
}
int main(){
    int t;
    cin>>t;
    int ttno=1;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        long long op=0;
        fn(a,op);
        long long nr=NOR(n-1);
        cout<<"Case #"<<ttno<<": "<<setprecision(6)<<(float)op/nr<<endl;
        ttno++;
    }
    return 0;
}