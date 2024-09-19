#include<stdio.h>
int main(){
    float x_f_point, y_f_point, x_s_point, y_s_point, b, k;
    scanf("%f%f%f%f", &x_f_point, &y_f_point, &x_s_point, &y_s_point);
    if (x_f_point == x_s_point){
        printf("x=%.2f", x_s_point);
    }
    else{
        if (y_f_point == y_s_point){
            printf("y=%.2f", y_f_point);
        }
        else{
            k = (y_f_point - y_s_point) / (x_f_point - x_s_point);
            b = y_s_point - k * x_s_point;
            if (b > 0){
                printf("y=%.2fx+%.2f", k, b);
            }
            else{
                if (b < 0){
                    printf("y=%.2fx%.2f", k, b);                    
                }
                else{
                    printf("y=%.2fx", k);
                }
            }            
        }
    }
    return 0;
}