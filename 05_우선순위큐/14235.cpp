#include <iostream>
#include <queue>

using namespace std;

int main(){
    // 선물의 가치 담을 우선순위 큐
    priority_queue<int> gift;
    
    int n, a, value; // n은 장소 방문할 횟수, a는 가져올 선물 개수, value는 선물 하나당 가치
    // 입력
    cin >> n;
    // 선물 주기
    for(int i = 0; i<n; i++){
        cin >> a;
        // 애들 집 방문할 시
        if(a == 0){ // 선물 다 떨어졌는데 애들 집 감
            if(gift.empty()){
                cout << "-1\n";
            } else{ // 충전한 선물 중 가치 젤 큰 거 주기
                cout << gift.top() <<"\n";
                gift.pop();
            }
        } else{ // 선물 충전하러감
            for(int k = 0; k<a; k++){
                cin >> value;
                gift.push(value);
            }
        }
    }
    return 0;   
}