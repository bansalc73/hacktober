#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int partition(int a[],int i,int j,int pivot);

void RQS(int a[],int i,int j){
    if(i<j){
        int p = rand()%(j-i+1)+i;
        int temp = a[p];
        a[p]=a[i];
        a[i]=temp;
        int k = partition(a,i+1,j,a[i]);
        RQS(a,i,k-1);
        RQS(a,k+1,j);
    }
}

int partition(int a[],int i,int j,int pivot){
    int l=i,r=j;
    while(l<=r){
        while(l<=r && a[l]<=pivot)
            l++;
        while(l<=r && a[r]>=pivot)
            r--;
        if(l<=r){
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            l++;
            r--;
        }
    }
        int k = l-1;
        a[i-1] = a[k];
        a[k] = pivot;
        return k;
}
int main(){
    // int a[]={9,8,7,6,5,4,3,2,1};
    // RQS(a,0,8);
    int a[1000000];
    long n = 1000000;
    for(int i=0;i<n;i++)
        a[i] = n-i;
    // int a[]={9,8,7,6,5,4,3,2,1};
    
    // selection_sort(a,n);
    RQS(a,0,999999);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    for(int i=0;i<9;i++)
        printf("%d\n",a[i]);
    return 0;

}