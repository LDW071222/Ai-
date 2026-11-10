#include <stdio.h>

int main() {
    int number[] = {3, 7, 12, 24, 45};
    size_t size = sizeof(number) / sizeof(number[0]);

    printf("배열 요소의 개수: %zu\n", size);

    //각 요소에 해당 인덱스의 제곱값을 곱하여 저장
    for (size_t i = 0; i < size; i++){
        number[i] = number[i] * (i*i);
    }
    //저장된 값을 출력
    for (size_t i = 0; i < size; i++) {
        printf("number[%zu] = %d\n", i, number[i]);
    }
    return 0;
}