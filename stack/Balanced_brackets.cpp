// this question is from codeforces named as Balanced brackets
#include<bits/stdc++.h>
using namespace std;
// we are making modified push and pop according to question
// we do not need to make a real stack as only '(' and ')' are available
bool letsEND = false;
void pusH(int *top){
    (*top)++;
}
void poP(int *top){
    if((*top) == -1){
        letsEND = true;
    }
    else (*top)--;
}
int main(){
    string s; cin>>s; 
    int top = -1;
    for(auto x: s){
        if(letsEND) {cout<<"NO"; return 0;}
        if(x == '(') pusH(&top);
        else poP(&top);
    }
    if(top == -1){cout <<"YES";}
    else{ cout<<"NO";}
    return 0;
}