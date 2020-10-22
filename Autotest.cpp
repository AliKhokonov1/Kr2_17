#include"FractionPoint.h"
#include"FractionVector.h"
#include <fstream>
#include <iostream>
using namespace std;
int Autotest (void) {
    FractionPoint sk;
    int N1,N2;
    ifstream fin("test.txt");
    if (fin.fail()) {
        cout<<"File did not open!"<<endl;
        return 2;
    }
    
    fin>>N1;fin>>N2;
        if (N1!=N2) {
    cout<<"There is not same length even in Autotest!!!"<<endl;
    return 1;
        }
        
    FractionVector q(N1),e(N2);
    FractionVector sum(N1),raz(N2);
    q.setVector(fin);e.setVector(fin);
    
    ifstream vin("restest.txt");
    if (vin.fail()) {
        cout<<"File did not open!"<<endl;
        return 3;
    }
    vin>>N1;vin>>N2;
    if (N1!=N2) {
    cout<<"There is not same length!!!"<<endl;
    return 2;
        }
    sum.setVector(vin);raz.setVector(vin);
    sk=(e*q);
    for (int i=0;i<N1;i++) {
        if ((sum.getVector()[i].P() != (q+e).getVector()[i].P()) || (sum.getVector()[i].Q() != (q+e).getVector()[i].Q())) {
            cout<<"Autotest failed"<<endl;
            return 1;   
            }
    }
    for (int i=0;i<N1;i++) {
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
