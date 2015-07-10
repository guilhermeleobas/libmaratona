/*
Problema - Final mundial de 2008
http://br.spoj.com/problems/MINIMO/
Guilherme Leobas
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
#define INF 99999999
int graph[110][110];
int p[110][110];
vector<vector<vector<int> > > vv;

void floyd_warshall (int n){

  
  for (int k=0; k<n; k++){
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        if (graph[i][j] > graph[i][k] + graph[k][j]){
          graph[i][j] = graph[i][k] + graph[k][j];
          p[i][j] = p[k][j];
        }
        // graph[i][j] = min (graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }
}

int main (){

  ios::sync_with_stdio(false);

  int n, m, c, u, v, w, t, test=0;

  while (true){
    cin >> n >> m;
    if (!cin)
      break;

    vv.resize (n);
    for (int i=0; i<vv.size(); i++)
      vv[i].resize (n);

    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        if (i == j){
          graph[i][j] = 0;
          p[i][j] = 0;
        }
        else{
          graph[i][j] = INF;
          p[i][j] = i;
        }
      }
    }

    for (int i=0; i<m; i++){
      cin >> u >> v >> w;
      graph[u-1][v-1] = min (graph[u-1][v-1], w);
    }

    floyd_warshall (n);

    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        cout << graph[i][j] << ' ';
      }
      cout << endl;
    }

    cout << endl;
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        cout << p[i][j]+1 << ' ';
      }
      cout << endl;
    }
  } 
  
  

  

  return 0;
}

