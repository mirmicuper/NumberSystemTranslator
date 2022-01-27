/*      переводчик между двоичной и десятичной системами
    
        ************************************************
     
        коды ошибок:
        error01 - ошибка ввода неверно введенного числа
        ...
*/
#include <iostream>
#include <cmath>

using namespace std;

bool error01(int arrBin[], int count) {
    bool flag = true;
    for(int i = 0; i < count; i++) {
        if(arrBin[i] == 1 || arrBin[i] == 0) {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    return flag;
}

int main() {
    int dec = 0;
    int value = 0;
    
    cout << "Выберете вариант перевода (0 - 10->2; 1 - 2->10): ";
    cin >> value;
    
    if (value == 0) {

        cout << "Введите десятичное число: ";
        cin >> dec;
        
        int j = 0;
        bool flag = false;
        
        //Определяем количество бит, => j
        while (!flag) {
            if(dec > pow(2,j)) {
                j++;
            }
            if(dec <= pow(2,j)) {
                flag = true;
            }
        }
        int n = j, m = j;
        int arrBin[j];
        //Заполняем Bin массив нулями с учетом кол-ва битов
        for(int i = 0; i < m; i++) {
            arrBin[i] = 0;
        }
        //Заменяем некоторые биты на True
        for (int i = 0, k = n - 1; i < j, k >= 0; i++, k--) {
            if(dec >= pow(2,k)) {
                arrBin[i] = 1;
                dec -= pow(2, k);
            }

        }
        //Выводим получившийся Bin массив
        cout << "Десятичное число в двоичной системе счисления: ";
        for(int i = 0; i < j; i++) {
            cout << arrBin[i] << " ";
        }
        cout << endl;
    }
    
    
    
    if (value == 1) {
        int arrBinPow[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        int temp;
        int dec = 0;
        cout << "Введите двоичное число: ";
        cin >> temp;
        const int N = temp;

        //Находим количество цифр в числе.
        int count = 1;
        temp = N; // Переписываем значение N в temp и работаем с temp
        while (temp /= 10)
            count++;

        //Выделяем память для массива с переменной count
        int *arrBin;
        arrBin = new int[count];

        //Заполняем массив
        int i = count - 1;
        temp = N;  // Переписываем значение N в temp и работаем с temp
        do {
            arrBin[i--] = temp % 10;
            temp /= 10;
        }
        while(temp);
        
        error01(arrBin, count);
        bool flag;
        if(flag == false) {
            return 0;
        }
        int tempC = count;
        int arrDecSum[count];
        //Заполнение Dec-массива
        for(int i = 0, j = tempC - 1; j > -1; i++, j--) {
            if(arrBin[i] == 1) {
                arrDecSum[i] = pow(2, arrBinPow[j]);
            }
            if (arrBin[i] == 0) {
                arrDecSum[i] = 0;
            }
        }
        //Получение dec-числа из массива
        for(int i = 0; i < count; i++) {
            dec += arrDecSum[i];
        }
        
        cout << "Десятичное число: " << dec << endl;

    }
}
