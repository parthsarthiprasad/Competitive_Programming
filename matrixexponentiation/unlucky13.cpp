#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 +9;
struct matrix{
    vector<vector<int>> a = vector<vector<int>>(2,vector<int>(2,0));
    matrix operator*(const matrix & other){
        matrix res;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    res.a[i][k]+= this->a[i][j] * other.a[j][k];
                    res.a[i][k] %= mod;
                }
            }
        }
        return res;
    }
};

matrix expo_power(matrix single, long long p){
    matrix id;
    for(int i=0;i<2;i++) id.a[i][i]= 1;
    while(p>0){
        if(p&1) id = id*single;
        single = single*single;
        p=p>>1;
    }
    return id;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        /*
        happy state is when i've not encountered a 1
        the matrix is of form
        happy to happy
        happy to sad
        sad to happy
        sad to sad
        */
        matrix single;
        single.a[0][0] = 9;
        single.a[0][1] = 1;
        single.a[1][0] = 8;
        single.a[1][1] = 1;

        matrix ans = expo_power(single,n);
        cout<<(ans.a[0][0] + ans.a[0][1])%mod<<endl;
    }
}