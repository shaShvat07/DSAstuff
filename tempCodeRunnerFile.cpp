bool bfs(int root)
// {
//     queue<int> q;
//     q.push(root);
//     vector<bool> visited(N, false);
//     visited[root] = false;
//     bool ans = false;
//     while (!q.empty())
//     {
//         int u = q.front();
//         int children = 0;
//         q.pop();
//         for (int v : tree[u])
//         {
//             if (!visited[v])
//             {
//                 if(bacha[v] == 1)
//                     children++;
                
//                 visited[v] = true;
//                 q.push(v);
//             }
//         }
//         if(children >= 3)
//             return true;
//         else return false;
//     }
// }