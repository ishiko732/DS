
void BinaryInsertSort(int A[], int N)
{
    int left, right, mid;
    int i, j;
    int x;
    for (i = 1; i < N; i++)
    {
        x = A[i];
        left = 0;
        right = i - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (A[mid] > x)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        for (j = i; j >= left + 1; j--)
        {
            A[j] = A[j - 1];
        }
        A[left] = x;
    }
}