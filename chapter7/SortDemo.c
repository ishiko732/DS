#include "SimpleSelectionSort.c"
#include "InsertSort.c"
#include "BubbleSort.c"
#include "HeapSort.c"
#include "BinaryInsertSort.c"
#include "QuickSort.c"

void SortAndPrint(void (*Sort)(int *, int))
{
    int A[10] = {3, 2, 5, 7, 6, 8, 9, 1, 10, 4};
    int N = 10;
    int i;
    printf("\n");
    printf("原数组:");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    Sort(A, N);
    printf("排序后:");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
    int choose;
    while (1)
    {
        printf("*************************************\n");
        printf("*********   1--选择排序   **********\n");
        printf("*********   2--插入排序   **********\n");
        printf("*********   3--冒泡排序   **********\n");
        printf("*********   4--希尔排序   **********\n");
        printf("*********   5--快速排序   **********\n");
        printf("*********   6----堆排序   **********\n");
        printf("*********   7--折半排序   **********\n");
        printf("*********   0--退出程序   **********\n");
        printf("*************************************\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
        {
            printf("选择排序：");
            SortAndPrint(SimpleSelectionSort);
            break;
        }
        case 2:
        {
            printf("插入排序：");
            SortAndPrint(InsertionSort);
            break;
        }
        case 3:
        {
            printf("冒泡排序：");
            SortAndPrint(BubbleSort);
            break;
        }
        case 4:
        {
            printf("希尔排序：");
            SortAndPrint(ShellSort);
            break;
        }
        case 5:
        {
            printf("快速排序：");
            SortAndPrint(QuickSort);
            break;
        }
        case 6:
        {
            printf("堆排序：");
            SortAndPrint(HeapSort);
            break;
        }
        case 7:
        {
            printf("折半排序：");
            SortAndPrint(BinaryInsertSort);
            break;
        }
        default:
        {
            printf("输入错误，请重新选择！\n");
            break;
        }
        }
    }

    return 0;
}