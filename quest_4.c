#include<stdio.h>
int main(){
    int side_a, side_b, i, j;
    char fill;
    scanf("%d%d", &side_a, &side_b);
    scanf("%c", &fill);
    if (side_a > 0 && side_b > 0){
        for(i = 1; i<=side_a; i++){
            for(j = 1; j<=side_b; j++){
                printf("%c", fill);                
            }
            printf("\n");
        }
    }
    return 0;
}