#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long int  a,b,c,d;
        cin>>a>>b>>c>>d;
        long int sum = 0;
        sum+=(abs(c-a) + abs(b-d));
        if(abs(b-d) && (abs(a-c))){
            sum+=2;
        }
        cout<<sum<<endl;
    }
    return 0;
}