//1. Bubble Sort
/*#include<stdio.h>
void bubble(int a[],int n){
    int swap=0,i,comparison=0;
    for(i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            comparison++;
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                swap++;
            }
        }
    }
    printf("\nBy Bubble Sort \nswap = %d \ncomparison = %d\n",swap,comparison);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }    
    bubble(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
*/
//2. Modified Bubble Sort
/*#include<stdio.h>
void efficient_bubble(int a[],int n){
    int swap=0,i,comparison=0;
    for(i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-i-1;j++){
            comparison++;
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                swap++;
                flag=1;
            }
        }
        if(flag==0) break;
    }
    printf("\nBy Modified Bubble Sort \nswap = %d \ncomparison = %d\n",swap,comparison);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }    
    efficient_bubble(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
*/
//3. Selection Sort
/*#include <stdio.h>
void selection_sort(int arr[], int n){
    int i, j, min_idx, count = 0, swap = 0;
    for (i = 0; i < n - 1; i++){
        min_idx = i;
        for (j = i + 1; j < n; j++){
            count += 1;
            if (arr[j] < arr[min_idx])
            min_idx = j;
        }
        if (min_idx != i){
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            swap += 1;
        }
    }
    printf("Comparisons = %d, Swaps = %d\n", count, swap);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    selection_sort (a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
/*
//4. Insertion Sort
/*#include<stdio.h>
void insertion_sort(int arr[], int n) {
    int i, key, j, count = 0, shift = 0;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
            shift += 1;
            count += 1;
        }
        arr[j + 1] = key;
        if (j >= 0)
            count += 1;
    }
    printf("Comparisons = %d, Shift = %d\n", count, shift);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }   
    insertion_sort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
*/