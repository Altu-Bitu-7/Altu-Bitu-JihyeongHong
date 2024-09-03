#include <iostream>
#include <vector>
#include <set>

using namespace std;


void getWheel(int n, int k){
    // 바퀴 만들기
    vector<string> wheel;
    set<string> used;
    
    wheel.assign(n, "?");
    int order = 0;
    
    int first;
    string second;
    
    for(int i = 0; i<k; i++){
        cin >> first >> second;
        order += first;
        //원형으로 변경
        if(order >= n)
            order %= n;
        
        // 알파벳 하나가 두 개 이상 들어오는 경우
        if( wheel[order] == "?" && used.count(second) > 0 )
        {
            cout << "!";
            return;
        }
        
        
        
        //같은 자리에 다른 알파벳 들어가는 경우
        if(wheel[order] != "?" && second != wheel[order])
        {
            cout << "!";
            return;
        }
        used.insert(second);
        wheel[order] = second;
        
    }
    
    //출력
    
    for(int i = 0; i<n; i++){
        if(order < 0){
            order += n;
        }
       cout << wheel[order];
       order--;
    }
    return;
}

int main(){
    int n, k;
    cin >> n >> k;
    getWheel(n, k);
    return 0;
}