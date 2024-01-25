#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb(n) push_back(n)
#define f(i, n) for (int i = 0; i < n; i++)
#define ff(i, x, n) for (int i = x; i < n; i++)
using namespace std;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int minCost(int **cost, int s, int p, int n, int mask, int *dp)
{

    if (s >= p)
        return 0;
    if (dp[mask] != INT_MAX)
        return dp[mask];

    int ans = INT_MAX;
    f(j, n)
    {
        if (!(mask & (1 << j)))
        {
            int temp = minCost(cost, s + 1, p, n, (mask | (1 << j)), dp) + cost[s][j];
            ans = min(ans, temp);
        }
    }

    dp[mask] = ans;
    return ans;
}

void solve()
{
    // input
    int p, n;
    cin >> p >> n;
    int **cost = new int *[p];
    int *dp = new int[1 << n];
    f(i, 1 << n) dp[i] = INT_MAX;

    f(i, p)
    {
        cost[i] = new int[n];
        f(j, n)
        {
            int a;
            cin >> a;
            cost[i][j] = a;
        }
    }

    cout << minCost(cost, 0, p, n, 0, dp) << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}
