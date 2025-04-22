#include <stdio.h>
#define max 25


void display(int process[],int n,int alloc[])
{
    printf("Process\tProcess size\tBlock no\n");
    for(int i=0;i<n;i++)
    {
        printf("%d         \t%d               \t",(i+1),process[i]);
        if(alloc[i]!=-1)
        {
            printf("%d\n",alloc[i]+1);
        }
        else{
            printf("Not allocated\n");
        }
    }

}

void firstfit(int process[], int n, int block[], int m)
{
    int alloc[max];
    for (int i = 0; i < n; i++)
        alloc[i] = -1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(process[i]<=block[j])
            {
                alloc[i]=j;
                block[j]=block[j]-process[i];
                break;
            }
        }
    } 
    printf("First Fit Allocation\n:");
    display(process,n,alloc);
}

void bestfit(int process[], int n, int block[], int m)
{
    int alloc[max];
    for (int i = 0; i < n; i++)
        alloc[i] = -1;
    for(int i=0;i<n;i++)
    {
        int bestindx=-1;
        for(int j=0;j<m;j++)
        {
            if(process[i]<=block[j])
            {
                if(bestindx==-1 || block[j]<block[bestindx])
                {
                    bestindx=j;
                }
            }
        }
        if(bestindx!=-1)
        {
            alloc[i]=bestindx;
            block[bestindx]-=process[i];
        }
    } 

    printf("Best Fit Allocation\n:");
    display(process,n,alloc);
}

void worstfit(int process[], int n, int block[], int m)
{
    int alloc[max];
    for (int i = 0; i < n; i++)
        alloc[i] = -1;
    for(int i=0;i<n;i++)
    {
        int  windx=-1;
        for(int j=0;j<m;j++)
        {
            if(process[i]<=block[j])
            {
                if(windx==-1 || block[j]>block[windx])
                {
                    windx=j;
                }
            }
        }
        if(windx!=-1)
        {
            alloc[i]=windx;
            block[windx]-=process[i];
        }
    } 

    printf("Worst Fit Allocation\n:");
    display(process,n,alloc);
}

void main()
{
    int blockSize[max], processSize[max], m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter size of each block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("Enter size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    int blockSize1[max], blockSize2[max], blockSize3[max];
    for (int i = 0; i < m; i++) {
        blockSize1[i] = blockSize[i];
        blockSize2[i] = blockSize[i];
        blockSize3[i] = blockSize[i];
    }

    firstfit(processSize, n,blockSize1, m);
    bestfit( processSize, n,blockSize2, m);
    worstfit( processSize, n,blockSize3, m);

}
