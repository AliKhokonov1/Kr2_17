#include <fstream>
#include <iostream>
#include"FractionPoint.h"
#include"FractionVector.h"
using namespace std;
FractionVector::FractionVector(int M){
	SetZero();
	N=M;
	e=new FractionPoint[N];	
}
FractionVector::~FractionVector() {
    Clean();
}
void FractionVector::CopyOnly(const FractionVector &b) {
		N = b.N;
		e=new FractionPoint[N];
		for (int i = 0; i < N; i++) {
			e[i] = b.e[i];
		}
}
FractionVector::FractionVector(const FractionVector &b) {
CopyOnly(b);
}
FractionVector FractionVector::operator=(const FractionVector &b) 
{   if (this!=&b) 
    {     Clean();
          CopyOnly(b);
        }
return *this;
}
void FractionVector::Clean(){delete[] e;SetZero();}
void FractionVector::SetZero(){e=NULL;N=0;}
FractionPoint* FractionVector::getVector(){
	return e;
}
void FractionVector::setVector(ifstream &fin){
	double a,b;
	for(int i = 0;i < N; i++){
	fin>>a>>b;
		e[i]=FractionPoint(a,b);
	}
}
void FractionVector::printVector(){
    cout<<"(";
	for(int i = 0; i < N; i++){
		cout<<"("<<e[i].P()<<","<<e[i].Q()<<")";
	}
	cout<<")";
}
int FractionVector::nod(int a, int b){
    if ((a==0) || (b==0)) 
        return abs(a)+abs(b);
    if (abs(a)>abs(b)) 
        return nod(abs(a)-abs(b),abs(b));
    else 
        return nod(abs(a),abs(b)-abs(a));
    
}
FractionPoint FractionVector::operator*(FractionVector &q){
	FractionPoint s(0,1);
	FractionPoint w(0,1);
	for(int i = 0; i < N; i++){
		s=s+FractionPoint(e[i].P()*q.getVector()[i].P(),e[i].Q()*q.getVector()[i].Q());		
	}
	int k=nod(s.P(),s.Q());
    if (k==0) k=1;
    w.setPoint(s,k);
    return w;
}
FractionVector FractionVector::operator+(FractionVector &q){
	FractionVector p(N);
	for(int i = 0; i < N; i++){
		p.getVector()[i]=q.getVector()[i]+e[i];
	}
	return p;
}
FractionVector FractionVector::operator-(FractionVector &q){
	FractionVector p(N);
	for(int i = 0; i < N; i++){
		p.getVector()[i]=q.getVector()[i]-e[i];
	}
	return p;
}
