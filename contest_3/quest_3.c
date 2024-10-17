#include<stdio.h>
#include<malloc.h>

int main(){
    int **din_matr;
    int str, column, min_summ, local_summ;

    scanf("%d %d", &str, &column);
    din_matr = (int**)malloc(str * sizeof(int));
    for(int i = 0; i < str; i++){
        din_matr[i] = (int*)malloc(column * sizeof(int));
        for(int j = 0; j < column; j++){
            scanf("%d", &din_matr[i][j]);
        }
    }

    min_summ = 0;

    if(column == 1){
        printf("0");
    }
    else{
        for(int i = 0; i < str; i++){
            min_summ += din_matr[i][0];
        }

        for(int i = 0; i < column; i++){
            local_summ = 0;
            for(int j = 0; j < str; j++){
                local_summ += din_matr[j][i];
            }
            printf("%d ", local_summ);
            if(local_summ < min_summ){
                min_summ = local_summ;
            }
        }

        for(int i = 0; i < column; i++){
            local_summ = 0;
            for(int j = 0; j < str; j++){
                local_summ += din_matr[j][i];
            }
            if(local_summ == min_summ){
                printf("\n%d ", i);
            }
        }        

    }

    for(int i = 0; i < str; i++){
        free(din_matr[i]);
    }
    free(din_matr);    

    return 0;
}