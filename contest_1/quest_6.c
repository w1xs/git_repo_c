#include<stdio.h>
int main(){
    int input, go_to_work, count_simple, chislo, is_easy_number;

    go_to_work = scanf("%d", &input); // Аналогичные действия с задачей 5, но тут input = количество простых чисел, которые нужно вывести
    if (go_to_work != 0 && input > 0){ // Проверка, что пользователь не дятел
        input -= 1; // Уменьшаем input на 1, в соответствии с условиями задачи
        if(input == 0){ // Если input стал 0, значит пользователь ввел в консоль 1 и на экран ему надо вывести 1
            printf("1 ");
        }
        else{
            printf("1 "); // Выводим 1 на экран в любом случае         
            count_simple = 0; // Заводим переменную для подсчета найденных простых чисел
            chislo = 1; // Заводим переменную для перебора всех чисел
            while(count_simple < input){ // Пока число найденных простых чисел меньше, чем input
                chislo += 1; // Берем новое число для его анализа
                is_easy_number = 1;
                for(int del = 2; del*del <= chislo; del++){ //
                    if(chislo % del == 0){                  // Аналогично с 5 задачей, ищем делители
                        is_easy_number = 0;                 //
                        break;
                    }
                }
                if(is_easy_number){
                    count_simple += 1;  // Если не нашли делители, то увеличиваем счетчик простых чисел на 1
                    printf("%d ", chislo); // Выводим это простое число в консоль
                }
            }
        }
    }
    else{
        printf("ERROR"); // Ну тут ежу понятно, что мы делаем
    }

    return 0;
}