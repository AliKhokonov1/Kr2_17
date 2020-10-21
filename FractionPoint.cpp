#include"FractionPoint.h"
#include <iostream>
#include <math.h>
using namespace std;
FractionPoint::FractionPoint() {p=0;q = 0;}
FractionPoint::FractionPoint(int p, int q) {this->p=p; this->q=q;}
int FractionPoint::P()const{return p;}
int FractionPoint::Q()const{return q;}
void FractionPoint::setPoint(FractionPoint &l,int k) {
   p=(l.P()/k);
   q=(l.Q()/k);
}
int FractionPoint::nod(int a, int b){
    if ((a==0) || (b==0)) 
        return abs(a)+abs(b);
    if (abs(a)>abs(b)) 
        return nod(abs(a)-abs(b),abs(b));
    else 
        return nod(abs(a),abs(b)-abs(a));
    
}
void   FractionPoint::print() {cout<<"("<<p<<","<<q<<")";}
FractionPoint FractionPoint::operator+(const FractionPoint &m) 
{ 
    FractionPoint r(p*m.Q() + q*m.P(), q*m.Q());
    FractionPoint w(0,0);
    int k=nod(r.P(),r.Q());
    if (k==0) k=1;
    w.setPoint(r,k);
    return w;
}
FractionPoint FractionPoint::operator-(const FractionPoint &m) 
{ 
   FractionPoint r(p*m.Q() - q*m.P(), q*m.Q());
    FractionPoint w(0,0);
    int k=nod(r.P(),r.Q());
    if (k==0) k=1;
    w.setPoint(r,k);
    return w;
}
