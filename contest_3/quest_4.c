#include<stdio.h>
#include<malloc.h>

int main(){
    int **din_matr;
    int size, flag, global_summ, local_summ;

    scanf("%d", &size);
    din_matr = (int**)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        din_matr[i] = (int*)malloc(size * sizeof(int));
        for(int j = 0; j < size; j++){
            scanf("%d", &din_matr[i][j]);
        }
    }

    // printf("\n");

    // for (int i = 0; i < size; i++){
    //     for (int j = 0; j < size; j++){
    //         printf("%d ", din_matr[i][j]);
    //     }
    //     printf("\n");
    // } 

    global_summ = 0;

    for(int i = 0; i < size; i++){
        global_summ += din_matr[i][0];
    }

    flag = 1;

    for(int i = 0; i < size; i++){
        local_summ = 0;
        for(int j = 0; j < size; j++){
            local_summ += din_matr[i][j];
        }
        if(local_summ != global_summ){
            flag = 0;
            break;
        }
    }

    for(int i = 0; i < size; i++){
        local_summ = 0;
        for(int j = 0; j < size; j++){
            local_summ += din_matr[j][i];
        }
        if(local_summ != global_summ){
            flag = 0;
            break;
        }
    }

    local_summ = 0;
    for(int i, j = 0; i < size && j < size; i++, j++){
        local_summ += din_matr[i][j];
    }    
    if(local_summ != global_summ){
        flag = 0;
    }

    local_summ = 0;
    for(int i = 0, j = size-1; i < size && j >= 0; i++, j--){
        local_summ += din_matr[i][j];
    }    
    if(local_summ != global_summ){
        flag = 0;
    }

    if(flag && size >= 0){
        printf("YES");
    }
    else{
        printf("NO");
    }    

    return 0;
}