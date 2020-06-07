#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll  a,b;
        cin>>a>>b;
        int temp = max(a,b);
        int temp2 = min(a,b);
        ll  num = temp/temp2;
        int count = 0;
        while( num%8 == 0){
             num/=8;
             count++;
        }
        while ( num%4 == 0){
           num/=4;
           count++;
        }
       
        while ( num%2 == 0){
            num/=2;
           count++;
        }
        if (num!=0) count = -1;
        cout<<count<<endl;
    }
    return 0;
}