#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arriv[n];
        int dep[n];
        for(int i=0;i<n;i++)cin>>arrov[i];
        for(int j=0;j<n;j++)cin>>dep[j];
        sort(arriv,arriv+n);
        sort(dep,dep+n);
        int plats= 1, res = 1;
        int i=1, j = 0;
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                plats++;
                i++;
            }else{
                plats--;
                j++;
            }
            res = max(res, plats);
        }
        cout<<res<<endl;
    }

}