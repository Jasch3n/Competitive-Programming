#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int visited[100001];
int hasCat[100001];
vector<int> adj[100001];
int n, m, answer = 0;



void dfs(int v, int catCount)
{
    if (visited[v]) return;
    visited[v] = 1;
    int currConsecutiveCount;
    currConsecutiveCount = hasCat[v] == 1 ? catCount + 1 : 0;
    if (currConsecutiveCount > m)
    {
        return;
    }
    else if(adj[v].size() == 1 && v != 1)
    {
        answer ++;
    }
    else
    {
        for(auto node: adj[v])
        {
            dfs(node, currConsecutiveCount);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> hasCat[i];
    }
    for (int i = 1; i <= n - 1; i ++)
    {
        int currNode, neighbor; cin >> currNode >> neighbor;
        adj[currNode].push_back(neighbor);
        adj[neighbor].push_back(currNode);
    }
    dfs(1, 0);
    cout << answer;
}