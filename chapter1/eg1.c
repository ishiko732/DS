#include <stdio.h>
#include <time.h>
clock_t start,stop;
double duration;

void printN_1_2(int n);
void printN_1_3(int n);
void run(void(*f)(int),int n,int cnt,int case_n);
int main(int args ,char** argv){
    int n;
    scanf("%d",&n);
    run(printN_1_2,n,1000,2);
    run(printN_1_3,n,1000,3);
    return 0;
}

void run(void(*f)(int n),int n,int cnt,int case_n){
    start = clock();
    for (int i=0;i<=cnt;i++){
        (*f)(n);
    }
    stop = clock();
    duration = ((double)(stop-start))/CLOCKS_PER_SEC/cnt;
    printf("duration%d=%6.2e \n",case_n,duration);
}



void printN_1_2(int n){
    for (int i=0;i<=n;i++){
        printf("%d\n",i);
    }
}

void printN_1_3(int n){
    if(n>0){
        printN_1_3(n-1);
        printf("%d\n",n);
    }
}

void run_function(void *f(),int cnt){
    start = clock();
    for (int i=0;i<cnt;i++){
        f();
    }
    stop = clock();
    duration = ((double)(stop-start))/CLOCKS_PER_SEC;
    printf("run function time :%6.2e ",duration/cnt);
}
