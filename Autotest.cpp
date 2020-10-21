#include"FractionPoint.h"
#include"FractionVector.h"
#include <fstream>
#include <iostream>
using namespace std;
int Autotest (void) {
    int N=3;
    FractionPoint sk;
    FractionVector q,e,sum,raz;
    ifstream fin("test.txt");
    if (fin.fail()) {
        cout<<"File did not open!"<<endl;
        return 2;
    }
    q.setVector(fin);e.setVector(fin);
    ifstream vin("restest.txt");
    if (vin.fail()) {
        cout<<"File did not open!"<<endl;
        return 3;
    }
    sum.setVector(vin);raz.setVector(vin);
    sk=e.scala(q);
    for (int i=0;i<N;i++) {
        if ((sum.getVector()[i].P() != (q+e).getVector()[i].P()) || (sum.getVector()[i].Q() != (q+e).getVector()[i].Q())) {
            cout<<"Autotest failed"<<endl;
            return 1;   
            }
    }
    for (int i=0;i<N;i++) {
        if ((raz.getVector()[i].P() != (q-e).getVector()[i].P()) || (raz.getVector()[i].Q() != (q-e).getVector()[i].Q())) {
            cout<<"Autotest failed"<<endl;
            return 2;
        }  
    }
    if ((sk.P() != 1) || (sk.Q() != 1)) {
       cout<<"Autotest failed"<<endl;
            return 3; 
    }
    cout<<"Autotest passed!"<<endl;
    return 0;
}