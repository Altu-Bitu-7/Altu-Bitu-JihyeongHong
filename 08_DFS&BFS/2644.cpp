#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 101;
vector<int> adj[MAX];
vector<bool> visited;
int num = -1;

void dfs(int start, int end, int depth){
    if(start == end){
        num = depth;
        return;
    }
    
    visited[start] = true;
    
    for(int i = 0; i<adj[start].size(); i++){
        int next = adj[start][i];
        if(visited[next]) continue;
        
        dfs(next, end, depth+1);
        if(num != -1) return;
        
    }
    
}

int main(){
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    visited.assign(n, false);
    int x, y;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    dfs(a-1, b-1, 0);
    cout << num;
    return 0;
}