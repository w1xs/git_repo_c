#include<stdio.h>
#include<malloc.h>

int main(){
    int **din_matr;
    int size, flag;
    int count_same;

    scanf("%d", &size);
    din_matr = (int**)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        din_matr[i] = (int*)malloc(size * sizeof(int));
        for(int j = 0; j < size; j++){
            scanf("%d", &din_matr[i][j]);
        }
    }

    count_same = 0;
        
    for(int i = 0; i < size; i++){
        flag = 1;
        for(int j = 0; j < size; j++){
            if(din_matr[i][j] != din_matr[j][i]){
                flag = 0;
                break;
            }
        }
        if(flag){
            count_same += 1;
            printf("%d ", i);
        }
    }

    if(count_same == 0){
        printf("-1");
    }        

    return 0;
}