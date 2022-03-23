#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int main()  {
    vector<string> vec;
    string s;
    stack<string> container;
    cout<<"Enter Polish Notation: ";
    cin>>s;
    while(s != "q") {
        vec.push_back(s);
        cin>>s;
    }
    
    for(int i=0; i<vec.size(); i++) {
        if(vec[i] == "+" || vec[i] == "-" || vec[i] == "*" || vec[i] == "/")    {
            int a = stoi(container.top());
            container.pop();
            int b = stoi(container.top());
            container.pop();
            int c;
            if(vec[i] == "+")   {
                c = a+b;
            }
            else if(vec[i] == "-")  {
                c = b-a;
            }
            else if(vec[i] == "*")  {
                c = b*a;
            }
            else  {
                c = b/a;
            }
            container.push(to_string(c));
        }
        else    {
            container.push(vec[i]);
        }
    }
    
    cout<<"Answer = "<<container.top()<<endl;
    return 0;
}