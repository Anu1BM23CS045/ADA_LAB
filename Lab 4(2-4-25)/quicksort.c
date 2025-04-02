#include <stdio.h>
#include <time.h>

void swap(int a[],int p,int q);
void quicksort(int a[],int l,int r);
int hoarePartition(int a[],int l,int r);

void main()
{
    clock_t start, end;
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int a[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = n - i;  // Initialize in descending order
    }
    
    start = clock();
    quicksort(a, 0, n - 1);
    end = clock();
    
    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nTime taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void quicksort(int a[], int l, int r)
{
    int s;
    if(l < r)
    {
        s = hoarePartition(a, l, r);
        quicksort(a, l, s - 1);
        quicksort(a, s + 1, r);
    }
}

int hoarePartition(int a[], int l, int r)
{
    int p = a[l];
    int i = l, j = r + 1;

    do
    {
        while(a[++i] < p);
        while(a[--j] > p);

        if(i < j)
        {
            swap(a, i, j);
        }
    } while(i < j);

    swap(a, l, j);
    return j;
}

void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
