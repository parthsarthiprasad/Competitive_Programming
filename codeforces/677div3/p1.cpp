#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int ptr[4] = {1,3,6,10};
    while(t--){
        int n;
        cin>>n;
        string temp = to_string(n);
        long int sum = 0;
        sum+=(temp[0]-'1')*10;
        sum+=ptr[temp.size()-1];
        cout<<sum<<endl;
        
    }
    return 0;
}