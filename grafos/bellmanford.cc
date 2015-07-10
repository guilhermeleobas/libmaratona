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
#define CNT PI/180
#define INF 99999999
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;

bool bellman_ford (graph& g, int source){
  int n = g.size();

  vector<int> distance (n, INF);
  vector<int> predecessor (n, -1);

  distance[source] = 0;
  predecessor[source] = source;

  /*
            cost 
    [tail] ------> [head]
  */

  // para cada v \in V
  for (int i=0; i<g.size(); i++){
    // para cada e \in E
    for (int j=0; j<g.size(); j++){
      for (int k=0; k<g[j].size(); k++){
        int cost = g[j][k].first;
        int head = g[j][k].second;
        int tail = j;

        if (distance[head] > distance[tail] + cost){
          distance[head] = distance[tail] + cost;
          predecessor[head] = tail;
        }
      }
    }
  }

  // verifica ciclos;
  for (int j=0; j<g.size(); j++){
    for (int k=0; k<g[j].size(); k++){
      int cost = g[j][k].first;
      int head = g[j][k].second;
      int tail = j;

      if (distance[head] > distance[tail] + cost){
        // ciclo negativo;
        return false;
      }
    }
  }

  return true;
}

int main (){

  ios::sync_with_stdio(false);
  

  

  

  return 0;
}
