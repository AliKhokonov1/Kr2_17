#include <fstream>
#include <iostream>
using namespace std;
class FractionPoint {
public:
    FractionPoint ();
    FractionPoint (int p, int q);
    int P()const;
    int Q()const;
    void setPoint(FractionPoint &l,int k);
    int nod (int a, int b);
    void print();
    FractionPoint operator+(const FractionPoint &m);
    FractionPoint operator-(const FractionPoint &m);
private:
    int p;
    int q;
};
