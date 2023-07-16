#include <iostream>
#include <climits>
using namespace std;

int findMinVertex( int *weight, bool *visited , int n){
    int minVertex = -1;
    for ( int i = 0 ; i < n ; i++ )
    {
        if( !visited[i] && ( minVertex == -1 || weight[i] < weight[minVertex]))
            minVertex = i;
    }
        return minVertex;
}
void prim ( int ** edges , int n){
      
    bool* visited = new bool[n];
    int * weight = new int[n];
    int *parent = new int[n];

        for( int i = 0 ; i < n ; i++)
        {
            visited[i] = false;
            weight[i] = INT_MAX;
        }

        parent[0] = -1;
        weight[0] = 0;

        for ( int i = 0 ; i < n-1 ; i++)
        {
            int minVertex  = findMinVertex(weight , visited, n);
            visited[minVertex] = true;

            for ( int j = 0 ; j < n ; j++)
            {
                if(!visited[j] && edges[minVertex][j] != 0)
                {
                    if(edges[minVertex][j] < weight[j])
                    {
                        weight[j] = edges[minVertex][j];
                        parent[j] = minVertex;
                    }
                }
            }
        } 

        for ( int i = 1 ; i < n; i++ )
        {
            if( i < parent[i])
                cout << i << " " << parent[i] << " " << weight[i] << endl;
            else 
                cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
}

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;

    int ** edges = new int *[n];

    for ( int i = 0 ; i < n ; i++)
    {
        edges[i] =  new int[n];
        for( int j = 0 ; j < n ; j++)
        {
            edges[i][j] = 0; 
        }
    }

    
    for ( int i  = 0 ; i < n ; i++)
    {
        int f , s , w ;
        cin >>f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }

    prim(edges , n); 
}