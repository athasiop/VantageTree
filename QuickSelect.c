#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "vpsequentialF.h"
#include <time.h>

// Standard partition process of QuickSort().
// It considers the last element as pivot
// and moves all smaller element to left of
// it and greater elements to right

void swap(double *a,double *b){
    double tmp = *a;
    *a=*b;
    *b=tmp;
}
int partition(double *arr,double *data,int d, int l, int r)
{
    double x = arr[r];
    int  i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i],&arr[j]);
            for(int a=0;a<d;a++){
            swap(&data[i*d+a],&data[j*d+a]);
          }
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    for(int a=0;a<d;a++){
      swap(&data[i*d+a], &data[r*d+a]);
  }

    return i;
}

// This function returns k'th smallest
// element in arr[l..r] using QuickSort
// based method.  ASSUMPTION: ALL ELEMENTS
// IN ARR[] ARE DISTINCT
double kthSmallest(double *arr,double *data,int d, int l, int r, int k)
{
    // If k is smaller than number of
    // elements in array
    if (k > 0 && k <= r - l + 1) {

        // Partition the array around last
        // element and get position of pivot
        // element in sorted array
        int index = partition(arr,data,d, l, r);

        // If position is same as k
        if (index - l == k - 1)
            return arr[index];

        // If position is more, recur
        // for left subarray
        if (index - l > k - 1)
            return kthSmallest(arr,data,d, l, index - 1, k);

        // Else recur for right subarray
        return kthSmallest(arr,data,d, index + 1, r,
                            k - index + l - 1);
    }

    // If k is more than number of
    // elements in array
    return INT_MAX;
}
double* test(double*x,int offset){
  return x+offset;
}
// Driver program to test above methods
int main()
{
    /*double arr[] = { 4,3,2,1 };
    double arr1[] = { 0,0,0, 1, 0, 2, 0, 3 ,0,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    //double *arr2 = test(arr1,6);
   for(int i=0;i<5;i++){
      printf("%f\n",arr2[i]);
    }*/
    int n=100000;
    int d = 2;
    double x[n*d];
    int idx;
    for(int i=0;i<n*d;i+=d){
      x[i] = i/2;
  	x[i+1]=0;
  }
  clock_t begin = clock();
  vptree* root  = buildvp(x,n,d);
 clock_t end = clock();
 printf("exe time = %lf seconds\n",(end-begin)/(double)CLOCKS_PER_SEC);
  /*
    vptree* t = buildvp(arr1,5,2);
    vptree* t1 = getOuter(t);
    vptree* t2 = getInner(t);
    //vptree* t3 = getInner(t);
    double *vp1 = getVP(t);
    double *vp2 = getVP(t1);
    double *vp3 = getVP(t2);
    //double *vp4 = getVP(t3);
    for(int i=0;i<2;i++){
      printf("\n vp root = %f\n",vp1[i]);
      printf("\n vp outer root = %f\n",vp2[i]);
      printf("\n vp inner root = %f\n",vp3[i]);
      //printf("\n vp inner root = %f\n",vp4[i]);
    }*/
    //printf("K-th smallest element is %f",kthSmallest(arr,arr1,2, 0, n - 1, k));
    /*for(int i=0;i<8;i++){
      printf("\n%f",arr1[i]);
    }
    for(int i=0;i<5;i++){
      for(int j=0;j<2;j++)
      printf("\n%f",arr1[i*2+j]);
    }
    for(int i=0;i<4;i++){
    //  printf("\n%f",arr[i]);
  }*/
    return 0;
}
