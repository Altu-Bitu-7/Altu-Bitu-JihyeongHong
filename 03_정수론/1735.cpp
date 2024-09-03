#include <iostream>
#include <algorithm>

using namespace std;


int getGcd(int a, int b){
    while(b != 0){
        a %= b;
        swap(a, b);
    }
    return a;
}



void addIrrFraction(int son1, int mom1, int son2, int mom2){
    int realMom = mom1*mom2;
    
    int realSon = son1*mom2 + son2*mom1;
    
    int gcd = getGcd(realMom, realSon);
    
    realMom /= gcd;
    realSon /= gcd;
    cout << realSon << " " << realMom;
}

int main(){
    int mom1, mom2, son1, son2;
    cin >> son1 >> mom1 >> son2 >> mom2;
    addIrrFraction(son1, mom1, son2, mom2);
    return 0;
}