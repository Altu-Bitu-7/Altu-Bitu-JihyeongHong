#include <iostream>
#include <vector>

using namespace std;
// 체스판 최대 크기
const int MAX = 8;


// A1과 같이 주어질 때 (1, 1)처럼 좌표로 바꾸어서 저장하는 함수
void reset(pair<int, int> &one, string oneRes){
    // 알파벳을 숫자로 변환
    char ch = oneRes[0];
    one.first = ch - 64;
    // string으로 주어진 숫자를 int로 변환
    ch = oneRes[1];
    one.second = ch -'0';
}

// 킹과 돌 움직이는 함수
// 생각할 점 : 돌이 움직인다는 의미 == 움직인 킹과 움직이기 전 돌 합체
void moveKing(pair<int, int> &king, pair<int, int> &stone, string command){
    // 범위를 벗어날 경우를 고려하기 위해 미리 다른 변수 지정
    int k1 = king.first, k2 = king.second;
    int s1 = stone.first, s2 = stone.second;
    // command 입력 받고 돌이 움직여야 할 경우에 움직여줌
    if(command == "R"){
        k1 += 1;
        if(s1 == k1 && s2 == k2){
        s1 += 1;
        }
    }
    if(command == "L"){
        k1 -= 1;
        if(s1 == k1 && s2 == k2){
        s1 -= 1;
    }
    }
    if(command == "B"){
        k2 -= 1;
        if(s1 == k1 && s2 == k2){
        s2 -= 1;
    }
    }
    if(command == "T"){
        k2 += 1;
        if(s1 == k1 && s2 == k2){
           ;
        s2 += 1;
    }
    }
    if(command == "RT"){
        k1 += 1;
        k2 += 1;
        if(s1 == k1 && s2 == k2){
        s1++;
        s2++;
    }
    }
    if(command == "LT"){
        k1 -= 1;
        k2 += 1;
        if(s1 == k1 && s2 == k2){
        s1--;
        s2++;
    }
    }
    if(command == "RB"){
        k1 += 1;
        k2 -= 1;
        if(s1 == k1 && s2 == k2){
        s1++;
        s2--;
    }
    }
    if(command == "LB"){
        k1 -= 1;
        k2 -= 1;
        if(s1 == k1 && s2 == k2){
        s1--;
        s2--;
    }
    }
    // 범위를 벗어나면 킹과 돌을 움직일 필요가 없으므로 리턴
    if(k1 > MAX || k2 > MAX || k1 <=0 || k2 <=0 ||
        s1 > MAX || s2 > MAX || s1 <= 0 || s2 <= 0){
        return;
    }
    
    // 범위를 벗어나지 않았을 경우 위치 변경
    king.first = k1;
    king.second = k2;
    
    stone.first = s1;
    stone.second = s2;
    
}

// 좌표로 주어진 위치를 A1과 같이 변환
string changeToRes(pair<int, int> &one){
    char ch1 = one.first + 64;
    char ch2 = one.second + '0';
    return {ch1, ch2};
}

int main(){
    
    int n;
    string command;
    pair<int, int> king;
    pair<int, int> stone;
    
    string kingRes;
    string stoneRes;
    // 초기값 입력
    cin >> kingRes;
    cin >> stoneRes;
    // 몇 번 입력할 지 결정
    cin >> n;
    // 초기값을 각각 저장
    reset(king, kingRes);
    reset(stone, stoneRes);
    
    // 킹과 돌 움직임
    for(int i = 0; i<n; i++){
        cin >> command;
        moveKing(king, stone, command);
    }
    // 해당 좌표를 문자로 변환
    kingRes = changeToRes(king);
    stoneRes = changeToRes(stone);
    // 출력
    cout << kingRes <<"\n";
    cout << stoneRes << "\n";
    
    return 0;
}