#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct linked_list{
    ll data;
    struct linked_list * next;
};  
void add_at_beg(struct linked_list ** head,ll data){
    struct linked_list * tmp = new linked_list;
    tmp->next = *head;
    tmp->data = data;   
    *head = tmp;
}
void add_edge(struct linked_list * graph[],ll n,ll u,ll v){
    add_at_beg(&graph[u],v);
}
void DFS_recur(struct linked_list * graph[],ll L[],ll n,ll start,bool check[],ll phi[],ll count,ll c){
    if(!check[start]){
        // L[n-c] = count++;
        check[start] = true;
        struct linked_list * tmp = graph[start];
        while(tmp){
            ll v = tmp->data;
            phi[v] = start;
            // phi[v] = true;
            if(!check[v]){
                DFS_recur(graph,L,n,v,check,phi,count,c);
            }
            tmp = tmp->next;

        }
        // F[start] = count++;
        L[n-c-1] = count++;
        c++;
    }
}


void topological_sort(struct linked_list * graph[],ll n,ll start,ll phi,ll L,bool is_visited[],ll count,ll c){
    // L is sequence of topological sort 
    



}


int main(){
    ll n = 5;
    struct linked_list * graph[n] = {NULL};
    ll count = 0, c = 0;
    ll start = 0;
    ll phi[n] = {-2};
    phi[start] = -1;
    bool check[n] = {false};
    ll L[n];
    add_edge(graph,n,0,1);
    add_edge(graph,n,0,2);
    add_edge(graph,n,2,4);
    add_edge(graph,n,1,2);
    add_edge(graph,n,1,3);
    add_edge(graph,n,4,1);
    add_edge(graph,n,4,3);
    DFS_recur(graph,L,n,start,check,phi,count,c);
    for(ll i=0;i<n;i++){
        cout<<L[i]<<" ";
    }
    return 0;

}