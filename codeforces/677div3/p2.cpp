#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        vector<int> distances;
        int start = 0 , end = n-1;
        while(start<n && vec[start]==0){
            start++;
        }
        while(end>=0 && vec[end]==0){
            end--;
        }
        for(int i=start;i<end;i++){
            int j=i;
            int count = 0;
            while(j<end && vec[j]==0){
                count++;
                j++;
            }
            if(count){
                distances.push_back(count);
            }
            i = max(i,j-1);
        }
        long long int sum = 0;
        for(auto a:distances){
            sum+=a;
        }
        cout<<sum<<endl;

    }
    return 0;
}