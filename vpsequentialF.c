#include <stdio.h>
#include <stdlib.h>
#include "QuickSelect.h"
#include <math.h>
#include "vpsequentialF.h"


vptree *buildTree(double *data,int nP,int dim){
  vptree* vpt = malloc(sizeof(vptree));
  vpt->data = data;
  vpt->nP = nP;
  vpt->dim = dim;
  vpt->left = NULL;
  vpt->right = NULL;
  return vpt;
}
void insert(vptree* T){
  if(T->nP<1||T->data==NULL)
  return;
  int nP = T->nP;
  //printf("\nP = %d\n",nP);
  int dim = T->dim;
  //int counter=0;
  //printf("\n---Data---\n");
  double* data = T->data;
/*  for(int i=0;i<nP;i++){
    for(int j=0;j<dim;j++)
    printf("\n%f",T->data[i*dim+j]);
    counter++;
  }*/
  //printf(" c =   %d",counter);
  int k = nP/2+1;
  int offset = nP*dim/2+1;
  //printf("\noffset = %d",offset);
  int sizeOfDist = (nP-2);

  double *distance = createDistArray(T);
  for(int i=0;i<nP-1;i++){
  //  printf("\ndist = %f",distance[i]);
  }

  T->md = kthSmallest(distance,T->data,dim,0,nP-2,k);
  //printf("\n%f",T->md);
  T->vp = malloc(dim*sizeof(double));
  for(int i=0;i<dim;i++){
  T->vp[i] = T->data[nP*dim-dim+i];
  //printf("\nvp = %f",T->vp[i]);
}
  T->left = buildTree(T->data,nP/2,dim);
  T->right = buildTree(T->data+offset,(nP-2)/2,dim);
  insert(T->left);
  insert(T->right);
}
vptree *buildvp(double *X,int n,int d){
  vptree* T = buildTree(X,n,d);
  insert(T);
  return T;
}
vptree * getInner(vptree * T){return T->left;}
vptree * getOuter(vptree * T){return T->right;}
double getMD(vptree * T){return T->md;}
double * getVP(vptree * T){return T->vp;}
int getIDX(vptree * T){return T->idx;}
double *createDistArray(vptree* T){
    int nP = T->nP;
    int dim = T->dim;
    double *x = T->data;
    double sum=0;
    double* dist = (double*) malloc((nP-1)*sizeof(double));

    for(int i=0;i<nP-1;i++){//distance from point
      sum=0;
      for(int j=0;j<dim;j++){
        sum = sum+(x[nP*dim-dim+j]-x[j+i*dim])*(x[nP*dim-dim+j]-x[j+i*dim]);
        //printf("x[n]: %f  %d \n",x[nP*dim-dim+j],nP*dim-dim+j);
        //printf("x[other]: %f\n",x[j+i*dim]);
      }
      dist[i] = sqrt(sum);
      //printf("sum = %f",dist[i]);
    }
    return dist;
}
