#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
bool canDivide(vector<int> &lecture, int m, int mid){
    int count = 1;
    int sum = 0;
    for(int i : lecture){
        if(sum + i > mid){
            count++;
            sum = i;
            if(count > m)
                return false;
        } else {
            sum += i;
        }
    }
    return true;
}

int solution(int n, int m, vector<int> &lecture){
    int left = *max_element(lecture.begin(), lecture.end());
    int right = accumulate(lecture.begin(), lecture.end(), 0);
    int answer = right;
    while(left <= right){
        int mid = left + (right - left)/2;
        
        if(canDivide(lecture, m, mid)){
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}

int main(){
    int n, m;
    cin >> n >>m;
    vector<int> lecture(n, 0);
    for(int i = 0; i<n; i++){
        cin >> lecture[i];
    }
    int res = solution(n, m, lecture);
    cout << res;
    return 0;
}