#include<iostream>
using namespace std;

template<typename X, typename Y>
class Pair {
    X x;
    Y y;
public:
    void setX(X x) {
        this->x = x;
    }
    void setY(Y y) {
        this->y = y;
    }
    X getX() const { return x; }
    Y getY() const { return y; }
};

int main()  {

    Pair<int, int> p1;
    p1.setX(2);
    p1.setY(5);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;

    // cout<<endl;

    Pair<double,int> p2;
    p2.setX(2.67);
    p2.setY(5.67);
    cout<<p2.getX()<<" "<<p2.getY()<<endl;

    // cout<<endl;

    Pair<Pair<int,int>,int> p3;
    Pair<int, int> pNew;
    pNew.setX(6);
    pNew.setY(7);
    p3.setX(pNew);
    p3.setY(5.67);
    cout<<p3.getX().getX()<<" "<<p3.getX().getY()<<" "<<p3.getY()<<endl;

    Pair<Pair<int,double>,char> p4;
    Pair<int, double> pNew2;
    pNew2.setX(65.937);
    pNew2.setY(65.937);
    p4.setX(pNew2);
    p4.setY(65.937);
    cout<<p4.getX().getX()<<" "<<p4.getX().getY()<<" "<<p4.getY()<<endl;

    return 0;
}