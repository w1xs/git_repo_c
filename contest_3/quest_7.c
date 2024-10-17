#include<stdio.h>
#include<malloc.h>

int main(){
    int **din_matr;
    int str, column, count_res;


    scanf("%d %d", &str, &column);
    din_matr = (int**)malloc(str * sizeof(int));
    for(int i = 0; i < str; i++){
        din_matr[i] = (int*)malloc(column * sizeof(int));
        for(int j = 0; j < column; j++){
            scanf("%d", &din_matr[i][j]);
        }
    }

    count_res = 0;

    for(int i = 0; i < str; i++){
        for(int j = 0; j < column; j++){
            if(str != 1 && column != 1){
                if(i == str - 1){
                    if(j == 0){
                        if(din_matr[i][j] < din_matr[i-1][j] && din_matr[i][j] < din_matr[i][j+1]){
                            count_res += 1;
                        }
                    }
                    if(j == column - 1){
                        if(din_matr[i][j] < din_matr[i-1][j] && din_matr[i][j] < din_matr[i][j-1]){
                            count_res += 1;
                        }
                    }
                    if(j != 0 && j != column - 1){
                        if(din_matr[i][j] < din_matr[i-1][j] && din_matr[i][j] < din_matr[i][j+1] && din_matr[i][j] < din_matr[i][j-1]){
                            count_res += 1;
                        }
                    }
                }
                if(i == 0){
                    if(j == 0){
                        if(din_matr[i][j] < din_matr[i+1][j] && din_matr[i][j] < din_matr[i][j+1]){
                            count_res += 1;
                        }
                    }
                    if(j == column - 1){
                        if(din_matr[i][j] < din_matr[i+1][j] && din_matr[i][j] < din_matr[i][j-1]){
                            count_res += 1;
                        }
                    }
                    if(j != 0 && j != column - 1){
                        if(din_matr[i][j] < din_matr[i+1][j] && din_matr[i][j] < din_matr[i][j+1] && din_matr[i][j] < din_matr[i][j-1]){
                            count_res += 1;
                        }
                    }                
                }
                if(j == column - 1){
                    if(i != 0 && i != str - 1){
                        if(din_matr[i][j] < din_matr[i+1][j] && din_matr[i][j] < din_matr[i][j-1] && din_matr[i][j] < din_matr[i-1][j]){
                            count_res += 1;
                        }
                    }
                }            
                if(j == 0){
                    if(i != 0 && i != str - 1){
                        if(din_matr[i][j] < din_matr[i+1][j] && din_matr[i][j] < din_matr[i][j+1] && din_matr[i][j] < din_matr[i-1][j]){
                            count_res += 1;
                        }
                    }                
                }
                if(i != 0 && i != str -1 && j != 0 && j != column -1){
                    if(din_matr[i][j] < din_matr[i][j-1] && din_matr[i][j] < din_matr[i+1][j] && din_matr[i][j] < din_matr[i][j+1] && din_matr[i][j] < din_matr[i-1][j]){
                        count_res += 1;
                    }
                }
            }
            else{
                if(str == 1 && column != 1){
                    if(j == 0){
                        if(din_matr[i][j] < din_matr[i][j+1]){
                            count_res += 1;
                        }
                    }    
                    if(j == column -1){
                        if(din_matr[i][j] < din_matr[i][j-1]){
                            count_res += 1;
                        }
                    }    
                    if(j != 0 && j != column - 1){
                        if(din_matr[i][j] < din_matr[i][j-1] && din_matr[i][j] < din_matr[i][j+1]){
                            count_res += 1;
                        }
                    }    
                }

                if(column == 1 && str != 1){
                    if(i == 0){
                        if(din_matr[i][j] < din_matr[i+1][j]){
                            count_res += 1;
                        }
                    }    
                    if(i == str -1){
                        if(din_matr[i][j] < din_matr[i-1][j]){
                            count_res += 1;
                        }
                    }    
                    if(i != 0 && i != str - 1){
                        if(din_matr[i][j] < din_matr[i-1][j] && din_matr[i][j] < din_matr[i+1][j]){
                            count_res += 1;
                        }
                    }    
                }

                if(str == 1 && column == 1){
                    count_res += 1;
                }                
            }    
        }
    }

    printf("%d", count_res);

    for(int i = 0; i < str; i++){
        free(din_matr[i]);
    }
    free(din_matr);    

    return 0;
}