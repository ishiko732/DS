#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTRLEN 1024

struct SString{
    unsigned char* cpString;
    int maxStrLen;
};

void getNext(char *t,int *next,int length){
    int j=0,k=-1;
    next[0]=-1;
    while(j<length-1){
        if(k==-1||t[j]==t[k]){
            j++;
            k++;
            next[j]=k;
        }else{
            k=next[k];
        }
    }
}
void getNextVal(char *t,int *nextval,int length){
    int j=0,k=-1;
    nextval[0]=-1;
    while(j<length-1){
        if(k==-1||t[j]==t[k]){
            j++;
            k++;
            if(t[j]!=t[k]){
                nextval[j]=k;
            }else{
                nextval[j]=nextval[k];
            }
        }else{
            k=nextval[k];
        }
    }
}

int KMPIndex(char* s,char* t){
    int s_len=strlen(s);
    int t_len=strlen(t);
    int* next=(int *)malloc(sizeof(char)*(t_len));
    int i=0,j=0;
    getNextVal(t,next,t_len);
    while(i<s_len&&j<t_len){
        if(j==-1||s[i]==t[j]){
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if(j>=t_len){
        return i-t_len;
    }else{
        return -1;
    }
}
int main(){
    char *s="ababaababcb";
    char *t="ababc";
    // int len=strlen(t);
    // int* nextj=(int *)malloc(sizeof(char)*(len));
    // getNextVal(s,nextj,len);
    // for(int i=0;i<len;i++){
    //     printf("%d ",nextj[i]);
    // }
    printf("%d\n",KMPIndex(s,t)+1);
}