#include <iostream>
#include <stack>
#include <queue> 
#include <string>

using namespace std;

void checkBrakets(string s){
    stack<char> st;
    char test;
    for(int i = 0; i<s.length(); i++){
        test = s.at(i);
        
        
        if( !st.empty() && ((test == ')' && st.top() == '(') 
        || (test == ']' && st.top() == '[')) )
            st.pop();
        else if(test == '(' || test == '[' || test == ')' || test == ']' ){
            st.push(test);
            
        }
    }
    
    if(st.empty())
        cout << "yes\n";
    else
        cout << "no\n";
}

int main(){
    string s;
    queue<string> q;
    while(true){
        getline(cin, s);
        if(s == ".") break;
        q.push(s);
        
    }
    
    while(!q.empty()){
        checkBrakets(q.front());
        q.pop();
    }
    return 0;
}