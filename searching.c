#include <stdio.h>
#include <stdlib.h>

int linear_search(int arr[], int n, int key, int *count)
{
    int i;
    *count=0;
    for(i=0;i<n;i++)
    {
        (*count)++;
        if( arr[i]==key )
        { 
            return i+1;      
        }      
    }
    return -1;
}

int binary_search(int arr[], int n, int key, int *count)
{
    int low=0, high = n-1,mid;
    *count = 0;
    while(low <= high)
    {
        (*count)++;
        mid = (high+low)/2;
        if( key == arr[mid])
        {
            return mid+1;
        }
        else if( key > arr[mid])
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int interPolation_search(int arr[], int n, int key, int *count)
{
    int low=0, high = n-1,pos;
    *count = 0;
    while(low <= high)
    {
        (*count)++;
        pos = low + (((double)(high-low)/(arr[high] - arr[low])) * (key - arr[low]));
        if( key == arr[pos])
        {
            return pos+1;
        }
        else if( key > arr[pos])
        {
            low = pos+1;
        }
        else
        {
            high = pos-1;
        }  
     }
     return -1;
}

int is_sort(int arr[], int n) 
{
    int i,inc=0,dec=0;
    for(i=0; i<n-1; i++)
    {
        if(arr[i] <= arr[i+1])
        {
            inc++;
        }
        else if(arr[i] >= arr[i+1])
        {
            dec++;
        }
    }
    if(inc == n-1 || dec == n-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display(int arr[],int n)
{
    int i;
    printf("The arr is");
    for(i=0;i<n;i++){
    printf(" %d, ", arr[i]);
    }
}

int main(){
    int x,y,z,lin,bin,inpo,key;
    int c1=0,c2=0,c3=0;
    int p[10]={2,3,4,15,1,3,5,76,54,87};
    int q[10]={10,20,30,40,50,60,70,80,90,100};
    int r[10]={10,20,30,40,50,60,70,80,90,10000};

     printf("%d  \n", is_sort(p,10));
    printf("%d  \n", is_sort(q,10));
    printf("%d  \n", is_sort(r,10)); 

    x=is_sort(p,10);
    y=is_sort(q,10);
    z=is_sort(r,10);

 

    if(x == 0)
    {
    display(p,10);
    printf("Enter the number to serach for in linear search\n");
    scanf("%d",&key);
     lin=linear_search(p,10,key, &c1);
     if(lin == -1)
     {
        printf("Element not found\n");
     }
     else
     {
         printf("\n Element found at the position %d after %d iterations\n",lin,c1);

     }
    }


     if(y == 1)
    { 
    display(q,10);
    printf("Enter the number to serach for in binary search\n");
    scanf("%d",&key);
     bin=binary_search(q,10,key, &c2);
     if(bin == -1)
     {
        printf("Element not found\n");
     }
     else
     {
         printf("\n Element found at the position %d after %d iterations\n",bin,c2);
     }
    }

     if(z == 1)
    {
    display(r,10);
    printf("Enter the number to serach forn in interpolation search\n");
    scanf("%d",&key);
     inpo=interPolation_search(r,10,key, &c3);
     if(inpo == -1)
     {
        printf("Element not found\n");
     }
     else
     {
         printf("\n Element found at the position %d after %d iterations",inpo,c3);

     }
    }
    return 0;
}