#include<iostream>
#include<vector>
using namespace std;


void printdfs(vector<vector<int>> matrix, int sv, vector<bool> &visited)    {
    cout<<sv<<" ";
    visited[sv] = true;
    int n = matrix.size();
    for(int i=0;i<n;i++)    {
        if(matrix[sv][i] == 1 & visited[i] == false)    {
            printdfs(matrix,i,visited);
        }
    }
}

void dfs(vector<vector<int>> matrix)    {
    int components = 0;
    int v = matrix.size();
    vector<bool> visited(v, false);
    for(int i=0;i<matrix.size();i++)    {
        if(!visited[i]) {
            printdfs(matrix, i, visited);
            components++;
        }
    }
    cout<<"\nNo of components: "<<components;
}
