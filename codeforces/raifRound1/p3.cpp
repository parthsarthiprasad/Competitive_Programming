#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long sum = 0;
        int countb = 0;
        int counta = 0;

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='B'){
                countb++;
            }else{
                if(countb){
                    countb--;
                }else{
                    sum++;
                }
            }
        }
        cout<<sum + (countb)%2<<endl;
    }
    return 0;
}