#include <stdio.h>

int main() {
    int arr[] = {5, 3, 8, 1, 2};
    int n = 5;

    // 삽입 정렬은 두 번째 원소부터 시작한다.
    // 첫 번째 원소는 이미 정렬되어 있다고 생각한다.
    for (int i = 1; i < n; i++) {

        // 현재 삽입할 값을 따로 저장한다.
        int key = arr[i];

        int j = i - 1;

        // 삽입 정렬의 핵심:
        // key보다 큰 값들을 한 칸씩 뒤로 이동시킨다.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // 빈자리에 key를 삽입한다.
        // 버블 정렬과 달리 바로 옆 값과 계속 교환하지 않는다.
        arr[j + 1] = key;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}