#include<stdio.h>

int* get(int *a,int n);
void dis(int *a, int n);
void ins(int *a, int index, int n, int valu);
void dele(int *a, int delval, int n);
void find(int *a, int fin, int n);

int n = 0; 
int main(void)
{
    int *arr, first[100],ch,valu,index,delval,fin;
    
    do
    {
        printf("1.Create\n2.Insert\n3.Delete\n4.Display\n5.Find\n6.Exit\n");
        printf("Enter your Option:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1://create
                printf("Enter the array size\n");
                scanf("%d",&n);
                arr = get(first, n);
                break;
            case 2://insert
                printf("\nEnter the Element to insert:");
                scanf("%d",&valu);
                printf("\nEnter the position to insert:");
                scanf("%d",&index);
                ins(arr, index, n, valu);
                n++;
                break;
            case 3://delete
                printf("\nEnter the element to delete:    ");
                scanf("%d",&delval);
                dele(arr, delval, n);
                n--;
                break;
            case 4://display
                dis(arr, n);
                break;
            case 5://find
                printf("\nwhich element is to find:");
                scanf("%d",&fin);
                find(arr, fin, n);
                break;
            case 6://find
                printf("Exit\n");
                break;    
        }

    }
    while(ch<=5);
    
    return 0;
    
}

int* get(int *a,int n)
{
    printf("Enter the array elements\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("List was created successfully\n\n");
    return a;
}
void dis(int *a, int n)
{
    if(n==0)
    {
        printf("List is empty");
    }
    else
    {
        printf("\nElements present in the list are:");
        
        for(int i =0; i < n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    
}
void ins(int *a, int index, int n, int valu)
{
    
    for(int i = n;i >=index;i--)
    {
        a[i] = a[i-1]; 
    }

    a[index]=valu;
    
    
    //printf("Elements after insertion:\n");
    //for(int i = 0; i <= n; i++)
    //{
    //    printf("%d\n",a[i]);
    //}
    printf("\n");
    
}
void dele(int *a, int delval, int n)
{
    int index;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == delval)
        {
            index = i;
        }
    }
    for(int i = index; i < n;i++)
    {
        a[i] = a[i +1];
    }
    printf("\n");
    //printf("Array after deletion:\n");
    //for(int i =0; i < n-1; i++)
    //{
    //    printf("%d\n",a[i]);
    //}
    
}
void find(int *a, int fin, int n)
{
    int index = -1;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == fin)
        {
            index = i;
        }
    }
    if(index == -1)
    {
        printf("\nElement is not present");
    }
    else
    {
        printf("\nElement is at %d",index);
    }
    
    
}
