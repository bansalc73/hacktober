#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    printf("NUMBER OF ELEMENTS IN INPUT ARRAY");                                                                                        
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0,max=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>max)
            max = sum;
        if(sum<0)
            sum=0;
        
    }
    printf("max possible sum is %d\n",max);
    return 0;
}