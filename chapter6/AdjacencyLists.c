#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode* PtrToENode;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode* PtroToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    WeightType Weight;
    PtroToAdjVNode Next;
};

typedef struct VNode{
    PtroToAdjVNode FirstEdge;
    DataType Data;
} *AdjList;

typedef struct GNode* PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

typedef enum{false,true} bool;
static bool Visited[MaxVertexNum]={0,};

LGraph CreateGraph(int VertexNum){
    Vertex V;
    LGraph Graph;

    Graph=(LGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    Graph->G=(AdjList)malloc(sizeof(struct VNode)*VertexNum);
    for(V=0;V<Graph->Nv;V++){
        Graph->G[V].FirstEdge=NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E){
    PtroToAdjVNode NewNode;
    NewNode=(PtroToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V2;
    NewNode->Weight=E->Weight;

    NewNode->Next=Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge=NewNode;

    // 无向图
    NewNode=(PtroToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V1;
    NewNode->Weight=E->Weight;

    NewNode->Next=Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge=NewNode;

}

LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;
    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);

    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++){
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }

    for(V=0;V<Graph->Nv;V++){
        scanf("%c",&(Graph->G[V].Data));
    }
    return Graph;
}

#include "Queue_op.c"
void Visit(Vertex V){
    printf("正在访问顶点%d\n",V);
}
void DFS(LGraph Graph,Vertex V,void(*Visit)(Vertex)){
    PtroToAdjVNode W;
    Visit(V);
    Visited[V]=true;
    for(W=Graph->G[V].FirstEdge;W;W=W->Next){
        if(!Visited[W->AdjV]){
            DFS(Graph,W->AdjV,Visit);
        }
    }
}
void BFS(LGraph Graph,Vertex S,void(*Visit)(Vertex)){
    Queue Q;
    Vertex V,W;
    PtroToAdjVNode WNode;
    Q=CreateQueue(MAXSIZE);

    Visit(S);
    Visited[S]=true;
    AddQ(Q,S);
    while(!isEmpty(Q)){
        V=DeleteQ(Q);
        for(WNode=Graph->G[S].FirstEdge;WNode;WNode=WNode->Next){
            W=WNode->AdjV;
            if(!Visited[W]){
                Visit(W);
                Visited[W]=true;
                AddQ(Q,W);
            }
        }
    }
}