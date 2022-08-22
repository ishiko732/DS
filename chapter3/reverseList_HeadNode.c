#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data; /* 存储结点数据 */
    PtrToNode Next;   /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

#include "../chapter2/ListOp.c"
List Reverse(List L, int K);
void K_Reverse(List L, int K);

int main()
{
    List L;
    int K;

    L = Read();
    scanf("%d", &K);
    K_Reverse(L, K);
    Print(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
// List Reverse(List L, int K)
// {
//     List prev = L->Next;
//     List current = prev->Next;
//     List tmp;
//     int cnt = 1;
//     while (cnt < K)
//     {
//         tmp = current->Next;
//         current->Next = prev;
//         prev = current;
//         current = tmp;
//         cnt++;
//     }
//     L->Next->Next = current;
//     return prev;
// }

void K_Reverse(List L, int K)
{
    if (K == 1) // K=1 不逆转
    {
        return;
    }
    List p = L;
    List q = L->Next;
    do
    {
        int check = 0;
        while (q && check < K)
        {
            // 判断后续元素是否满足k个
            // O(n)
            q = q->Next;
            check++;
        }
        if (check % K == 0) // 不足以K元素不逆转
        {
            List prev = p->Next;
            List src = prev;
            // src : 保留现场 使其指向逆转前的头元素结点
            List current = prev->Next;
            List tmp;
            int cnt = 1;
            while (cnt < K)
            {
                tmp = current->Next;
                current->Next = prev;
                prev = current;
                current = tmp;
                cnt++;
            }
            p->Next->Next = current;
            p->Next = prev;
            p = src;
        }
    } while (q);

    return;
}