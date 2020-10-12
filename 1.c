#include<stdio.h>
#include<string.h>
#include<math.h>


int checkDelimiter(char str[],int i,char check){

    if(check != 45){
        printf("-1\n");
        return 0;
    }
    else{
        check = str[++i];
        if(check != 49){
            printf("-1\n");
            return 0;
        }
        else{
            check = str[++i];
            if(check!=32){
                printf("-1\n");
                return 0;
            }
        }
        check = str[++i];
    }
    
}


int main(){
    char str[100000];
    fgets(str,100000,stdin);
    int size=0;
    
    int i=0;
    char check = str[i];

    // for(int j=0;j<strlen(str);j++){
    //     printf("%d\n",str[j]);
    //     printf("%c\n",str[j]);
    // }

    while(1){
        if(check == 32){
            // printf("Break");
            break;
        }
        else if(48<=check && check<=57){
            size = size*10;
            size += (int)check - 48;
            // printf("%d\n",size);
            check = str[++i];
            // printf("%d\n",check);
        }
        else{
            printf("-1\n");
            return 0;
        }
    }

    // printf("%d\n",size);
    check = str[++i];
    if(check != 45){
        printf("-1\n");
        return 0;
    }
    else{
        check = str[++i];
        if(check != 49){
            printf("-1\n");
            return 0;
        }
        else{
            check = str[++i];
            if(check!=32){
                printf("-1\n");
                return 0;
            }
        }
        check = str[++i];
    }

    float vector1[size],vector2[size];
    for(int j=0;j<size;j++){
        vector1[j] = 0;
        vector2[j] = 0;
    }

    for(int j=0;j<size;j++){
        while(1){
            //Check for decimal(dot)
            if(check == 46){
                check = str[++i];
                int count = 0;
                while(1){
                    if(check == 44 || check == 32){
                        break;
                    }
                    else if(48<=check && check<=57){
                        vector1[j] = vector1[j]*10;
                        vector1[j] += (int) check - 48;
                        count++;
                        check = str[++i];
                    }
                    else{
                        printf("%d\n",j);
                        printf("-1 after dot\n");
                        return 0;
                    }
                }
                vector1[j] = vector1[j]/(pow(10,count));
                break;
            }
            else if(48<=check && check<=57){
                vector1[j] = vector1[j]*10;
                vector1[j] += (int)check - 48;
                // printf("%d\n",size);
                check = str[++i];
                // printf("%d\n",check);
            }
            else{
                printf("-1 before dot\n");
                return 0;
            }
        }
        check = str[++i];
        // printf("%f\n",vector1[j]);
        if(vector1[j]<=0){
            printf("-1\n");
            return 0;
        }
    }

    if(check != 45){
        printf("-1\n");
        return 0;
    }
    else{
        check = str[++i];
        if(check != 49){
            printf("-1\n");
            return 0;
        }
        else{
            check = str[++i];
            if(check!=32){
                printf("-1\n");
                return 0;
            }
        }
        check = str[++i];
    }

    printf("Success\n");
}