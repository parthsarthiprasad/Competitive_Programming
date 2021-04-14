#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int nax = 5e5+5;
vector<int> fans;
int finalsize = 1e9;
vector<int> tempvec(nax);
int findcover(vector<int> &tempans, int index, int n, vector<vector<int>> &vec, vector<int> &mask, int m , int count = 0){
    if(count == m) return count;
    if(index==n) return m;
    tempvec = mask;
    int val;
    int tempval = count;
    tempans.push_back(index);
    for(int i=0;i<m;i++){
        if(mask[i]==0 && vec[index][i]==1) count++;
        mask[i] = mask[i] | vec[index][i];
    }
    val = findcover(tempans,index+1,n,vec,mask,m,count);
    if(val<finalsize){
        finalsize = val;
        fans = tempans;
    }
    tempans.pop_back();
    count = tempval;
    val = findcover(tempans, index+1,n,vec,mask,m,count);
    if(val<finalsize){
        finalsize = val;
        fans = tempans;
    }
    return val;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        finalsize = m;
        vector<vector<int>> vec(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            for(int j=0;j<k;j++){
                int temp;
                cin>>temp;
                temp--;
                vec[i][temp] = 1;
            }
        }
        //finding product mod 1e9+7
        vector<int> count0(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec[i][j]==0){
                    count0[j]++;
                }
            }
        }
        int64_t product = 1;
        for(int i=0;i<m;i++){
            if(count0[i]==0 || count0[i]==n) continue;
            else product*=2;
            product%=mod;
        }

        //now finding the vertex cover
        vector<int> tempans;
        vector<int> mask(m,0);
        int sz =  findcover(tempans,0, n, vec, mask,  m);
        cout<<product<<" "<<fans.size()<<endl;
        for(auto a:fans){
            cout<<a+1<<" ";
        }
        cout<<endl;

        // for(auto a:tempans){
        //     cout<<a<<" ";
        // }
        // cout<<endl;


    }
    return 0;
}

 // for(int i=0;i<m;i++){
        //     if(count0[i]==0){
        //         for(auto a:mpzero[i]){
        //             if(rans.find(a)!=rans.end()){
        //                 rans.erase(a);
        //             }
        //         }
                
        //     }else if(count0[i]==1){
        //         for(auto a:mpone[i]){
        //             if(rans.find(a)!=rans.end()){
        //                 rans.erase(a);
        //             }
        //         }
        //     }
        // }