#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

typedef vector<vector<int> > graph;

class tarjan_bridge {
 private:
  int bridges;
  vector<int> disc, low, parent;
  vector<pair<int, int> > edges;
  int counter;
 public:
  tarjan_bridge (): bridges (0), counter (0)
  {
    //
  }
  
  void dfs (graph g, int tail){
    disc[tail] = low[tail] = counter++;
    
    for (int i=0; i<g[tail].size(); i++){
      int head = g[tail][i];
      if (disc[head] == -1){
        parent[head] = tail;
        dfs (g, head);
        low[tail] = min (low[tail], low[head]);
        
        if (low[head] > disc[tail]){
          edges.push_back (make_pair (tail, head));
          bridges++;
        }
      }
      else  if (head != parent[tail]){
        low[tail] = min (low[tail], disc[head]);
      }
    }
    
  }
  
  vector<pair<int, int> > get_edges (){
    return edges;
  }
  
  int calc_bridges (graph g){
    low.resize (g.size(), -1);
    disc.resize (g.size(), -1);
    parent.resize (g.size(), -1);
    
    for (int i=0; i<parent.size(); i++)
      parent[i] = i;
    
    for (int v=0; v<g.size(); v++)
      if (disc[v] == -1){
        dfs (g, v);
      }
    
    return bridges;
  }
  
  
};
