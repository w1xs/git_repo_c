#include<stdio.h>
#include<malloc.h>

int main(){
    int **din_matr;
    int str, column, number_of_change;
    int pointer, buffer;

    scanf("%d %d", &str, &column);
    din_matr = (int**)malloc(str * sizeof(int));
    for(int i = 0; i < str; i++){
        din_matr[i] = (int*)malloc(column * sizeof(int));
        for(int j = 0; j < column; j++){
            scanf("%d", &din_matr[i][j]);
        }
    }

    scanf("%d", &number_of_change);

    if(number_of_change >= str || number_of_change < 0){
        for (int i = 0; i < str; i++){
            for (int j = 0; j < column; j++){
                printf("%d ", din_matr[i][j]);
            }
            printf("\n");
        }
        return 0;
    }

    pointer = 0;


    while(pointer < column - pointer){
        buffer = din_matr[number_of_change][pointer];
        din_matr[number_of_change][pointer] = din_matr[number_of_change][column - pointer-1];
        din_matr[number_of_change][column - pointer-1] = buffer;
        pointer++;
    }
        

    for (int i = 0; i < str; i++){
        for (int j = 0; j < column; j++){
            printf("%d ", din_matr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < str; i++){
        free(din_matr[i]);
    }
    free(din_matr);        

    return 0;
}