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

const int N = (int)(2e5 + 5);
vector<int> tree[N];
vector<int> bacha(N,0);
void dfs(int s, int p)
{
    if (tree[s].size() == 0)
        bacha[s] = 1;
    else
        bacha[s] = 0;
    for (int v : tree[s])
    {
        if (v != p)
        {
            dfs(v, s);
        }
    }
}

bool bfs(int root)
{
    queue<int> q;
    q.push(root);
    vector<bool> visited(N, false);
    visited[root] = true;
    bool ans = false;
    while (!q.empty())
    {
        int u = q.front();
        int children = 0;
        q.pop();
        for (int v : tree[u])
        {
            if (!visited[v])
            {
                if(bacha[v] == 1)
                    children++;
                
                visited[v] = true;
                q.push(v);
            }
        }
        if(children >= 3)
            return true;
        else {
            break;
        }
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    ff(i, 1, n)
    {
        int u;
        cin >> u;
        // directed tree
        tree[u].push_back(i + 1);
    }
    dfs(1,0);
    bool ans = bfs(1);
    if(ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main()
{
    fastio();
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
