#include<stdio.h>
#include<malloc.h>
#include <locale.h>

int input_matrix(float **matrix, int size){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(!scanf("%f", &matrix[i][j])){
                return 0;
            }
        }
    }
    return 1;
}

void output_matrix(float **matrix, int size){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            printf("%6.1f ", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

// void take_memory(float **matrix, int size){
//     int i;
//     matrix = (float**)malloc(size * sizeof(float*));
//     for(i = 0; i < size; i++){
//         matrix[i] = (float*)malloc(size * sizeof(float)); 
//     }
//     return;
// }    

void free_memory(float **matrix, int size){
    int i;
    for(i = 0; i < size; i++){
        free(matrix[i]);
    }
    free(matrix);
    return;
}


void summ_matrix_with_matrix_E(float **matrix, int size){
    int i;
    for(i = 0; i < size; i++){
        matrix[i][i] += 1;
    }
    return;
}

void multiplier_matrix(float **matrix_1, float **matrix_2, float **res_matrix, int size){
    float el_in_res_matr;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            el_in_res_matr = 0;
            for(int k = 0; k < size; k++){
                el_in_res_matr += (matrix_1[i][k] * matrix_2[k][j]);
            }
            res_matrix[i][j] = el_in_res_matr;
        } 
    }
    return;
}

void rotate_matrix_on_180(float **matrix_base, float **res_matrix, int size){
    int i, j;
    for(j = 0; j < size; j++){
        for(i = 0; i < size; i++){
            res_matrix[i][j] = matrix_base[(size-1) - i][(size-1) - j];
        }
    }
    return;
}

void main(){
    float **matrix_A, **matrix_B, **matrix_C;
    int size;

    setlocale(0,"");
    printf("Введите размер матрицы: ");
    if(!scanf("%d", &size)){
        printf("ERROR: Размер матирицы может быть только целым, положиельный числом");
        return;
    }

    matrix_A = (float**)malloc(size * sizeof(float*));
    for(int i = 0; i < size; i++){
        matrix_A[i] = (float*)malloc(size * sizeof(float));
    }
    matrix_B = (float**)malloc(size * sizeof(float*));
    for(int i = 0; i < size; i++){
        matrix_B[i] = (float*)malloc(size * sizeof(float));
    }
    matrix_C = (float**)malloc(size * sizeof(float*));
    for(int i = 0; i < size; i++){
        matrix_C[i] = (float*)malloc(size * sizeof(float));
    }
    // take_memory(matrix_A, size);
    // take_memory(matrix_B, size);
    // take_memory(matrix_C, size);

    printf("Введите матрицу:\n");
    if(!input_matrix(matrix_A, size)){
        printf("ERROR: Матрица может состоять только из вещественных чисел");
        return;
    }
    if(size < 0){
        printf("ERROR: Размер матрицы не может быть меньше нуля");
        return;
    }

    rotate_matrix_on_180(matrix_A, matrix_B, size);
    
    printf("Матрица A:\n");
    output_matrix(matrix_A, size);
    printf("Матрица B:\n");
    output_matrix(matrix_B, size);

    summ_matrix_with_matrix_E(matrix_B, size);
    multiplier_matrix(matrix_A, matrix_B, matrix_C, size);
    summ_matrix_with_matrix_E(matrix_C, size);

    printf("Матрица C:\n");
    output_matrix(matrix_C, size);
    
    free_memory(matrix_A, size);
    free_memory(matrix_B, size);
    free_memory(matrix_C, size);

    return;
}