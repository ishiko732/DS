#include "Sort.h"

void SimpleSelectionSort(ElementType A[],int N){
    int i,j,min;
    for(i=0;i<N-1;i++){
        min=i;
        for(j=i+1;j<N;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        if(min!=i){
            Swap(&A[i],&A[min]);
        }
    }
}