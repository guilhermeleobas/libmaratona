/*
    This is the Andrew's monotone chain convex hull algorithm.
    Runs in O(N * log N), with N being the number of points given.
 */
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iomanip>
#include <locale>
using namespace std;

#define PI acos(-1)
#define endl "\n"
typedef long long int ll;

typedef struct sPoint {
    int x, y;
    sPoint(int _x, int _y) {x=_x; y=_y;}
} point;

bool comp(point a, point b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int cross(point a, point b, point c) //AB x BC
{
    a.x-=b.x;  a.y-=b.y;
    b.x-=c.x;  b.y-=c.y;
    
    return a.x*b.y - a.y*b.x;
}

bool isCw(point a, point b, point c) //Clockwise
{ return cross(a, b, c) < 0; }

// >= if you want to put collinear points on the convex hull
bool isCcw(point a, point b, point c) //Counter Clockwise
{ return cross(a, b, c) > 0; }

//TODO: Better this algorithm, use one array instead of two vectors (upper and lower), and use indexes for control.
vector<point> convexHull(vector<point> p)
{
    vector<point> u, l; // Upper and Lower hulls
    
    sort(p.begin(), p.end(), comp);
    for(unsigned int i=0; i < p.size(); i++)
    {
        while(l.size() > 1 && !isCcw(l[l.size()-1], l[l.size()-2], p[i]))
            l.erase(l.begin()+(l.size()-1));
        l.push_back(p[i]);
    }
    
    for(int i=p.size()-1; i >=0; i--)
    {
        while(u.size() > 1 && !isCcw(u[u.size()-1], u[u.size()-2], p[i]))
            u.erase(u.begin()+(u.size()-1));
        u.push_back(p[i]);
    }
    
    u.erase(u.begin()+(u.size()-1));
    l.erase(l.begin()+(l.size()-1));
    l.insert(l.end(), u.begin(), u.end());
    return l;
}
