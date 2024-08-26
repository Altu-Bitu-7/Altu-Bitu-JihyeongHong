#include <iostream>
#include <queue>

using namespace std;

void yosepuse(int n, int k){
    queue<int> q;
    
    for(int i = 1; i<=n; i++){
        q.push(i);
    }
    cout << "<";
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<k-1; j++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        if(i != n-1)
            cout << ", ";
        q.pop();
    }
    cout << ">";
}

int main(){
    //입력
    int n, k;
    cin >> n;
    cin >> k;

    //출력
    yosepuse(n, k);
    return 0;
}