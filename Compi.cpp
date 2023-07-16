#include<bits/stdc++.h>
#define ll long long
#define pp pair<int,int>
using namespace std;

int diff ( int a , int b)
{
    if( a<b)
        return b-a;
    else
        return a-b;
}
int solve(int *input , int n , int d , int h){
        double comp = h, maxwell = 0.0;
        for ( int i = 0 ; i <= n ; i++) {
            double help = (double) ( input[i]- input[i-1])/double(d);
            comp += help;
            if(comp < 0.0)  { comp = 0.0; maxwell = max (maxwell , comp);}
        }

        double ans = maxwell * (double) d;
        return ans;
}

int main(){

    int t; cin>>t;
    while(t--){
        int n , d ,h;
        cin >> n >> d >> h;
        int *input = new int[n+1];
        input[0] = 0;
        for( int i = 1;  i <= n ; i++) 
        {
           cin >> input[i];
        }
        
        int ans=solve(input, n , d , h);
        cout<<ans<<endl;
    }

    return 0;
}