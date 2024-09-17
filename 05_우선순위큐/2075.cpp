#include <iostream>
#include <queue>

using namespace std;


// n번째로 큰 수 구하기
int getNthBigNum(int n){
    // 최대힙 사용시 메모리 초과 -> 최소 힙 사용
    int size = n*n;
    int num;
    priority_queue<int, vector<int>, greater<int>> nums;
    
    
    for(int i = 0; i<size; i++){
        cin >> num;
        // n만큼 꽉 차있지 않으면 우선순위큐에 넣음
        if(nums.size() < n){
            nums.push(num);
        } else if ( num > nums.top()){ // 큐 안에 들어있는 것 중 젤 작은 거 보다 크면 넣음
            nums.pop();
            nums.push(num);
        }
        
    }
    
    return nums.top();
}

int main(){
    // 입출력 시간 초과 방지
    ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	// 입력
    int n;
    cin >> n;
    // n번째 큰 수 출력
    int bigNum = getNthBigNum(n);
    cout << bigNum;
    return 0;
}