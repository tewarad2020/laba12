#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]) {
    double sum = 0;
    for(int i=0;i<N;i++) sum += A[i];
    B[0] = sum;
    B[0] /= N;
    
    sum = 0;
    for(int i=0;i<N;i++) sum += pow(A[i],2);
    B[1] = sqrt(sum/(N)-pow(B[0],2));
    
    sum = 1;
    for(int i=0;i<N;i++) sum *= A[i];
    B[2] = pow(sum,1/double(N));
    
    sum = 0;
    for(int i=0;i<N;i++) sum += 1/A[i];
    B[3] = N/sum;
    
    B[4] = A[0];
    B[5] = A[0];
    for(int i=0;i<N;i++) {
        if (B[4] < A[i]) B[4] = A[i];
        if (B[5] > A[i]) B[5] = A[i];
    }
}