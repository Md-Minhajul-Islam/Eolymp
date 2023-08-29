// Q: https://www.eolymp.com/en/problems/1453
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 105;
const int INF = 30000;
vector<pii> adj[N];
vector<int> dis(N, INF);

void bell_ford(int s, int n)
{
    dis[s] = 0;
    for(int i = 1; i < n; i++)
        for(int u = 1; u <= n; u++)
            for(pii vpair: adj[u])
            {
                int v = vpair.first;
                int w = vpair.second;
                if(dis[u] != INF && dis[u]+w < dis[v])
                    dis[v] = dis[u]+w ;
            }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    bell_ford(1, n);
    for(int i = 1; i <= n; i++)
        cout << dis[i] <<" ";
    return 0;
}