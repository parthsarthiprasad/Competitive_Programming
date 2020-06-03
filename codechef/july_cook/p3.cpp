#include<bits/stdc++.h>
#define ll long long
#define int long long  
#define pb push_back
using namespace std;
int bases(int i){
    int count =0;
    while(i){
        count++;
        i/=2;
    }
    return count;
}
ll solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    
    vector<vector<int> > bitstore(n);
    //filling the bitstore
    
    for(int i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++){
        int temp =vec[i];
        while(temp){
            if(temp&1){
                //bitstore[i].insert(bitstore.begin(),1);
                bitstore[i].pb(1);
            }else{
                //bitstore[i].insert(bitstore.begin(),0);
                bitstore[i].pb(0);
                }
            temp/=2;
        } 
    }
    vector<int> bitoff(n);
    for(int i=0;i<n;i++){
        int temp = vec[i];
    }
    int num1 = vec[n-1];
    vector<int> numrep;
    while(num1){
        if(num1&1){
            //numrep.insert(numrep.begin(),1);
            numrep.pb(1);
        }else{
            //numrep.insert(numrep.begin(),0);
            numrep.pb(0);
        }
        num1/=2;
    }
    num1=vec[n-1];
    for(int i=0;i<n;i++){
        int start = numrep.size()-1;
        int start2 = bitstore[i].size()-1;

        while(start>-1 && start2>-1&& numrep[start]==bitstore[i][start2]){start--; start2--;}
        bitoff[i] = numrep.size()-1-start;
    }

    // for(int i=0;i<n;i++){
    //     cout<<vec[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"bitstore";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<bitstore[i].size();j++){
    //         cout<<bitstore[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // cout<<"bitoff";
    // for(int i=0;i<n;i++) cout<<bitoff[i]<<" ";
    // cout<<endl;
    // cout<<"numrep";
    // for(int i=0;i<n;i++) cout<<numrep[i]<<" ";
    // cout<<endl;
     int index = 0;
     int maxlen=0;
     for(int i=0;i<n-1;i++){
         int sz = bitstore[n-1].size() + bitstore[i].size()-bitoff[i];
         if(sz>maxlen){
             maxlen=sz;
             index=i;
         }
     }
     ll finans1=vec[n-1]<<(bitstore[index].size());
     //cout<<"TEST"<<finans1<<endl;
     finans1+=vec[index];
     //cout<<finans1<<endl;
     ll finans2=vec[index]<<(bitstore[n-1].size());
     finans2+=vec[n-1];
     //cout<<finans2-finans1;
      
    //  for(int i=0;i<bitstore[i].size();i++){

    //  }

    // int num2=0;
    // int i=n-2;
    // for(;i>-1;i--){
    //     int temp = vec[i];
    //     int bit=30;
    //     for(;bit>=0;--bit){
    //         if(vec[i]==1){num2=1; break;}
    //         if(temp & (1<<bit)){
    //             break;
    //         }
    //         // if((vec[i] &(1<<bit)) ){
    //         //     if(vec[i]&(1<<(bit-1))){
    //         //         num2=vec[i];
    //         //         break;
    //         //     }else{

    //         //     }
    //         // }
    //     }
    //     while(vec[i])
    //     if(num2!=0){break;}
    // }
    // if(num2==0){num2=vec[0];}
    // //cout<<num1<<" "<<num2<<endl;
    // ll finans1 = (num1<<bases(num2))+num2;
    // ll finans2 = (num2<<bases(num1))+num1;
    //cout<<finans1;
    //return finans2-finans1;
    //find number whose 2nd highest bit is 1,
    //number whose 2nd highest bit is 0.

    return (finans2-finans1);
}
signed  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}