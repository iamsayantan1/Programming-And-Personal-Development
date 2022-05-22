#include<bits/stdc++.h>
using namespace std;

void dfsPrint(vector<vector<int>> v, int fv, vector<bool> &visited)    {
    cout<<fv<<" ";
    visited[fv] = true;
    for (int i = 0; i < v.size(); i++)  {
        if(v[fv][i] && visited[i] == false) {
            dfsPrint(v, i, visited);
        }
    }
}

void bfsPrint(vector<vector<int>> v, int fv, vector<bool> &visited)    {
    int n = v.size();
    queue<int> q;
    q.push(fv);
    visited[fv] = true;
    while(!q.empty()) {
        int cv = q.front();
        q.pop();
        cout<<cv<<" ";
        for (int i = 0; i < n ; i++)  {
            if(v[cv][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int dfs(vector<vector<int>> v) {
    int n = v.size();
    vector<bool> visited(n,false);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfsPrint(v, i, visited);
            count++;
        }
    }
    return count;
}

int bfs(vector<vector<int>> v) {
    int n = v.size();
    vector<bool> visited(n,false);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            bfsPrint(v, i, visited);
            count++;
        }
    }
    return count;
}

int main(){
    int v,e;
    cout<<"Enter No. of Vertices and  Edges: "<<endl;
    cin>>v>>e;
    vector<vector<int>> matrix(v,vector<int>(v,0));

    cout<<"Enter Edges: "<<endl;
    for(int i=0;i<e;i++)    {
        int fv, sv;
        cin>>fv>>sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }

    // vector<bool> visited(v,false);

    cout<<"DFS:"<<endl;
    int dcom = dfs(matrix);
    cout<<endl;
    cout<<"BFS:"<<endl;
    int bcom = bfs(matrix);
    cout <<"\nConnect component/components is/are = "<<dcom<<" and only "<<bcom<<endl;
    return 0;
}