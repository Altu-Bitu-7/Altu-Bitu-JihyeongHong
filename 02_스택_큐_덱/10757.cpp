#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

void plusBigNum(string s1, string s2) {
    string num1 = s1;
    string num2 = s2;
    string result = "";
    int carry = 0;
    int n1 = num1.length();
    int n2 = num2.length();
    
    if (num1.length() < num2.length()) {
        swap(num1, num2);
    }
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    
    
    for (int i = 0; i < n1; ++i) {
        int digit1 = num1[i] - '0';
        int digit2 = (i < n2) ? num2[i] - '0' : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    
    if (carry == 1) {
        result += carry + '0';
    }
    
    reverse(result.begin(), result.end());
    
    cout << result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    plusBigNum(s1, s2);
    
    return 0;
}