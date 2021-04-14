#include<bits/stdc++.h>
using namespace std;
struct dat{
    int a;
    int b;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,temp;
        cin>>n;
        vector<int> num1(n);
        vector<long> num2(n);
        vector<dat> vec(n);
        for(int i=0;i<n;++i)cin>>num1[i];
        for(int i=0;i<n;++i)cin>>num2[i];
        for(int i=0;i<n;++i){
            cin>>temp;
            num2[i]*=temp;
        }
        for(int i=0;i<n;++i){
            vec[i].a = num1[i];
            vec[i].b = num2[i];
        }
        sort(vec.begin(),vec.end(),[&](const dat &num1,const dat &num2){
            return num1.a*(num2.b)>num2.a*num1.b;
        });
        // reverse(vec.begin(),vec.end());
        // reverse(vec.begin(),vec.begin() + vec.size() -1);
        for(int i=0;i<n;++i)cout<<vec[i].a<<" ";
         cout<<endl;
        for(int i=0;i<n;++i)cout<<vec[i].b<<" ";
        cout<<endl;

    }
    return 0;
}