#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 알파벳 몇 개 있는지 벡터로 변환
vector<int> getAlpaNum(string original){
    vector<int> alpa;
    alpa.assign(26, 0);
    for(int i = 0; i<original.length(); i++){
        alpa[original[i] - 65]++;
    }
    return alpa;
}

// 펠린드롬 만들기
string getPel(vector<int> alpa){
    string pel = "";
    string halfPel;
    // 홀수 일 경우 odd에 저장
    char odd;
    // 홀수인 알파벳 몇 개인지 저장
    // 홀수인 알파벳이 두 개 이상이면 못 만듦
    int oddCnt = 0;
    for(int i = 0; i<26; i++){
        if(alpa[i] %2 == 1){
            oddCnt++;
            odd = i + 65;
            
        }
        
        if(oddCnt >= 2){
            return "I'm Sorry Hansoo";
        }
        // 펠린드롬 1/2 완성
        for(int j = 0; j<alpa[i]/2; j++){
            
            pel += i + 65;
        }
    }
    
    halfPel = pel;
    // 홀수면 가운데에 두기
    if(oddCnt == 1){
        pel += odd;
    }
    
    reverse(halfPel.begin(), halfPel.end());
    // 진짜 완성
    pel += halfPel;
    
    
    return pel;
}


int main(){
    
    string original;
    cin >> original;
    vector<int> alpabet;
    string pel;
    
    // 연산
    alpabet.assign(26, 0);
    alpabet = getAlpaNum(original);
    pel = getPel(alpabet);
    
    // 출력
    cout << pel;
    return 0;
}