#include<iostream>
#include<stack>
#include<string>
using namespace std;

int validParanthesis(string str)  {
    stack<char> s;
    bool valid = true;
    for(int i=0; i<str.size(); i++) {
        if(str[i]== '(' || str[i]== '{' || str[i]== '[' || str[i]== ')' || str[i]== '}' || str[i]== ']')    {
            if(str[i]== '(' || str[i]== '{' || str[i]== '[') {
                s.push(str[i]);
            }
            else   {
                if(s.empty())    {
                    valid = false;
                    break;  
                }
                else if((str[i]== ')' && s.top() == '(') || (str[i]== '}' && s.top() == '{') || (str[i]== ']' && s.top() == '['))    {
                    s.pop();
                }
                else    {
                    valid = false;
                    break;  
                }              
            }
        }
    }
    if(!s.empty())  {
        valid = false;
    }
    if(valid) return true;
    else return false;
}

int main() {
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    if(validParanthesis(str)) cout<<"Parenthesis are valid."<<endl;
    else cout<<"Parenthesis are invalid."<< endl;
    return 0;
}