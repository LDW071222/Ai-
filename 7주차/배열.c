#include <stdio.h>

#define MAX_SIZE 10 //배열의 크기 정의

int main ()
{
    int ary[] = {1,2,3,4,5,6,7,8,9,10};
    int * TStart;
    int * TEnd;

    //배열을 정방향으로 출력
    printf('Array forward : ');
    for (TStart = ary, TEnd = ary+ MAX_SIZE; TStart < TEnd; TStart++)
    printf('%3d', *TStart);

    printf('\n');

    //배열을 역방향으로 출력
    printf('Array backward:');
    for (TStart = TEnd -1;TStart >= ary; TStart--)
    printf('%3d', *TStart);
}