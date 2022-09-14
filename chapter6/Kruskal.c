#include "AdjacencyLists.c"
#include "../chapter4/Set.c"

#define ERROR -1
void InitializeVSet(SetType Set,int V);
void InitializeESet(LGraph Graph,Edge ESet);
int GetEdge(Edge ESet,int CurrentSize);
bool CheckCycle(SetType VSet,Vertex V1,Vertex V2);

int Kruskal(LGraph Graph,LGraph MST){
    WeightType TotalWeight;
    int ECount,NextEdge;
    SetType VSet;
    Edge ESet;

    InitializeVSet(VSet,Graph->Nv);
    ESet=(Edge)malloc(sizeof(struct ENode)*Graph->Ne);
    InitializeESet(Graph,ESet);

    MST=CreateGraph(Graph->Nv);
    TotalWeight=0;
    ECount=0;

    NextEdge=Graph->Ne;
    while(ECount<Graph->Nv-1){
        NextEdge=GetEdge(ESet,NextEdge);
        if(NextEdge<0){
            break;
        }

        if(CheckCycle(VSet,ESet[NextEdge].V1,ESet[NextEdge].V2)==true){
            InsertEdge(MST,ESet+NextEdge);
            TotalWeight+=ESet[NextEdge].Weight;
            ECount++;
        }
    }
    if(ECount<Graph->Nv-1){
        TotalWeight=ERROR;
    }
    return TotalWeight;
}

void InitializeVSet(SetType Set,int V){
    for(int i=1;i<V;i++){
        Set[i]=-1;
    }
}

void PercDown(Edge ESet,int p, int N){//chapter4-MinHeap.c PercDown
    int Parent,Child;
    struct ENode X;
    X=ESet[p];
    for(Parent=p;(Parent*2+1)<N;Parent=Child){
        Child=Parent*2+1;
        if((Child!=N-1)&&(ESet[Child].Weight>ESet[Child+1].Weight)) Child++;
        if(ESet[Child].Weight>=X.Weight) break;
        else{
            ESet[Parent]=ESet[Child];
        }
    }
    ESet[Parent]=X;
}
void InitializeESet(LGraph Graph,Edge ESet){
    Vertex V;
    PtroToAdjVNode W;
    int ECount;

    ECount=0;
    for(V=0;V<Graph->Nv;V++){
        for(W=Graph->G[V].FirstEdge;W;W=W->Next){
            if(V<W->AdjV){ // 下三角
                ESet[ECount].V1=V;
                ESet[ECount].V2=W->AdjV;
                ESet[ECount++].Weight=W->Weight;
            }
        }
    }
    for(ECount=Graph->Ne/2;ECount>=0;ECount--){ //BuildMinHeap
        PercDown(ESet,ECount,Graph->Ne);
    }
}

void Swap(struct ENode* a,struct ENode* b){
    struct ENode t=*a;
    *a=*b;
    *b=t;
}

int GetEdge(Edge ESet,int CurrentSize){
    Swap(&ESet[0],&ESet[CurrentSize-1]);
    PercDown(ESet,0,CurrentSize-1);
    return CurrentSize-1;
}

bool CheckCycle(SetType VSet,Vertex V1,Vertex V2){
    Vertex Root1,Root2;
    Root1=Find(VSet,V1);
    Root2=Find(VSet,V2);
    if(Root1==Root2){
        return false;
    }else{
        Union1(VSet,Root1,Root2);
        return true;
    }
}