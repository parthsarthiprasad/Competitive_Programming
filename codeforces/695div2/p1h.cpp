#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n+3,0);
        vec[1] = 8;
        vec[0] = 9;
        vec[n-1] = max(vec[n-1],0);
        int i = 2;
        int j = n-2;
        while(i<=j){
            vec[i] = (vec[i-1]+1)%10;
            vec[j] = max(vec[j], (vec[j+1]+1)%10);
            i++;
            j--;
        }
        for(int i=0;i<n;i++){
            cout<<vec[i];
        }
        cout<<endl;
    }
    return 0;
}

