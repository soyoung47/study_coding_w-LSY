//#1251. SW문제해결응용 4일차 - 하나로 (Kruskal algorithm)
#include <iostream>
#include <vector>
#include <algorithm> //sort
#define endl '\n'
typedef long long ll;
typedef struct
{
    ll x;
    ll y;
}Pos;
 
using namespace std;
ll Parent[1000] = { 0 };
double E = 0.0;
ll minC = 0;
Pos P[1000];
vector <pair<ll, pair<ll, ll>>> Edge;
 
int Find_Parent(int x)
{
    if (Parent[x] == x) return x;
    else return Parent[x] = Find_Parent(Parent[x]);
}
 
bool SameParent(int x, int y) //check if two edges has same parent (connected)
{
    x = Find_Parent(x);
    y = Find_Parent(y);
    if (x == y) return true;
    else return false;
}
 
void Union(int x, int y) //make two edges have same parent (connect)
{
    x = Find_Parent(x);
    y = Find_Parent(y);
    if (x != y)
    {
        Parent[y] = x;
    }
}
 
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;
    cout.precision(0);
    int tc = 0;
    cin >> tc;
 
    for (int test = 0; test < tc; test++)
    {
        Parent[1000] = { 0 };
        minC = 0.0;
        E = 0.0;
        Edge.clear();
        for (int i = 0; i < 1000; i++)
        {
            P[i].x = -1;
            P[i].y = -1;
        }
        int ni = 0;
        cin >> ni;
        for (int i = 0; i < ni; i++) cin >> P[i].x;
             
        for (int i = 0; i < ni; i++) cin >> P[i].y;
        cin >> E;
 
        for (int i = 0; i < ni; i++)
        {
            for (int j = 0; j < ni; j++)
            {
                ll Dist = ((P[i].x - P[j].x) * (P[i].x - P[j].x)) + ((P[i].y - P[j].y) * (P[i].y - P[j].y));
                Edge.push_back(make_pair(Dist, make_pair(i, j)));
            }
        }
 
        //Solution
        sort(Edge.begin(), Edge.end());
 
        for (int i = 0; i < ni; i++) Parent[i] = i;
         
        for (int i = 0; i < Edge.size(); i++)
        {
            if (SameParent(Edge[i].second.first, Edge[i].second.second) == false)
            {
                Union(Edge[i].second.first, Edge[i].second.second);
                minC = minC + Edge[i].first;
            }
        }
 
        cout << "#" << test + 1 << " " << (double)minC*E << endl;
    }
 
    return 0;
}
