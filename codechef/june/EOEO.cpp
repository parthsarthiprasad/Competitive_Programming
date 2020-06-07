//simple dp approach to find bottom up approach

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        unsigned long int n, temp;
        cin>>n;
        temp = n;
        int count = 0;
        while(!(temp&1)){
            count++;
            temp=temp>>1;
        }
        cout<<temp/2<<endl;
        
    }
    return 0;
}