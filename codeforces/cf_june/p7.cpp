//simple dp approach to find bottom up approach

#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 
float a,b,c,p,q,r;

int verify_table_difference(int p,int q,int r, vector<int> diff, set<int> unique_diff){
    /*
     Initialising the diff tables
     only include those values that need to be changed
     */      
     if(a!=p){
      diff.push_back(a-p);
      unique_diff.insert(a-p);
     }
     if(b!=q){
      diff.push_back(b-q);
     unique_diff.insert(b-q);
     }
     if(c!=r){
      diff.push_back(c-r);
      unique_diff.insert(c-r);
     }

     int diffcount = unique_diff.size();
      //all cases of doing in 0 tries for difference
      //bool ans=true;
     return diffcount;

}



int function1(float a,float b,float c){
    if(p>a||q>b||r>c) return 3;
    if(p==a){
        if(q==b){
            if(r==c){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if (r==c){
            if(q==b){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            if((q-b)==(r-c))
                return 1;
            else if(q!=0 && r!=0 && (b*1.0/q)==(c*1.0/r))
                return 1;
            else 
                return 2;
            // else if((r!=0 && c%r==0 && b%(c/r)==0 &&(b/(c/r)-q>=0)) || (q!=0&& b%q==0 && c%(b/q)==0 && (c/(b/q)-r>=0)) )
            //     return 2;
            // else 
            //     return 3;
        }
    }
    else if(q==b){
        if(p==a){
            if(r==c){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if (r==c){
            if(p==a){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            if((p-a)==(r-c))
                return 1;
            else if(p!=0 && r!=0 && (a*1.0/p)==(c*1.0/r))
                return 1;
            else 
                return 2;
            // else if((r!=0&& c%r==0 && a%(c/r)==0 && (a/(c/r)-p>=0)) || (p!=0 && a%p==0 && c%(a/p)==0 && (c/(a/p)-r>=0)) )
            //     return 2;
            // else 
            //     return 3;
        }
    }
     else if(r==c){
        if(p==a){
            if(q==b){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if (q==b){
            if(p==a){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            if((p-a)==(q-b))
                return 1;
            else if(p!=0 && q!=0 && (a*1.0/p)==(b*1.0/q))
                return 1;
            else 
                return 2;
            // else if((q!=0&& b%q==0 && a%(b/q)==0 && (a/(b/q)-p>=0)) || (p!=0 && a%p==0 && b%(a/p)==0 && (b/(a/p)-q>=0)) )
            //     return 2;
            // else 
            //     return 3;
        }
    }
    else{
        vector<int> diff;
        set<int> unique_diff;
        int temp1 = verify_table_difference(p,q,r,diff,unique_diff);
        // bool temp2 = (p && q &&r && (a/p == b/q) &&(b/q==c/r) )
       
        if((p && q &&r && (a/p == b/q) &&(b/q==c/r) ))
            return 1;
         if(temp1<3)
            return temp1;
    }
    return 3;
}


int verify_answer(float p,float q,float r){
    if(p>a||q>b||r>c) return 3;
    if(p==a){
        if(q==b){
            if(r==c){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if (r==c){
            if(q==b){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            if((q-b)==(r-c))
                return 1;
            else if(q!=0 && r!=0 && (b*1.0/q)==(c*1.0/r))
                return 1;
            else 
                return 2;
            // else if((r!=0 && c%r==0 && b%(c/r)==0 &&(b/(c/r)-q>=0)) || (q!=0&& b%q==0 && c%(b/q)==0 && (c/(b/q)-r>=0)) )
            //     return 2;
            // else 
            //     return 3;
        }
    }
    else if(q==b){
        if(p==a){
            if(r==c){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if (r==c){
            if(p==a){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            if((p-a)==(r-c))
                return 1;
            else if(p!=0 && r!=0 && (a*1.0/p)==(c*1.0/r))
                return 1;
            else 
                return 2;
            // else if((r!=0&& c%r==0 && a%(c/r)==0 && (a/(c/r)-p>=0)) || (p!=0 && a%p==0 && c%(a/p)==0 && (c/(a/p)-r>=0)) )
            //     return 2;
            // else 
            //     return 3;
        }
    }
     else if(r==c){
        if(p==a){
            if(q==b){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if (q==b){
            if(p==a){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            if((p-a)==(q-b))
                return 1;
            else if(p!=0 && q!=0 && (a*1.0/p)==(b*1.0/q))
                return 1;
            else 
                return 2;
            // else if((q!=0&& b%q==0 && a%(b/q)==0 && (a/(b/q)-p>=0)) || (p!=0 && a%p==0 && b%(a/p)==0 && (b/(a/p)-q>=0)) )
            //     return 2;
            // else 
            //     return 3;
        }
    }
    else{
        
        //int count = verify_table(p,q,r);
        //this place means neither p==a,not q==b, or r==c
        //this is done for answer 1
        vector<int> diff;
        set<int> unique_diff;
        int temp1 = verify_table_difference(p,q,r,diff,unique_diff);
        // bool temp2 = (p && q &&r && (a/p == b/q) &&(b/q==c/r) )
       
        if((p && q &&r && (a/p == b/q) &&(b/q==c/r) ))
            return 1;
         if(temp1<3)
            return temp1;

        //for cases with return value as 2;
        bool isdivisible = true;
        isdivisible = p && q && r;
        if(isdivisible && (int)a%(int)p==(int)b%(int)q && (int)b%(int)q==(int)c%(int)r)
            return 2;
        
        vector<float> ratio;
        set<float> unique_ratio;

        int i=1;
        int val1= a/i;
        int val2=b/i;
        int val3=c/i;
        int val = 3;
        while(val1 >=p && val2 >=q && val3 >=r){

            if(val<3){
                break;
            }
            val=min(val,function1(val1,val2,val3));
            i++;
            while((((int)a%i!=0)&& ((int)b%i!=0)&& ((int)b%i!=0)) && (a/i >=p && b/i >=q && c/i >=r)){
                i++;
            }
            val1= a/i;
            val2=b/i;
            val3=c/i;
        }

    
       //return verify_table(p,q,r);
       return val;

    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    auto start = high_resolution_clock::now();
    while(t--){
      cin>>p>>q>>r;
      cin>>a>>b>>c;
      //verify_table(p,q,r); 
        
      int ans = verify_answer(p,q,r);
      cout<<ans<<endl;
     
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout<<"TIME TAKEN:\t"<<duration.count()/1e6<<endl;
    return 0;
}