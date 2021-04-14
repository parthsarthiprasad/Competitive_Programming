#include <bits/stdc++.h>

using namespace std;


template <int delta> struct ManacherBase{
private:
		static const int maxn=1e5+1;
        int r[maxn];
        char s[maxn];
        int mid,n,i;

public:
        ManacherBase():mid(0),i(0),n(1) 
        {
        	memset(r,-1,sizeof(int)*maxn);
        	s[0]='$';
        	r[0]=0;
        }

        int get(int pos)
        {
        		pos++;
                if(pos<=mid)
                        return r[pos];
                else
                        return min(r[mid - (pos - mid)], n - pos - 1);
        }
        
        void addLetter(char c)
        {
                s[n]=s[n+1]=c;
                
                while(s[i - r[i] - 1 + delta] != s[i + r[i] + 1])
                        r[++i] = get(i-1);
                r[mid=i]++, n++;
        }

        int maxPal()
        {
                return ( n - mid - 1 ) * 2 + 1 - delta;
        }
} ;

struct Manacher{
private:
        ManacherBase<1> manacherEven;
        ManacherBase<0> manacherOdd;
public:
        void addLetter(char c)
        {
                manacherEven.addLetter(c);
                manacherOdd.addLetter(c);
        }

        int maxPal()
        {
                return max(manacherEven.maxPal(), manacherOdd.maxPal());
        }
        int getRad(int type,int pos)
        {
                if(type)
                        return manacherOdd.get(pos);
                else
                        return manacherEven.get(pos);
        }
} ;

int main()
 {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string t;
    while(cin>>t)
    {
        int n=t.size();
        Manacher test;
        for(int i=0;i<n;i++)
        {
            test.addLetter(t[i]);
            cout<<"Arrays for string "<<t.substr(0,i+1)<<":"<<endl;
            for(int z=0;z<2;z++)
            {
                for(int j=0;j<=i;j++)
                    cout<<test.getRad(z,j)<<' ';
                cout<<endl;
            }
        }
        cout<<"========================================="<<endl;
    }
}

