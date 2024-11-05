#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canDivide(vector<int> &length, int m, int mid){
    int count = 0;
    for(int i : length){
        count += i / mid;
        if(count >= m)
            return true;
    }
    return count >= m;
}
int solution (int m, int n, vector<int> &length){
    int left = 1;
    int right = *max_element(length.begin(), length.end());
    int answer = 0;
    int mid;
    while(left <= right){
        mid = left + (right - left)/2;
        
        if(canDivide(length, m, mid)){
            answer = mid;
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    return answer;
    
}

int main(){
    int m,n;
    cin >> m >> n;
    vector<int> length(n, 0);
    for(int i = 0; i<n; i++){
        cin >> length[i];
    }
    
    int maxLength = solution(m, n, length);
    cout << maxLength;
    return 0;
}