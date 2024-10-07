#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 101;
vector<int> adj[MAX];
vector<bool> visited;
int sickCom = 0;

void bfs(int start){
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i<adj[x].size(); i++){
            int next = adj[x][i];
            if(!visited[next]){
                visited[next] = true;
                
                sickCom++;
                q.push(next);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
   
    visited.assign(n, false);
    int a, b;
    for(int i = 0; i<m; i++){
        cin >> a >>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    bfs(0);
    cout << sickCom;
    return 0;
}