#include <bits/stdc++.h>
#include "topologicalSort.cpp"
using namespace std;

int main()  {
    string vertex;
    int e;
    cout<<"Enter no. of Vertix and Edge:"<<endl;
    cin>>vertex>>e;

    // vector<string> v;
    map<string, int> v;

	stringstream ss(vertex);

	while (ss.good()) {
		string substr;
		getline(ss, substr, ';');
		v[substr] = 0;
	}

    cout<<"Enter Edges: \n";
    //map<string, map<string, int>> matrix1;
    map<string, vector<string>> matrix1;
    map<string, vector<string>> matrix2;

    // for(int i=0;i<e;i++)   {
    //     string fv, sv;
    //     cin>>fv>>sv;
    //     matrix[fv].push_back(sv);
    // }

    for(int i=0;i<e;i++)   {
        string fv, sv;
        cin>>fv>>sv;
        matrix1[sv].push_back(fv);
        matrix2[fv].push_back(sv);

    }

    cout<<endl;

    topologicalSort(matrix1, matrix2, v);

    return 0;
}