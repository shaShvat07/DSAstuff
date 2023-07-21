#include<iostream>
#include <algorithm>
#include <climits>
using namespace std;
int please ( int ** input , int i , int j, int n , int m , int **dp){
    if(i == n-1 && j == m-1 )
        return input[i][j];
 
    int first = INT_MAX , second = INT_MAX, third = INT_MAX;
    int temp = input[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];

    if(i+1 < n){
        first = please(input , i+1 , j , n , m , dp);
    }
    if( j+1 < m){
        second = please(input, i , j+1 , n ,m ,dp );
    }
    if(i+1 < n && j+1 < m)
    {
        third = please (input , i+1, j+1 , n, m,dp);
    }

    int help = min(first, min(second, third));
    dp[i][j] = help+temp;

    return help+temp;
}

int minCostPath(int **input, int n, int m) {
    int** dp = new int*[n];
    for(int i = 0 ; i < n ; i++) {
        dp[i] = new int [m];
        for(int j =0 ;  j < m ; j++) dp[i][j] = -1;
    }

    int ans = please(input , 0 , 0 , n , m, dp);

    delete []dp;
    return ans;

}
int main()
{
    int **arr,n,m,i,j;
    cin >> n >> m;
    arr = new int*[n];
    for(i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> arr[i][j];
	    }
    }
    
    cout << minCostPath(arr, n, m) << endl;
    
    return 0;
}