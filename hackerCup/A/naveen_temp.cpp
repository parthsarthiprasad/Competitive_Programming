#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void twoDArray(char incoming [], char outgoing [] , int N)
{
    
    char Planes[N][N];
    
    for( int i = 0; i < N; i++)
    {
        for( int j = 0 ;  j < N; j++)
        {
            
            if( i == j)
            Planes[i][j] = 'Y';
            
            else if( abs(i - j) == 1)
            {
                
                if( outgoing[i] == 'Y' && incoming[j] == 'Y')
                {
                    Planes[i][j] = 'Y';
                    
                    int temp = j;
                    
                    while( (outgoing[j] == 'Y' && incoming[j+1] == 'Y') )
                    {
                        Planes[i][j+1] = 'Y';
                        j++;
                    }
                    
                    while( outgoing[j] == 'Y' && incoming[temp-1] == 'Y')
                    {
                        Planes[i][temp] = 'Y';
                        temp--;
                    }
                }
                else
                Planes[i][j] = 'N';
                
            }
            
            else
            Planes[i][j] = 'N';
            
        }
    }
    
    for( int i = 0; i < N; i++)
    {
        for( int j = 0; j < N; j++)
        {
            cout << Planes[i][j];
        }
        cout << "\n";
    }
    
}

void solution( int T)
{
    
    for(int j = 1; j <= T; j++)
    {
        cout << "Case #" << j << ":" << "\n";
        
        int N;
        
        cin >> N;
        
        char incoming[N];
        
        char outgoing[N];
        
        for(int i = 0; i < N; i++)
        cin >> incoming[i];
        
        for(int i = 0; i < N; i++)
        cin >> outgoing[i];        
    
       twoDArray(incoming, outgoing, N);    
        
    }
    
    
}


int main()
{
    fastIO;
    
    int T;
    
    cin>>T;
    
    solution(T);
    
    return 0;
}