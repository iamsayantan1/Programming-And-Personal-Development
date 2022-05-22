#include<bits/stdc++.h>
using namespace std;

template<typename T>
class MapNode   {

public:
    string key;
    T value;
    MapNode* next;
    
    MapNode(string key, T value)    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode() {
        delete next;
    }
};

template<typename T>
class MyMap {
private:
    MapNode<T>** buckets;
    int count = 0;
    int num_buckets = 5;

    int getBucketIndex(string key) {
        int hashcode = 0;
        int base = 1;
        int p = 37;

        for (int i = key.size()-1; i >= 0; i--)   {
            hashcode += key[i]*base;
            base = base*p;
            hashcode = hashcode%num_buckets;
            base = base%num_buckets;
        }
        return hashcode%num_buckets;
    }

    void rehash()   {
        MapNode<T>** temp = buckets;
        
        buckets = new MapNode<T>*[2*num_buckets];
        for (int i = 0; i < 2*num_buckets; i++)   {
            buckets[i] = NULL;
        }
        int old_bucket_size = num_buckets;
        num_buckets *= 2;
        count = 0;
        for (int i =0;i < old_bucket_size; i++) {
            while(temp[i])   {
                insert(temp[i]->key, temp[i]->value);
                temp[i] = temp[i]->next;
            }
        }
        for (int i= 0; i < old_bucket_size; i++)  {
            delete temp[i];
        }
        delete []temp;
    }

public:
    MyMap() {
        buckets = new MapNode<T>*[num_buckets];
        for (int i = 0; i < num_buckets; i++)   {
            buckets[i] = NULL;
        }
    }

    ~MyMap() {
        for (int i = 0; i < num_buckets; i++)   {
            delete buckets[i];
        }
        delete []buckets;
    }

    int size()  {
        return count;
    }

    T value(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<T>* head = buckets[bucketIndex];
        while(head)    {
            if(head->key == key)    {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    void insert(string key, T value)    {
        int bucketIndex = getBucketIndex(key);
        MapNode<T>* head = buckets[bucketIndex];
        while(head)    {
            if(head->key == key)    {
                head->value = value;
                return;
            }
            head = head->next;
        }
        
        MapNode<T>* root = new MapNode<T>(key, value);
        root->next = buckets[bucketIndex];
        buckets[bucketIndex] = root;
        count++;
        double loadFactor = (1.0*count)/num_buckets;
        if(loadFactor>0.7)  {
            rehash();
        }
    }

    T remove(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<T>* head = buckets[bucketIndex];
        MapNode<T>* prev = NULL;
        while(head)    {
            if(head->key == key)    {
                T value = head->value;
                if(!prev)   {
                    buckets[bucketIndex] = head->next;
                }
                else    {
                    prev->next = head->next;
                }
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
    double getLoadFactor() {
        return (1.0*count)/num_buckets;
    }
};

int main()  {

    MyMap<int> ourmap;
    for(int i = 0; i < 10;i++)  {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        // cout<<key<<" "<<value<<endl;
        ourmap.insert(key, value);
        cout <<ourmap.getLoadFactor()<<endl;
    }
    cout <<ourmap.size()<<endl;

    ourmap.remove("abc1");
    ourmap.remove("abc6");

    for(int i = 0; i < 10;i++)  {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout<<key<<" "<<ourmap.value(key)<<endl;
    }
    cout <<ourmap.size()<<endl;
    return 0;
}