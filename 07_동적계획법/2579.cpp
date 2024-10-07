#include <iostream>
#include <vector>

using namespace std;

int dp(int n, vector<int> &stair){
    vector<int> dp(n);
    
    // 한 계단씩 또는 두 계단씩 오를 수 있음
    // 연속된 세개의 계단 못 밟음
    // 마지막 도착 계단은 반드시 밟음 
    dp[0] = stair[0];
    dp[1] = max(stair[0] + stair[1], stair[1]);
    dp[2] = max(stair[0]+stair[2], stair[1] + stair[2]);
    // dp[3]의 경우 생각해보기... 
    for(int i = 3; i<n; i++){
        dp[i] = max(dp[i-2] + stair[i], stair[i-1] + stair[i] + dp[i-3]);
    }
    return dp[n-1];
    
}

int main(){
    int n;
    cin >> n;
    int max;
    vector<int> stair(n);
    for(int i = 0; i<n; i++){
        cin >> stair[i];
    }
    max = dp(n, stair);
    cout << max;
    return 0;
}