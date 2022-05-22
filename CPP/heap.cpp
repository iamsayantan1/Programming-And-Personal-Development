#include<bits/stdc++.h>
using namespace std;

class MinHeap{
private:
    vector<int> v;
public:
    void insert(int val)    {
        v.push_back(val);
        int ci = v.size()-1;
        int pi = (ci-1)/2;
        while(ci > 0 && v[ci]<v[pi])    {
            swap(v[ci],v[pi]);
            ci = pi;
            pi = (pi-1)/2;
        }
    }
    int removeMin() {
        if(!v.size()) return -1;
        int ans = v[0];
        swap(v[0],v[v.size()-1]);
        v.pop_back();

        int pi = 0;
        while(true) {
            int lci = 2*pi+1;
            int rci = 2*pi+2;
            int min = pi;
            if(lci < v.size() && v[lci]<v[min])    {
                min = lci;
            }
            if(rci < v.size() && v[rci] < v[min]) {
                min = rci;
            }
            if(pi == min)   {
                break;
            }
            swap(v[pi],v[min]);
            pi = min;
        }
        return ans;
    }

    bool empty() {
        return v.size() == 0;
    }
    int size() {
        return v.size();
    }
    int min() {
        if(empty())   return -1;
        return v[0];
    }
};


int main()  {
    MinHeap heap;
    heap.insert(100);
    heap.insert(10);
    heap.insert(15);
    heap.insert(4);
    heap.insert(17);
    heap.insert(21);
    heap.insert(67);

    cout<<heap.size()<<endl;
    cout<<heap.min()<<endl;

    while(!heap.empty()) {
        cout<<heap.removeMin()<<" ";
    }

    return 0;
}