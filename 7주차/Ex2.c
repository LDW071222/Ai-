#include <stdio.h>

int main() 
{
    int arr[3] = {10, 20, 30};
    int *p = arr; // 배열의 첫 번째 요소를 가리키는 포인터

    printf('%d', *p++);
    printf('%d', *p);
    
    //결과 값 = 10 20  원래 *p=10 -> ++ 주소 증가 -> p=20 -> *p=20

}