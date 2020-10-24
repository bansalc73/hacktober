#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct linked_list{
    struct linked_list * next;
    ll data;
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


bool is_cycle(struct linked_list * graph[],ll n,ll u,bool visited[],bool check[]){
    visited[u] = true;
    check[u] = true;
    struct linked_list * tmp = graph[u];
    while(tmp){
        ll v = tmp->data;
        if(!visited[v] && is_cycle(graph,n,v,visited,check)){
            return true;
        }
        else if(check[v])return true;
        tmp = tmp->next;
    }
    check[u] = false;
    return false;
}
int main(){
    ll n;
    cout<<"n : ";
    cin>>n;
    struct linked_list * graph[n] = {NULL};
    ll prequisites;
    cout<<"Number of prerequisites : ";
    bool ans = true;
    cin>>prequisites;
    for(ll i=0;i<prequisites;i++){
        ll u,v;
        cout<<"u : ";
        cin>>u;
        cout<<"v : ";
        cin>>v;
        add_edge(graph,n,u,v);  
    }
    bool check[n] = {false},visited[n] = {false}, me[n] = {false};
    for(ll i=0;i<n;i++){
        if(!visited[i]){
            if(is_cycle(graph,n,i,visited,check)){
                ans = false;
                break;
            }
        }
    }
    // ans is the answer of the question not is_cycle
    cout<<ans;
    return 0;
}