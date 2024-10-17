#include<stdio.h>
#include<malloc.h>

int main(){

    int **din_matr;
    int str, column, count_sedl, number;
    int flag;

    scanf("%d %d", &str, &column);
    din_matr = (int**)malloc(str * sizeof(int));
    for(int i = 0; i < str; i++){
        din_matr[i] = (int*)malloc(column * sizeof(int));
        for(int j = 0; j < column; j++){
            scanf("%d", &din_matr[i][j]);
        }
    }

    count_sedl = 0;
    for(int i = 0; i < str; i++){
        for(int j = 0; j < column; j++){

            number = din_matr[i][j];
            flag = 1;
            for(int k = 0; k < column; k++){
                if(number > din_matr[i][k]){
                    flag = 0;
                }
            }

            for(int k = 0; k < str; k++){
                if(number < din_matr[k][j]){
                    flag = 0;
                }
            }

            if(flag){
                count_sedl += 1;
            }            

        }
    }
    
    printf("%d", count_sedl);

    for(int i = 0; i < str; i++){
        free(din_matr[i]);
    }
    free(din_matr);

    return 0;
}