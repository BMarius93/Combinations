#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MOD 40009
//Inmulteste matricele A si B. Rezultatul este returnat in matricea B.
//Operatiile sunt modulo MOD.
inline void multiplyMatrix(
    std::vector< std::vector<int> >& A,
    std::vector< std::vector<int> >& B
) {
    const size_t N = A.size();
    const size_t M = B[0].size();
    const size_t K = A[0].size();

    std::vector< std::vector<int> > Res(N, std::vector<int>(M, 0));

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            for (size_t k = 0; k < K; ++k) {
                Res[i][j] = (Res[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    B.swap(Res);
}



//Ridica la puterea p matricea patratica A. Matricea finala este returnata in A.
//Operatiile sunt modulo MOD.
inline void logPowMatrix(std::vector< std::vector<int> >& A, int p) {
    std::vector< std::vector<int> > Res(A.size(),std::vector<int>(A.size(), 0));

    for (size_t i = 0; i < Res.size(); ++i) {
        Res[i][i] = 1;
    }

    while(p){
        if(p%2)
            multiplyMatrix(A,Res);
            multiplyMatrix(A,A);
            p/=2;
    }

    A.swap(Res);
}
//Ririca un numar nr la puterea powe in timp logaritmic
long long LgPow(long long nr,long long power)
{
    long long aux = 1;
 
    while(power)
    {
        if(power%2)
           aux = ((aux%MOD)*(nr%MOD)) % MOD;
        nr = ((nr%MOD)*(nr%MOD))%MOD;
        power/=2;
    }
 
    return aux;
}


int main(){
    
    FILE *fr, *fw; 
    fr = fopen ("date.in", "r");
    fw = fopen ("date.out", "w");
    int a, b, c;
    fscanf(fr, "%d %d %d", &a, &b, &c);
    int n = a;
    int m = b;
    int k = c;

    vector<vector<int> > mat(k+1);
    for ( int i = 0 ; i < k+1 ; i++ ){
        mat[i].resize(k+1);
    }
    //initializarea matricei de recurenta
    for ( int i = 0 ; i < k+1 ; i++ ){
        for (int j = 0; j < k+1; j++){
           if((j == k) || ((i - j) == 1)){
                mat[i][j] = 1;
           }else{
                mat[i][j] = 0;
           }
        }
    }

    //ridicarea acesteia la puterea n+1
    logPowMatrix(mat,n+1);
    //ridicarea elementului din dreapta-jos la puterea m
    int result = LgPow(mat[k][k],m);

    //scrierea rezultatului in fisier si inchiderea fisierelor
    fprintf(fw, "%d", result);
    fclose(fr);
    fclose(fw);
    return 0;


}
