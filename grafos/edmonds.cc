#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<vector<int> > graph;

#define INF 0x3f3f3f3f

long long edmonds_karp (graph &g, vector<vector<int> >& capacity, int s, int t){
  int n = g.size();
  vector<vector<int> > flow (n, vector<int> (n, 0));

  while (true){
    vector<int> parent (n);
    fill (parent.begin(), parent.end(), -1);
    vector<int> M (n, 0);
    
    queue<int> q;
    q.push (s);
    parent[s] = s;
    M[s] = INF;
    while (not q.empty()){
      int u = q.front();
      q.pop();

      if (u == t)
        break;

      for (int i=0; i<g[u].size(); i++){
        int v = g[u][i];

        if (parent[v] != -1)
          continue;

        if (capacity[u][v] - flow[u][v] > 0){
          parent[v] = u;
          M[v] = min (M[u], capacity[u][v] - flow[u][v]);
          
          if (v != t){
            q.push (v);
          }
          else {
            while (v != parent[v]){
              u = parent[v];
              flow[u][v] += M[t];
              flow[v][u] -= M[t];
              v = u;
            }
            break;
          }
        }
      }
    }

    if (parent[t] == -1){
      // nao encontrou um caminho de s ---> t
      long long sum = 0;
      for (int i=0; i<n; i++){
        sum += flow[s][i];
      }

      return sum;
    }
  }

}
