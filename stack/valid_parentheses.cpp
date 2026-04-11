// this is problem number 20 on leetcode 
// ()[]{()}   → YES
// {[(])}     → NO
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;  cin>>s;
    vector<char> char_stack(s.length(),'a');
    int top = -1;
    for(auto x: s){
        if(x == '(' || x == '{' || x == '['){
            top++;
            char_stack[top] = x;
        }
        else{
            if(top == -1) {cout<<"INVALID"; return 0;}
            if(x == ')' && char_stack[top] == '(') top--;
            else if(x == ']' && char_stack[top] == '[') top--;
            else if(x == '}' && char_stack[top] == '{') top--;
            else{ cout<<"INVALID"; return 0; }
        }
    }
    if(top == -1) {cout<<"VALID"; return 0;}
    else{ cout<<"INVALID"; }
    return 0;
}
