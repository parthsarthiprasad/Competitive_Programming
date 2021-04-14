#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int count =0;
    while(n){
        int k=0;
        int temp = n;
        while(temp){
            k= max(k,temp%10 );
            temp/=10;
        }
        n-=k;
        count++;
    }
    cout<<count<<endl;
}