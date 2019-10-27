typedef struct Node{
    double *data;//array of points
    int nP;//number of points
    int dim;//number of dimensions
    double *vp;//vantage point
    double md;//median
    int idx; //index in original array
    struct Node *left;
    struct Node *right;
}vptree;
double *createDistArray(vptree* T);
vptree * getInner(vptree * T);
vptree * getOuter(vptree * T);
double getMD(vptree * T);
double * getVP(vptree * T);
int getIDX(vptree * T);
vptree *buildTree(double *data,int nP,int dim);
void insert(vptree* T);
vptree *buildvp(double *X,int n,int d);
