#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()  {
    string str;
    bool flag = true;
    stack<char> s;
    int stpr = -1;
    char temp = '\0';
    cout<<"Enter string: ";
    cin>>str;


    // ------------------------------------- One Method ---------------------------------------
    // while(flag) {
    //     flag=false;
    //     for(int i=str.size()-1; i>=0; i--)  {
    //         if(str[i] == temp) {
    //             s.pop();
    //             temp = '\0';
    //             flag = true;
    //         }
    //         else    {
    //             s.push(str[i]);
    //             temp = str[i];
    //         }
    //     }
    //     temp = '\0';
    //     str = "";
    //     if(s.empty()) {
    //         break;
    //     }
    //     while(!s.empty()) {
    //         str += s.top();
    //         s.pop();
    //     }        
    // }
    // ----------------------------------------------------------------------------------------------

    // -----------------------------------Another Method---------------------------------------------
    // for(int i=str.size()-1; i>=0; i--)  {
    //     if(s.empty())   {
    //         s.push(str[i]);
    //     }
    //     else    {
    //         if(str[i] == s.top())   {
    //             s.pop();
    //         }
    //         else    {
    //             s.push(str[i]);
    //         }
    //     }
    // }
    // while(!s.empty()) {
    //     cout<<s.top();
    //     s.pop();
    // }  
    // cout<<" ";
    // ----------------------------------------------------------------------------------------------

    // ------------------------------------Best method-----------------------------------------------
    for(int i=0; i<str.size();i++)  {
        if(stpr == -1 || str[i] != str[stpr])   {
            stpr++;
            str[stpr] = str[i];
        }
        else    {
            stpr--;
        }
    }

    string ans = "";
    for (int i = 0; i <= stpr; i++) {
        ans.push_back(str[i]);
    }
    // ----------------------------------------------------------------------------------------------
    cout<<ans<<" ";

    return 0;
}