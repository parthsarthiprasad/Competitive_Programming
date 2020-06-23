#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define for(a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define pll pair<long, long>
int solve(){
    int a,b,n;
    cin>>a>>b>>n;
    int temp2 = max(a,b);
    int nextval = a+b;
    int count = 1;
    int temp;
    while(nextval<=n){
        temp = nextval;
        nextval+=temp2;
        temp2=temp;
        count++;
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}