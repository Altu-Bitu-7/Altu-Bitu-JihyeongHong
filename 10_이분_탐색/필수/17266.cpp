#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> &x){
    
    int max = x[0];
    int temp;
    for(int i = 1; i<m-1; i++){
        temp = (x[i+1] - x[i] + 1)/2;
        if(max < temp){
            max = temp;
        }
    }
    temp = n - x[m-1];
    if(max < temp)
        max = temp;
    return max;
}

int main(){
    int n, m;
    int minHeight;
    cin >> n >> m;
    vector<int> x;
    x.assign(m, 0);
    for(int i = 0; i<m; i++){
        cin >> x[i];
    }
    minHeight = solution(n, m, x);
    cout << minHeight;
    return 0;
}