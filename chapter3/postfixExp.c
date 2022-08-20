#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define INFINITY 1e9
typedef double ElementType;
typedef enum{num,opr,end} Type;


/*
========stack===========
*/
#define ERROR -1
typedef enum{false,true} bool;
typedef int Position;
typedef struct SNode* PtrToSNode;
struct SNode{
    ElementType* Data;
    Position Top;
    int MaxSize;
};
typedef PtrToSNode Stack;
Stack CreateStack(int MaxSize){
    Stack s=(Stack)malloc(sizeof(struct SNode));
    s->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
    s->MaxSize=MaxSize;
    s->Top=-1;
    return s;
}

bool IsFull(Stack s){
    return s->Top==s->MaxSize-1;
}
bool Push(Stack s,ElementType X){
    if(IsFull(s)){
        printf("Stack is full");
        return false;
    }else{
        s->Data[++(s->Top)]=X;
        return true;
    }
}

bool IsEmpty(Stack s){
    return s->Top==-1;
}

ElementType Pop(Stack s){
    if(IsEmpty(s)){
        printf("Stack is empty");
        return ERROR;
    }else{
        return s->Data[(s->Top)--];
    }
}
/*
========stack===========
*/

Type GetOp(char* Expr,int* start,char* str){
    int i=0;
    while((str[0]=Expr[(*start)++])==' ');
    while(str[i]!=' '&&str[i]!='\0'){
        str[++i]=Expr[(*start)++];
    }
    if(str[i]=='\0'){
        (*start)--;
    }
    str[i]='\0';
    if(i==0){
        return end;
    }else if (isdigit(str[0])||isdigit(str[1])){
        return num;
    }else{
        return opr;
    }
}

ElementType PostfixExp(char *Expr){
    Stack S;
    Type T;
    ElementType Op1,Op2;
    char str[MAXOP];
    int start=0;

    S = CreateStack(MAXOP);
    Op1=Op2=0;
    while((T=GetOp(Expr,&start,str)!=end)){
        if(T==num){
            Push(S,atof(str));
        }else{
            if(!IsEmpty(S)) Op2=Pop(S);
            else Op2=INFINITY;
            if(!IsEmpty(S)) Op1=Pop(S);
            else Op2=INFINITY;
            switch (str[0])
            {
            case '+':
                Push(S,Op1+Op2);
                break;
            case '*':
                Push(S,Op1*Op2);
                break;
            case '-':
                Push(S,Op1-Op2);
                break;
            case '/':
                if(Op2!=0.0) Push(S,Op1/Op2);
                else {
                    printf("ERROR\n");
                    Op2=INFINITY;
                }
            default:
                printf("unkown:%s\n",str);
                Op2=INFINITY;
                break;
            }
            if(Op2>=INFINITY) break;
        }
    }
    if(Op2<INFINITY){
        if(!IsEmpty(S)){
            Op2=Pop(S);
        }else{
            Op2=INFINITY;
        }
    }
    free(S);
    return Op2;
}

int main(){
    char Expr[MAXOP];
    ElementType f;
    gets(Expr);
    f=PostfixExp(Expr);
    if(f<INFINITY){
        printf("%.4f\n",f);
    }else{
        printf("ERROR");
    }
    return  0;
}