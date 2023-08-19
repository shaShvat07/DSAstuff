#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int subtreeXOR[N];
vector<int> adj[N];

void dfs(int s, int p)
{
    subtreeXOR[s] = s;
    for (int v : adj[s])
    {
        if (v != p)
        {
          dfs(v,s);
          subtreeXOR[s] ^= subtreeXOR[v];
        }
    }
}

int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n , q;
        cin >> n >> q;
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
            subtreeXOR[i] = 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, 0);

        while(q--){
            int u;
            cin >> u;
            cout << subtreeXOR[u] << endl;
        }
    }
    return 0;
}