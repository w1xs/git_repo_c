#include<stdio.h>
#include<malloc.h>

int main(){
    int **din_matr;
    int size, flag, summ_main_diag, summ_loc_diag, i, j;
    int max_loc_diag_summ, count_numbers;

    scanf("%d", &size);
    din_matr = (int**)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        din_matr[i] = (int*)malloc(size * sizeof(int));
        for(int j = 0; j < size; j++){
            scanf("%d", &din_matr[i][j]);
        }
    }

    summ_main_diag = 0;
    summ_loc_diag = 0;
    max_loc_diag_summ = din_matr[0][0];

    // for(int i = 0, j = 0; i < size && j < size; i++, j++){
    //     summ_main_diag += din_matr[i][j];
    // }

    i = size - 1; j = 0; flag = 1;

    while(i >= 0 && j < size){
        if(flag){
            summ_loc_diag = 0;
            count_numbers = 0;
            for(int k = i, n = j; k < size && n < size; k++, n++){
                summ_loc_diag += din_matr[k][n];
                count_numbers += 1;
            }

            // if(summ_loc_diag == summ_main_diag){
            //     flag = 0;
            //     i = 0;
            //     j = 1;
            // }
            if(count_numbers == size){
                flag = 0;
                i = 0;
                j = 1;                
            }
            else{
                if(summ_loc_diag > max_loc_diag_summ){
                    max_loc_diag_summ = summ_loc_diag;
                }
                i--;                
            }
        }
        else{
            summ_loc_diag = 0;
            for(int k = i, n = j; k < size && n < size; k++, n++){
                summ_loc_diag += din_matr[k][n];
            }
            if(summ_loc_diag > max_loc_diag_summ){
                max_loc_diag_summ = summ_loc_diag;
            }
            j++;
        }
    }

    printf("%d", max_loc_diag_summ);

    for(int i = 0; i < size; i++){
        free(din_matr[i]);
    }
    free(din_matr);    

    return 0;
}    