#include <stdio.h>
#include <malloc.h>

int main(){
    int* ponit_arr;
    int i, arr_len, find_number, count_find_number;
    scanf("%d", &arr_len);

    ponit_arr = (int*)malloc(arr_len*sizeof(int));

    for( int i = 0; i < arr_len; i++){
        scanf("%d", &ponit_arr[i]);
    }

    scanf("%d", &find_number);
    count_find_number = 0;

    for(int i = 0; i < arr_len; i++){

        if(ponit_arr[i] == find_number){

            count_find_number += 1;

        }

    }

    printf("%d", count_find_number);

    return 0;
}