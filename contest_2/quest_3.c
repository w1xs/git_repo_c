#include <stdio.h>
#include <malloc.h>

int main(){

    int* din_arr;
    int arr_len, count_diff, flag;

    scanf("%d", &arr_len);
    din_arr = (int*)malloc(arr_len * sizeof(int));

    for(int i = 0; i < arr_len; i++){
        scanf("%d", &din_arr[i]);
    }

    count_diff = 1;

    for(int i = 0; i < arr_len; i++){
        int j = 0;
        while(j < i && din_arr[i] != din_arr[j]){
            j += 1;
            if(i == j){
                count_diff += 1;
            }
        }
    }
    printf("%d", count_diff);

    return 0;
}