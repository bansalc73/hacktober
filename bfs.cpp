// This implemnetation uses adjacency linked_list representation

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
void BFS(struct linked_list * graph[],ll n,ll start,ll phi[]){

    // use queue here
    queue<ll> q;
    bool is_visited[n] = {false};
    for(ll i=0;i<n;i++)phi[i] = -2;
    q.push(start);
    phi[start] = -1;
    is_visited[start] = true;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        struct linked_list * tmp = graph[u];
        while(tmp){
            ll v = tmp->data;
            if(!is_visited[v]){
                is_visited[v] = true;
                q.push(v);
                phi[v] = u;

            }
        }
    }
}
int main(void){
    ll n = 5;
    struct linked_list * graph[n] = {NULL};
    ll phi[n];

    add_edge(graph,n,0,1);
    add_edge(graph,n,0,2);
    add_edge(graph,n,1,3);
    add_edge(graph,n,1,2);
    add_edge(graph,n,2,4);
    add_edge(graph,n,4,1);
    add_edge(graph,n,4,3);
    BFS(graph,n,0,phi);
    for(ll i=0;i<n;i++){
        cout<<i<<" "<<phi[i]<<endl;
    }
    return 0;
}