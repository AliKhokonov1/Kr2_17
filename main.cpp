#include"FractionPoint.h"
#include"FractionVector.h"
#include "stdio.h"
#include <fstream>
#include <iostream>
using namespace std;
int Autotest();
int main () {
Autotest();
int N1,N2;
ifstream fin("zhozhozho.txt");
if (fin.fail()) {
        cout<<"File did not open!";
        return 1;
    }
fin>>N1;fin>>N2;
if (N1!=N2) {
    cout<<"There is not same length!!!"<<endl;
    return 0;
}
FractionVector q(N1),e(N2);
q.setVector(fin);
e.setVector(fin);
cout<<"scalar product q and e: "<<endl; (e*q).print(); cout<<endl<<endl;
cout<<"sum q and e: "<<endl; (q+e).printVector(); cout<<endl<<endl;
cout<<"difference q and e: "<<endl; (q-e).printVector();
return 0;
}







