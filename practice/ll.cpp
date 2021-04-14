#include<bits/stdc++.h>
using namespace std;
struct N{
    int it;
    N*n,*p,*a,*d;
};
N* Node(int it){
    N*t = new N();
    t->it = it;
    t->n = NULL;
    t->p = NULL;
    t->a = NULL;
    t->d = NULL;
    return t;
}
N*Test(int a[][4], int i, int j, N*c){
    if(i>=4 || j>=4){return NULL;}
    N *ext =  Node(a[i][j]);
    ext->n = c;
    ext->p = c;
    ext->a = Test(a,i,j+1,ext);
    ext->d = Test(a,i+1,j,ext);
    return ext;
}
int main(){
    int a[4][4] = {
        {4,2,1,3},
        {10,22,11,9},
        {0,-2,-9,8},
        {-5,5,50,15}
    };
    N * output = Test(a,0,0,NULL);
    cout<<output->it<<endl;
}