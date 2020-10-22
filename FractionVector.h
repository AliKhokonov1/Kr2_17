class FractionPoint;
class FractionVector {
public:
    FractionVector(int M);
    ~FractionVector();
    FractionVector(const FractionVector&b);
    void Clean();
    void SetZero();
    void CopyOnly(const FractionVector&b);
    FractionPoint* getVector();
    void setVector(ifstream &fin);
    void printVector();
    int nod (int a, int b);
    FractionPoint operator*(FractionVector &q);
    FractionVector operator+(FractionVector &q);
    FractionVector operator-(FractionVector &q);
    FractionVector operator=(const FractionVector &b);
private:
    FractionPoint *e;
    int N;
};
