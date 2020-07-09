//N = number of vertices

/******O(N^3)******/
//calculates minimum distance between all nodes in graph and stores it in adjacency list 'v'
void floyd_warshall(vector<vector<int>> &v) {
  int n = v.size();
  
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
}

                    
vector<vector<int>> v(n, vector<int>(n, INF)); //adjacency list of graph
//populate adjacency list with edges before calling floyd_warshall
