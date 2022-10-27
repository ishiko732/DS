#include <stdio.h>
#include <stdlib.h>


int bfIndex(char S[],char T[]){
    int i,j,start;
    i=j=0;
    start=0;
    while(S[i]!='\0'&&T[j]!='\0'){
        if(S[i]==S[j]){
            i++;
            j++;
        }else{
            start++;
            i=start;
            j=0;
        }
    }
    return T[j]=='\0'?start:-1;
}