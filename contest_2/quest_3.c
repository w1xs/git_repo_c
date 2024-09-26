#include <stdio.h>
#include <malloc.h>

int main(){

    int* din_arr;
    int arr_len, input, count_diff;

    scanf("%d", &input);
    din_arr = (int*)malloc(input * sizeof(int));

    for(int i = 0; i < input; i++){
        scanf("%d", &din_arr[i]);
    }

    count_diff = 0;

    for(int i = 0; i < input; i++){
        for(int j = 0; j < input; j++)
            if(din_arr[i] == din_arr[j]){
                
            }
    }

    return 0;
}