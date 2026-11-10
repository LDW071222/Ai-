#include <stdio.h>

int main() {
    int arr[] = {5, 3, 8, 1, 2};
    int n = 5;
    int temp;

    // 버블 정렬은 처음부터 끝까지
    // 인접한 두 값을 비교한다.
    for (int i = 0; i < n - 1; i++) {

        // arr[j]와 arr[j + 1]을 비교
        // 큰 값을 오른쪽으로 이동시킨다.
        for (int j = 0; j < n - 1 - i; j++) {

            if (arr[j] > arr[j + 1]) {
                // 버블 정렬의 핵심:
                // 두 값을 직접 교환한다.
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}