#include <stdio.h>
#include <stdlib.h>
int MaxSubseqSum4(int list[], int n)
{
    int thissum = 0, maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        thissum += list[i];
        if (thissum > maxsum)
        {
            maxsum = thissum;
        }
        else if (thissum < 0)
        {
            thissum = 0;
        }
    }
    return maxsum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *array = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", array + i);
    }
    printf("%d\n", MaxSubseqSum4(array, n));
}