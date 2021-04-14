//simple dp approach to find bottom up approach

#include<bits/stdc++.h>
using namespace std;
int a,b,c,p,q,r;

// void generateSubsets(int n){
//     int range = (1<<length) -1;
//     for(int i=0;i<=range;i++){

//     }
// }

int tupleops(int p,int q, int r){
      //this initialises the difference variables
    //   long diff[3];
    //   long ratio[3];
      unordered_map<float,pair<int,int>> diff;
      unordered_map<float, pair<int,int>> ratio;
      bool canratio =(p!=0 || (a==0 && p==0));
      canratio = canratio && ((q!=0 || (b==0 && q==0)))
      int ratio = a*1.0/p;
      if()
      ratio.insert(make_pair(a*1.0/p, make_pair(p,a)));
      ratio.insert(make_pair(b*1.0/q, make_pair(q,b)));
      ratio.insert(make_pair(c*1.0/r, make_pair(r,c)));

      diff.insert(make_pair(a-p, make_pair(p,a)));
      diff.insert(make_pair(b-q, make_pair(q,b)));
      diff.insert(make_pair(c-r, make_pair(r,c)));
      

      int countdiff=0;
      int countrat =0;
      map<float,pair<int,int>>::iterator it1=diff.begin();
      map<float,pair<int,int>>::iterator it2=ratio.begin();

    //   for(;it1!=diff.end(); it1++, it2++){
    //       if(diff[i%3]!=diff[(i+1)%3])
    //         countdiff++;
    //       if(ratio[i%3]==ratio[(i+1)%3])
    //         countrat++;
    //   }

         for(;it1!=diff.end(); it1++, it2++){
             cout<<it1->first<<" "<<(it1->second).first
                 <<" "<<(it1->second).first<<endl;
        }
    
      /*
      if countdiff ==0 all diffs are equal that means
      if countdiff == 3 all diffs are different
      if countdiff == 2 two are same, one is different
      */
      int ans=min(countdiff,countrat);
      return ans;      

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cin>>p>>q>>r;
    int ans = tupleops(p,q,r);
    cout<<ans<<endl; 
      
    //   if(diffcount==0){
    //       cout<<1<<endl;
    //   }

     
    }
    return 0;
}