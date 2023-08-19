#include <bits/stdc++.h>
#define ll long long

ll startSum(vector<int>& k, int n){
    ll ans = 0;
    for(int i = 0; i < n ; i++) {
        ans += k[i]*1;
    }
    return ans;
}

ll totalSum(vector<int>& k, int n){
    ll ans = 0;
    for(int i = 0; i < n ; i++) {
        ans += k[i]*2;
    }
    return ans;
}

bool check (vector<pair<int , int>>&daycan, vector<int>& k, int n, int m, ll mid){
    ll money = mid;
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(k[i] > 0)
        {   
            for(int j = 0 ; j < m ; j++){
                daycan[j].first
            }
        }
    }

    return (money >= 0);
}

bool comp (pair<int,int> &a , pair <int,int> &b)
{
    return a.first > b.first;
}
int minimumDays(vector<int>& days, vector<int>& candies, vector<int>& k, int n, int m)
{
	// write your code here
    ll start = startSum(k , n);
    ll end = totalSum(k , n);
    ll ans = end;
    vector <pair <int, int>> daycan(m);
    for(int i = 0  i < m ; i++)
    {
        daycan[i].first = days[i];
        daycan[i].second = candies[i];
    } 

    sort(daycan.begin() , daycan.end() , comp);
    
    while(start <= end){
        ll mid = start + (end - start)/2;
        if(check(daycan, k , n , m , mid)){
            end = mid-1;
            ans = mid;
        }
        else start = mid+1;
        return ans;
    }
}
