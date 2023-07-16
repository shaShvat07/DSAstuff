#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingLahot;
    visited[sv] = true;
    pendingLahot.push(sv);
    while (!pendingLahot.empty())
    {
        int startGuy = pendingLahot.front();
        pendingLahot.pop();
        cout << startGuy << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == startGuy)
                continue;

            if (edges[startGuy][i] == 1 && !visited[i])
            {
                pendingLahot.push(i);
                visited[i] = true;
            }
        }
    }
}

void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;

        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;

            printDFS(edges, n, i, visited);
        }
    }
}

void BFS(int **edges, int n)
{
    cout << "BFS" << endl;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printBFS(edges, n, i, visited);
    }

    delete[] visited;
}

void DFS(int **edges, int n)
{
    cout << "DFS" << endl;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printDFS(edges, n, i, visited);
    }

    delete[] visited;
}
int main()
{
    int n;
    int e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    BFS(edges, n);
    cout << endl;
    DFS(edges, n);
}