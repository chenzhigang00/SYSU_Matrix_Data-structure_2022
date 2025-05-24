#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<char> s;
    int cnt1, cnt2, cnt3;
    cnt1 = cnt2 =cnt3=0;
    string str;
    cin >> str;
    bool flag = true;
    char t;
    for(char c: str){
        switch(c){
            case '{':
            case '(':
            case '[':  s.push(c); break;
            case '}':  
                if(s.empty()){ flag = false; break;}   // 记得加上这句
                t = s.top(); 
                if(t!='{') flag=false;
                else s.pop();
                break;
            case ']':
                if(s.empty()){ flag = false; break;}
                t = s.top(); 
                if(t!='[') flag=false;
                else s.pop();
                break;
            case ')':
                if(s.empty()){ flag = false; break;}
                t = s.top(); 
                if(t!='(') flag=false;
                else s.pop();
                break;
        }
        if(!flag) break;
        
        /*
        s.push(c);
        switch(c){
            case '(': cnt1++; break;
            case '[': cnt2++; break;
            case '{': cnt3++; break;
            case ')': cnt1--; break;
            case ']': cnt2--; break;
            case '}': cnt3--; break;
        }
            */
    } // for
    if(!s.empty()){
        flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}




