#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
// int64_t findans(int i, string &c,int thatindex, bool small = false){
//     if(small){
//         return 1<<(c.size()-i);
//     }
//     int64_t tans = 0;
//     for(int j =i;j<c.size();j++){
//         if(j>thatindex){
//             tans+= findans(j,c,thatindex, true);
//             break;
//         }
//     }
// }
int64_t digitdp[32][2];
void initialise(){
    for(int i=0;i<32;i++){
        for(int j=0;j<2;j++) digitdp[i][j] = -1;
    }
}
int64_t findans(int pos, int end, string &a, string &b, 
                string &c, int & thatindex, bool small){
    if(pos == end) return 1;
    int64_t &ans = digitdp[pos][small];
    if( ans !=-1) return ans;
    ans = 1;
    if(small){
        if( pos<=thatindex){
            ans*= findans(pos+1,end,a,b,c,thatindex, small);
        }else{
            ans*= 2*findans(pos+1,end,a,b,c,thatindex,small);
        }
        return ans;
    }
    if(a[pos]!=b[pos]){
        if(pos<=thatindex){
            if(c[pos]== '1'){
                 ans*=findans(pos+1,end,a,b,c,thatindex,true);
            }else{
                if(a[pos]=='1') ans*=findans(pos+1,end,a,b,c,thatindex, true);
            }
        }else{
            ans*=findans(pos+1,end,a,b,c,thatindex,true);
        }
    }else{
        if(pos<=thatindex){
            if(c[pos]=='1'){
                ans*=2*findans(pos+1,end,a,b,c,thatindex,small);
            }else{
                ans*=findans(pos+1,end,a,b,c,thatindex,small);
            }
        }else{
            ans*=2*findans(pos+1,end,a,b,c,thatindex,small);
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int x,y,n;
        cin>>x>>y>>n;
        if(x==y){
            cout<<"0\n";
            continue;
        }
        string a,b,c;
        while(x){
            a+= ((x&1)+'0');
            x/=2;
        }
        while(y){
            b+= ((y&1)+'0');
            y/=2;
        }
        while(n){
            c+= ((n&1)+'0');
            n/=2;
        }
 
        int sz = max(a.size(), max(b.size(), c.size()));
        a+= string(sz-a.size(), '0');
        b+= string(sz-b.size(), '0');
        c+= string(sz-c.size(), '0');
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());
        initialise();
        int thatindex =0;
        int kthindex = 0;
        while( kthindex<sz && c[kthindex]=='1'){
            thatindex = kthindex;
            kthindex++;
        }
        while( kthindex< sz && c[kthindex]=='0'){
            thatindex = kthindex;
            kthindex++;
        }
        thatindex = kthindex-1;
        int64_t count = findans(0,sz,b,a,c,thatindex, false);
        int64_t sum =0;
      
        cout<<count<<endl;

        // for(int i=0;i<sz;i++){
        //     if(a[i]!=b[i]){

        //         int64_t tempcount = 1;
        //         bool possible = false;
        //         int j=i;
        //         while(j<sz && j<=thatindex){
        //             if(c[j]=='1'){
        //                 tempcount*=2;
        //                 possible = true;
        //             }
        //             j++;
        //         }
        //         if(possible) tempcount+= 1<<(sz-thatindex-1);
        //         count+= tempcount;
        //     }else{
        //         int64_t tempcount = 1;
        //         bool possible = false;
        //         if(c[i]==a[i]){
                    
        //         }
        //         if(possible) tempcount+= 1<<(sz-thatindex-1);
        //     }
        // }
        
        // count = findans(x,y,);
 
    }
  return 0;  
}