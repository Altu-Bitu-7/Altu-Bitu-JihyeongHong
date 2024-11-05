#include <iostream>
#include <vector>
#include <algorithm>
// 10815 numver card
using namespace std;

int binarySearch(int n, int key, vector<int> &nums){
    int left = 0;
    int right = n-1;
    int mid;
    
    while(left <= right){
        mid = (left + right) / 2;
        if(nums[mid] == key){
            return 1;
        }
        else if (nums[mid] > key){
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return 0;
}

vector<int> solution(int n, vector<int> &card, int m, vector<int> &numbers){
    vector<int> answer(m, 0);
    sort(card.begin(), card.end());
    
    for(int i = 0; i<m; i++){
        answer[i] = binarySearch(n, numbers[i], card);
    }
    return answer;
}


int main(){
    int n;
    cin >> n;
    vector<int> card;
    card.assign(n, 0);
    for(int i = 0; i<n; i++){
        cin >> card[i];
    }
    int m;
    cin >> m;
    vector<int> numbers;
    numbers.assign(m, 0);
    for(int i = 0; i<m; i++){
        cin >> numbers[i];
    }
    vector<int> res(m, 0);
    res = solution(n, card, m, numbers);
    for(int i = 0; i<m; i++){
        cout << res[i] << " ";
    }
    return 0;
}