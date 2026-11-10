#include <stdio.h>

#define MAX_STUDENTS 50

void bubbleSort(int*arr, int size);

void bubbleSort(int*arr, int size){
    for (int i = 0; i < size - 1 i++){
        for(int j =0; j < size -i -1; j++){
            if(*(arr + j)> *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j +1);
                *(arr + j +1) = temp;
            }
        }
    }
}

int main() {
    int numStudents;
    print('학생 수를 입력하세요. (최대 50명):', MAX_STUDENTS);
    scanf('%d',&numStudents);
}