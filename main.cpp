#include"FractionPoint.h"
#include"FractionVector.h"
#include "stdio.h"
#include <fstream>
#include <iostream>
using namespace std;
int Autotest();
int main () {
Autotest();
FractionVector q,e;
ifstream fin("zhozhozho.txt");
if (fin.fail()) {
        cout<<"File did not open!"<<endl;
        return 1;
    }
q.setVector(fin);
e.setVector(fin);
cout<<"scalar product q and e: "<<endl; e.scala(q).print(); cout<<endl<<endl;
cout<<"sum q and e: "<<endl; (q+e).printVector(); cout<<endl<<endl;
cout<<"difference q and e: "<<endl; (q-e).printVector();
return 0;
}