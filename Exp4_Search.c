/*Search in a bitonic array*/

#include <stdio.h>

int ascendingBinarySearch(int arr[], int low, int high, int key){
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int descendingBinarySearch(int arr[], int low, int high, int key){
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int searchmax(int a[], int n, int high, int low){
    int mid=(high+low)/2;
    int highestpoint=0;
    if (mid==0 || (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]))
        return mid;
    
    else if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1])
        highestpoint = searchmax(a, n, high, mid+1);
    
    else if (a[mid] < a[mid - 1] && a[mid] > a[mid + 1])
        highestpoint = searchmax(a, n, mid-1, low);
    
    return highestpoint;
}

int searchmin(int a[], int n, int high, int low){

    int mid=(high+low)/2;
    int lowestpoint =0;
    
    if (a[mid] < a[mid - 1] && a[mid] < a[mid + 1])
        return mid;
    
    else if (a[mid] < a[mid - 1] && a[mid] > a[mid + 1])
        lowestpoint = searchmin(a, n, high, mid+1);
    
    else if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1])
        lowestpoint = searchmin(a, n, mid-1, low);
    
    return lowestpoint;
}

int search(int arr[], int n, int key, int bitonicpoint, int minimumpoint){
    if(key>arr[bitonicpoint])
        return -1;
    else if(key==arr[bitonicpoint])
        return bitonicpoint;
    else{
        int ans=ascendingBinarySearch(arr,0,bitonicpoint-1,key);
        if(ans!=-1)
            return ans;
        int ans1 = descendingBinarySearch(arr,bitonicpoint+1,minimumpoint,key);
        if(ans1!=-1)
            return ans1;
        int ans2 = ascendingBinarySearch(arr,minimumpoint+1,n-1,key);
            return ans2;
    }
}

int main(){
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    int arr[n],key;
    printf("Enter bitonic elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter key : ");
    scanf("%d",&key);
    int low=0, high,bitonicpoint,minimumpoint;
    high =n-1;
    bitonicpoint=searchmax(arr,n,high,low);
    minimumpoint=searchmin(arr,n,high,bitonicpoint);
    int ans = search(arr,n,key,bitonicpoint,minimumpoint);
    if(ans==-1){
        printf("Element not found!");
    }else
        printf("\nElement is at index %d",ans);
    return 0;
}
