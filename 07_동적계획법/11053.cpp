#include <iostream>
#include <vector>

using namespace std;

int getIncrease(int n, vector<int> &arr){
    vector<int> dp(n, 1);
    int len = 1;
    
    for ( int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        len = max(len, dp[i]);
    }
    return len;
}

int main(){
    int n;
    int len;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    len = getIncrease(n, arr);
    cout << len;
    return 0;
}