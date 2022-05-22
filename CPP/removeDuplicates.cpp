#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

template<typename T>
vector<T> removeDuplicates(vector<T> v)    {
    unordered_map<T, bool> map;
    vector<T> newvec;
    for (auto i = 0; i < v.size(); i++)  {
        if(map.count(v[i]) == 0) {
            map[v[i]] = 0;
            newvec.push_back(v[i]);
        }
    }
    return newvec;
}

int main()  {
    vector<int> v = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 3, 4, 6, 1, 1, 3, 9};
    vector<int> vec = removeDuplicates(v);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return 0;
}