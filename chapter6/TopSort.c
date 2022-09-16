#include "AdjacencyLists.c" // 本操作集是无向图的,需要修改InsertEdge来实现有向图的插入边
#include "Queue_op.c"

bool TopSort(LGraph Graph,Vertex TopOrder[]){
    int Indegree[MaxVertexNum],cnt;
    Vertex V;
    PtroToAdjVNode W;
    Queue Q=CreateQueue(Graph->Nv);
    for(V=0;V<Graph->Nv;V++){
        Indegree[V]=0;
    }
    for(V=0;V<Graph->Nv;V++){
        for(W=Graph->G[V].FirstEdge;W;W=W->Next){
            Indegree[W->AdjV]++;
        }
    }
    
    for(V=0;V<Graph->Nv;V++){
        if(Indegree[V]==0){
            AddQ(Q,V);
        }
    }

    cnt=0;
    while (!isEmpty(Q))
    {
        V=DeleteQ(Q);
        TopOrder[cnt++]=V;
        for(W=Graph->G[V].FirstEdge;W;W=W->Next){
            if(--Indegree[W->AdjV]==0){
                AddQ(Q,W->AdjV);
            }
        }
    }
    if(cnt!=Graph->Nv){
        return false;
    }else{
        return true;
    }
    
}
