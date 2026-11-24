#include <stdio.h>

enum TraficLight {
   Red,
   Yellow,
   Green
};

int main() {

   enum TraficLight signal;
//신호 상태를 green으로 설정
signal = Green;

//현재 신호등의 상태에 따른 동작 출력
switch (signal) {
case Red:
   printf("Stop\n");
   break;
case Yellow:
   printf('Caution\n');
   break;
case Green:
   printf('Go\n');
   break;
default:
   printf('Unknown signal\n');
   break;
}

return 0;
}
