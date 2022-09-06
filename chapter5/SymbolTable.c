#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXTABLESIZE 100000
typedef int ElementType;
typedef int Index;
typedef Index Position;
typedef enum{Legitimate,Empty,Deleted} EntryType;
typedef enum{false,true} bool;
typedef struct HashEntry Cell;
struct HashEntry
{
    ElementType Data;
    EntryType Info;
};

typedef struct TblNode* HashTable;
struct TblNode
{
    int TableSize;
    Cell* Cells;
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
    H=(HashTable)malloc(sizeof(struct TblNode));
    H->TableSize=NextPrime(TableSize);
    H->Cells=(Cell*)malloc(sizeof(Cell));
    for(int i=0;i<H->TableSize;i++){
        H->Cells[i].Info=Empty;
    }
    return H;
}
Position Hash(ElementType Key,int TableSize){
    return Key%TableSize;
}

Position Find(HashTable H,ElementType Key){
    Position CurrentPos,NewPos;
    int CNum=0;

    NewPos=CurrentPos=Hash(Key,H->TableSize);
    while(H->Cells[NewPos].Info!=Empty && H->Cells[NewPos].Data!=Key){
        if((++CNum)%2){
            NewPos=CurrentPos+(CNum+1)*(CNum+1)/4;
            if(NewPos>=H->TableSize){
                NewPos=NewPos%H->TableSize;
            }
        }else{
            NewPos=CurrentPos-(CNum+1)*(CNum+1)/4;
            while(NewPos<0){
                NewPos+=H->TableSize;
            }
        }
    }
    return NewPos;
}

bool Insert(HashTable H,ElementType Key){
    Position Pos=Find(H,Key);
    if(H->Cells[Pos].Info!=Legitimate){
        H->Cells[Pos].Info=Legitimate;
        H->Cells[Pos].Data=Key;
        return true;
    }else{
        printf("key is exist!\n");
        return false;
    }
}

Position Delete(HashTable H,ElementType Key){
    Position Pos=Find(H,Key);
    if(H->Cells[Pos].Info==Legitimate){
        H->Cells[Pos].Info=Deleted;
        return Pos;
    }else{
        printf("key is not exist!\n");
        return false;
    }
}