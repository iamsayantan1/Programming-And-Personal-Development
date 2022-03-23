<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

void topologicalSort(map<string, vector<string>> matrix1, map<string, vector<string>> matrix2, map<string, int> v)  {

    map<string, int>::iterator it1;
    for (it1 = v.begin(); it1 != v.end(); it1++)
    {
        map<string, vector<string>>::iterator it2;
        for (it2 = matrix1.begin(); it2 != matrix1.end(); it2++)
        {
            /*cout<<it->first<<" - ";
            for(int i=0;i<(it->second).size();i++)  {
                cout<<(it->second[i])<<" ";
            }
            cout<<endl;
            cout<<(it2->first)<<" - "<<(it2->second)<<endl;
            */
             if((it1->first) == (it2->first))  {
                v[it1->first] = (it2->second).size();
                //cout<<(it1->first)<<" - "<<(it1->second)<<endl;
             }
            
        }
        cout<<(it1->first)<<" - "<<(it1->second)<<endl;
    }
    // End of Inorder Matrix

    /*map<string, int>::iterator it2;
    for (it2 = v.begin(); it2 != v.end(); it2++)
    {
        cout<<(it2->first)<<" - "<<(it2->second)<<endl;
    }*/

    queue<string> q;
    vector<string> checked;

    map<string, int>::iterator it3;
    for (it3 = v.begin(); it3 != v.end(); it3++)    {
        if(it3->second == 0)    {
            q.push(it3->first);
            checked.push_back(it3->first);
        }
    }

    /////////////////////////////////////
    

    while (!q.empty())
    {
        string cv = q.front();
        q.pop();
        
        //cout<<cv<<" ";
        //Delete cv from Hashmap v also
        v.erase(cv);

        for(int i=0; i<matrix2[cv].size();i++)  {
            map<string, int>::iterator it4;
            for (it4 = v.begin(); it4 != v.end(); it4++)    {
                if(it4->first == matrix2[cv][i])    {
                    it4->second--;
                }
            }
        }

        // map<string, int>::iterator it0;
        //     for (it0 = v.begin(); it0 != v.end(); it0++)    {
        //         cout<<it0->first<<" - "<<it0->second<<endl;
        //     }
        for(int i=0;i<checked.size();i++)
        cout<<checked[i]<<" ";

        map<string, int>::iterator it5;
        for (it5 = v.begin(); it5 != v.end(); it5++)    {
            // for(int i=0; i<checked.size(); i++) {
            //     if(it5->second == 0  )    {
            //         q.push(it5->first);
            //         checked.push_back(it5->first);
            //     //cout<<" "<<it5->first;
            //     }
            // }

            if(it5->second == 0)    {
                q.push(it5->first);
                checked.push_back(it5->first);
            }
        }
    }
    

=======
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

void topologicalSort(map<string, vector<string>> matrix1, map<string, vector<string>> matrix2, map<string, int> v)  {

    map<string, int>::iterator it1;
    for (it1 = v.begin(); it1 != v.end(); it1++)
    {
        map<string, vector<string>>::iterator it2;
        for (it2 = matrix1.begin(); it2 != matrix1.end(); it2++)
        {
            /*cout<<it->first<<" - ";
            for(int i=0;i<(it->second).size();i++)  {
                cout<<(it->second[i])<<" ";
            }
            cout<<endl;
            cout<<(it2->first)<<" - "<<(it2->second)<<endl;
            */
             if((it1->first) == (it2->first))  {
                v[it1->first] = (it2->second).size();
                //cout<<(it1->first)<<" - "<<(it1->second)<<endl;
             }
            
        }
        cout<<(it1->first)<<" - "<<(it1->second)<<endl;
    }
    // End of Inorder Matrix

    /*map<string, int>::iterator it2;
    for (it2 = v.begin(); it2 != v.end(); it2++)
    {
        cout<<(it2->first)<<" - "<<(it2->second)<<endl;
    }*/

    queue<string> q;
    vector<string> checked;

    map<string, int>::iterator it3;
    for (it3 = v.begin(); it3 != v.end(); it3++)    {
        if(it3->second == 0)    {
            q.push(it3->first);
            checked.push_back(it3->first);
        }
    }

    /////////////////////////////////////
    

    while (!q.empty())
    {
        string cv = q.front();
        q.pop();
        
        //cout<<cv<<" ";
        //Delete cv from Hashmap v also
        v.erase(cv);

        for(int i=0; i<matrix2[cv].size();i++)  {
            map<string, int>::iterator it4;
            for (it4 = v.begin(); it4 != v.end(); it4++)    {
                if(it4->first == matrix2[cv][i])    {
                    it4->second--;
                }
            }
        }

        // map<string, int>::iterator it0;
        //     for (it0 = v.begin(); it0 != v.end(); it0++)    {
        //         cout<<it0->first<<" - "<<it0->second<<endl;
        //     }
        for(int i=0;i<checked.size();i++)
        cout<<checked[i]<<" ";

        map<string, int>::iterator it5;
        for (it5 = v.begin(); it5 != v.end(); it5++)    {
            // for(int i=0; i<checked.size(); i++) {
            //     if(it5->second == 0  )    {
            //         q.push(it5->first);
            //         checked.push_back(it5->first);
            //     //cout<<" "<<it5->first;
            //     }
            // }

            if(it5->second == 0)    {
                q.push(it5->first);
                checked.push_back(it5->first);
            }
        }
    }
    

>>>>>>> d430e7484d1a6fea6c0fcdb61b54cae3c9cd8776
}