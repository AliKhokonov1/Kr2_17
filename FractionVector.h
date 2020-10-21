#include <fstream>
#include <iostream>
using namespace std;
class FractionPoint;
class FractionVector {
public:
    FractionVector();
    ~FractionVector();
    FractionVector(const FractionVector&b);
    void Clean();
    void SetZero();
    void CopyOnly(const FractionVector&b);
    FractionPoint* getVector();
    void setVector(ifstream &fin);
    void printVector();
    int nod (int a, int b);
    FractionPoint scala(FractionVector &q);
    FractionVector operator+(FractionVector &q);
    FractionVector operator-(FractionVector &q);
    FractionVector operator=(const FractionVector &b);
private:
    FractionPoint *e;
    int N;
};
