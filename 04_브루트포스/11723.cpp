#include <iostream>
#include <vector>

using namespace std;

int comAdd(int s, int x){
    // x에 해당하는 이진수 비트 만들기
    int a = 1;
    a = a << (x-1);
    
    // 해당 비트에 존재하지 않으면 추가
    if( (a & s) == 0){
        s = s | a;
    }
    
    return s;
}

int comRemove(int s, int x){
    // x에 해당되는 비트 만들기
    int a = 1;
    a = a << (x-1);
    // 해당 비트에 존재하면 삭제
    if( (a & s) != 0){
        s = s & (~a);
    }
    return s;
}

int comCheck(int s, int x){
    // x에 해당되는 비트 만들기
  int a = 1;
  a = a << (x-1);
   // s에 존재하면 1, 없으면 0 출력
  if((a & s) == 0){
      return 0;
  }
  return 1;
}

int comToggle(int s, int x){
    // xor을 이용해서 toggle 구현
    int a = 1; 
    a = a << (x-1);
    s = s ^ a;
    return s;
}

int comAll(int s){
    // 전체 비트 1로 채우기
    int a= 1 << 20;
    a -= 1;
    return a;
}

int comEmpty(int s){
    // 공집합 만들기
    return 0;
}


int main(){
    ios::sync_with_stdio(false);  
    cin.tie(NULL);  
    // 입력
    int m;
    cin >> m;
    // 공집합 생성
    int s = 0;
    // 메뉴얼 만들기
    vector<string> mani = {"add", "remove", "check", "toggle", "all", "empty"};
    string user; // 사용자로부터 입력받을 것 저장
    int x;
    // check에서 보여줄 결과 저장
    int res;
    
    for(int i = 0; i<m; i++){
        // 입력
        cin >> user;
        if(user != mani[4] && user != mani[5])
            cin >> x;
        // 계산 및 출력
        if(user == mani[0]) // add
        {
            s = comAdd(s, x);
            
        }
        if(user == mani[1]){
            s = comRemove(s, x);
            
        }
        if(user == mani[2]){
            res = comCheck(s, x);
            cout << res <<"\n";
            
        }
        if(user == mani[3]){
            s = comToggle(s, x);
            
        }
        if(user == mani[4]){
            s = comAll(s);
            
        }
        if(user == mani[5]){
            s = comEmpty(s);
            
        }
        
        
        
    }
    
    return 0;
}