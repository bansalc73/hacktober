#include<bits/stdc++.h>
using namespace std;
void build_tree(long long arr[],long long tree[],long long n){
    for(long long i=0;i<n;i++){
        tree[n-1+i] = arr[i];
    }
    for(long long i=n-2;i>-1;i--){
        tree[i] = tree[2*i+1] + tree[2*i+2];
    }

}
long long give_index(long long tree[],long long k,long long i,long long n,long long s,long long e){//given the tree having only binary elements it will give the index of Kth one in array
// the basic idea is that where the sum if k there only is kth one 
// so form a binary index tree
    // cout<<i<<" "<<k<<" ";
    long long m = (s+e)/2;
    if(i<2*n-1 && s<=e){
        if(tree[i]==k){
            long long temp;
            while(i<2*n-1){
                if(2*i+2<2*n-1){
                    if(tree[2*i+2]>0)i = 2*i+2;
                    else i = 2*i+1;
                    temp = i;
                }
                else{
                    temp = i;
                    break;
                } 
            }
            return temp - n + 1;

        }
        if(tree[2*i+1]>=k)return give_index(tree,k,2*i+1,n,s,m);
        else return give_index(tree,k-tree[2*i+1],2*i+2,n,m+1,e);
    }
    return -1;
}

unsigned long long nextPowerOf2(unsigned long long n)  
{  
    unsigned count = 0;  
      
    // First n in the below condition  
    // is for the case where n is 0  
    if (n && !(n & (n - 1)))  
        return n;  
      
    while( n != 0)  
    {  
        n >>= 1;  
        count += 1;  
    }  
      
    return 1 << count;  
}


void update(long long i,long long tree[],long long arr[],long long n){
    // you want to update arr[i] = update
    if(arr[i] == 0)return;
    arr[i] = 0;
    i += n-1;
    tree[i]--;
    while(i>=0){
        tree[(i-1)/2]--;
        i = (i-1)/2;
        if(i == 0)break;

    }
}

void print_tree(long long tree[],long long size){
    for(long long i=0;i<size;i++)cout<<tree[i]<<" ";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    long long n,q;
    // cout<<-1/2;
    cin>>n>>q;
    // vector<long long> v;
    long long extra  = nextPowerOf2(n);
    long long arr[extra];
    
    long long tree[3*extra+5];

    for(long long i=0;i<n;i++)arr[i] = 1;
    for(long long i=n;i<extra;i++)arr[i] = 0;
    n = extra;

    build_tree(arr,tree,n);
    // prlong long_tree(tree,2*n-1);
    while(q--){
        long long operation,key;
        cin>>operation>>key;
        if(operation==0){
            update(key-1,tree,arr,n);
            // prlong long_tree(tree,2*n-1);
        }
        else{
            long long i = give_index(tree,key,0,n,0,n-1);
            // prlong long_tree(tree,2*n-1);
            if(i==-1)i--;
            cout<<i+1<<"\n";
            // v.push_back(i+1);
        }
    }
    // for(int i=0;i<v.end()-v.begin();i++)cout<<v[i]<<"\n";
    return 0;
}