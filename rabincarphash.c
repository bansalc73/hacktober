#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 struct a{
    int data;
    struct a *node;
};
void append(struct a **head,int key)
{
    struct a* temp = (struct a*)malloc(sizeof(struct a));
    temp->data = key;
    if(*head == NULL)
    {
        *head = temp;
    }
    else
    {
        while((*head)->node != NULL)
        {
            *head = (*head)->node;             
        }
        temp->node = (*head)->node;
        (*head)->node = temp;
    }
}
int main()
{
    char T[100000];
    int n,m,N,y,x=2,j,i;
    int l=strlen(T);
    int prime=pow(10,5)+7;
    struct a *hashtable[prime];
    struct a *temp;
    printf("ENTER THE BIG STRING\n");
    scanf("%s",T);
    printf("ENTER THE NUMBER OF PATTERNS YOU WANT TO COMPARE\n");
    scanf("%d",&n);
    printf("ENTER THE LENGTH OF EACH PATTERN\n");
    scanf("%d",&m);
    char P[n][m];
    for(i=0;i<n;i++)
        {
            printf("ENTER PATTERNS");
            scanf("%s",P[i]);
        }
    for(i=0;i<n;i++)
    {
        N = (P[i][0]-48)%prime;
        for(j=1;j<m;j++)
        {
            N = (N*2 + P[i][j]-48)%prime; 
        }
        append(&hashtable[N],i+1);
    }
    y=(T[0]-48)%prime;
    for(i=1;i<m;i++)
        {
            x=(x*2)%prime;
            y=(y*2+(T[i]-48))%prime;
        }
    temp = hashtable[y];
    while(temp != NULL)
    {
        for(i=0;i<m;i++)
        {
            if(T[i]-48 != P[(temp->data)-1][i]-48)
                break;
        }
        if(i==m)
                printf("MATCH FOUND AT POSITION 1 WITH PATTERN %d",temp->data);
        temp=temp->node;
    }
    for(i=1;i<=l-m;i++)
    {
        y = (y*2+(T[i+m-1]-48)-x*(T[i-1]-48))%prime;
        if(y<0)
            y=y+prime;
        temp=hashtable[y];
        while(temp != NULL)
            {
                for(j=0;j<m;j++)
                    {
                        if((T[j+i]-48) != P[temp->data -1 ][j]-48)
                            break;
                    }
                if(j==m)
                    printf("MATCH FOUND AT POSITION %d WITH PATTERN %d",i+1,temp->data);
                temp=temp->node;
           }
    }
    return 0;
}
