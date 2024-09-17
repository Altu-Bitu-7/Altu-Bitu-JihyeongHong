#include <iostream>

using namespace std;

// 종말의 수 구하기
int getNumOfDeath(int n){
    int cnt = 1; // 몇번째 종말의 수인지 저장
    int test = 666; // test할 수
    // 666 연속 확인할 때 쓸 변수들
    int temp1; // 나머지
    int temp2; // 나눠지는 수 ex ) 1666-> 166->16->1
    int past; // 이전 반복문에서의 나머지 ex ) 1876에서 현재 temp1이 7이면 past는 6
    int suc; // 연속된 만큼의 횟수
    while(true){
        if(cnt == n){ // n번째 종말의 수일 경우 return
            return test;
        }
        // 666에서 점점 수를 늘려가면서 종말의 수인지 체크하기
        test++;
        // 초깃값 세팅
        temp2 = test;
        past = 6; 
        suc = 0;
        // 자릿수만큼 반복
        while(temp2 > 0){ 
            // 나머지 구하기
            temp1 = temp2 % 10;
            if(temp1 == 6 && past == 6) // 이전에도 6이고 지금도 6이면 연속횟수 증가
                suc++;
            else if(temp1 == 6 && past != 6) // 이전에는 6아니고 현재 6이면 연속횟수는 1
                suc = 1;
            else // 그밖의 경우는 다 0
                suc = 0;
            temp2 /= 10;
            // 이전의 나머지 계산
            past = temp1;
            // 연속횟수가 3이상이면 cnt를 증가시키고 반복문 탈출
            if(suc >= 3){
                
                cnt++;
                break;
            }
        }
        
       
    }
    
}

int main(){
    int n, res;
    // 입력
    cin >> n;
    // 계산
    res = getNumOfDeath(n);
    // 출력
    cout << res;
    return 0;
}