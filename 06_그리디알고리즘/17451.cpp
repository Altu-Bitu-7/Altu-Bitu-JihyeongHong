#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 입력
    int n;
    cin >> n;
    long long minV = 0;
    vector<long long> v(n);
    // 연산
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    for(int i = n-1; i>=0; i--){
        
        if(v[i] > minV){
            minV = v[i];
        } else {
            minV = ((minV - 1)/v[i] + 1 ) * v[i] ;
        }
    }
    // 출력
    cout << minV;
    return 0;
}