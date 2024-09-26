#include <stdio.h>
#include <malloc.h>

int main(){
    int* din_arr;
    int arr_len, buffer;

    scanf("%d", &arr_len);

    if(arr_len >= 0){ 
        din_arr = (int*)malloc(arr_len * sizeof(int));

        for(int i = 0; i < arr_len; i++){
            scanf("%d", &din_arr[i]);
        }

        for(int i = 0; i < (arr_len-1); i++){
            if(din_arr[i] % 3 != 0){
                for(int j = i; j < arr_len; j++){
                    if(din_arr[j] % 3 != 0){
                        if(din_arr[j] > din_arr[i]){
                            buffer = din_arr[i];
                            din_arr[i] = din_arr[j];
                            din_arr[j] = buffer;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < arr_len; i++){
            printf("%d ", din_arr[i]);
        }

    }
    return 0;
}