#include <stdio.h>
#include <time.h>

void mergesort(int a[], int n);
void merge(int b[], int c[], int a[], int p, int q, int n);

void main()
{
    clock_t start, end;
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int a[n];
    printf("elements:");
    for (int i = n; i > 0; i--)
    {
        a[n - i] = i; // Fixing array indexing
        printf("%d\t", a[n - i]);
    }
    start = clock();
    mergesort(a, n);
    end = clock();
    printf("\nSorted array:");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nTime taken: %f seconds\n", ((double)(end - start) / CLOCKS_PER_SEC)); // Fixed time calculation
}

void mergesort(int a[], int n)
{
    if (n > 1)
    {
        int mid = n / 2;
        int b[mid], c[n - mid]; // Adjust sizes of subarrays
        for (int i = 0; i < mid; i++)
        {
            b[i] = a[i];
        }
        for (int i = mid; i < n; i++)
        {
            c[i - mid] = a[i];
        }
        mergesort(b, mid);
        mergesort(c, n - mid);
        merge(b, c, a, mid, n - mid, n);
    }
}

void merge(int b[], int c[], int a[], int p, int q, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < p && j < q)
    {
        if (b[i] <= c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    while (i < p)
    {
        a[k] = b[i];
        i++;
        k++;
    }
    while (j < q)
    {
        a[k] = c[j];
        j++;
        k++;
    }
}
