#include<stdio.h>
int main(){
    int side_a, side_b, i, j;
    char fill;
    scanf("%d%d\n", &side_a, &side_b); // Получаем 2 целых цисла. side_a = количество строк в прямоугольнке, side_b = число символов в одной строке
    scanf("%c", &fill); // Получаем символ, которым будет закрашен прямоугольник. fill = символ.
    if (side_a > 0 && side_b > 0){ // Проверям, что обе стороны прямоугольника больше нуля
        for(i = 1; i<=side_a; i++){ // Пробегаемся по строкам от 1 до side_a
            for(j = 1; j<=side_b; j++){ // Пробегаемся по числу символов от 1 до side_b
                printf("%c", fill); // На каждый шаг цикла j выводим один символ в строку               
            }
            printf("\n"); // После вывода всех символов текущей строки, переходим на другую строку
        }
    }
    return 0;
}