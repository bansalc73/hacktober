#include<stdio.h>
#include<stdlib.h>


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



int findrank(int a[],int i,int j,int r){
    if(i<j){
        int p = rand()%(j-i+1)+i;
        int temp = a[i];
        a[p] = a[i];
        a[i] = temp;
        int k = partition(a,i+1,j,a[i]);
        if(r==j-k+1)
            return k;
        else if(r<j-k+1){
            findrank(a,k+1,j,r);
        }
        else{
            findrank(a,i,k-1,r-j+k-1);
        }

    }
    // else{
        // return -1;
    // }
}
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    int rank = findrank(a,0,8,3);
    printf("%d",rank);
    return 0;
}