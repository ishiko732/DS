#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXTABLESIZE 100000
#define KEYLENGTH 15
typedef char ElementType[KEYLENGTH+1];
typedef int Index;
typedef enum{false,true} bool;

typedef struct LNode* PtrToNode;
struct LNode{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;
typedef PtrToNode List;

typedef struct TblNode* HashTable;
struct TblNode{
    int TableSize;
    List Heads;
};

int NextPrime(int N){
    int i,p=(N%2)?N+2:N+1;
    while(p<=MAXTABLESIZE){
        for(i=(int)sqrt(p);i>2;i--){
            if(!(p%i))break;
        }
        if(i==2)break;
        else p+=2;
    }
    return p;
}
HashTable CreateTable(int TableSize){
    HashTable H;
    int i;
    H =(HashTable)malloc(sizeof(struct TblNode));
    H->TableSize=NextPrime(TableSize);
    H->Heads=(List)malloc(H->TableSize*sizeof(struct LNode));
    for(int i=0;i<H->TableSize;i++){
        H->Heads[i].Data[0]=0;
        H->Heads[i].Next=NULL;
    }
    return H;
}

// int Hash(const char* key,int TableSize){
//     unsigned int H=0;
//     while(*key!=0){
//         H=(H<<5)+*key++;
//     }
//     return H%TableSize;
// }

Index Hash( ElementType Key, int TableSize )
{
    return (Key[0]-'a')%TableSize;
}

Position Find(HashTable H,ElementType Key){
    Position P;
    Index Pos;
    Pos=Hash(Key,H->TableSize);
    P=H->Heads[Pos].Next;
    while(P&&strcmp(P->Data,Key)){
        P=P->Next;
    }
    return P;
}

bool Insert(HashTable H,ElementType Key){
    Position P,NewCell;
    Index Pos;
    P=Find(H,Key);
    if(!P){
        NewCell=(Position)malloc(sizeof(struct LNode));
        strcpy(NewCell->Data,Key);
        Pos=Hash(Key,H->TableSize);
        NewCell->Next=H->Heads[Pos].Next;
        H->Heads[Pos].Next=NewCell;
        return true;
    }else{
        printf("key is exist!\n");
        return false;
    }
}

bool Delete(HashTable H,ElementType Key){
    Position P,Cell;
    Index Pos;
    Pos=Hash(Key,H->TableSize);
    P=H->Heads+Pos;
    while(P->Next&&strcmp(P->Next->Data,Key)){
        P=P->Next;
    }
    if(P->Next){
        Cell=P->Next;
        P->Next=Cell->Next;
        free(Cell);
        printf("%s is deleted from list Heads[%d]\n",Key,Pos);
        return true;
    }else{
        return false;
    }
}

void DestroyTable(HashTable H){
    Position P,Tmp;
    for(int i=0;i<H->TableSize;i++){
        P=H->Heads[i].Next;
        while(P){
            Tmp=P->Next;
            free(P);
            P=Tmp;
        }
    }
    free(H->Heads);
    free(H);
}