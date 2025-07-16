#include <iostream>
#include "stackClass.h"

void DecimalToBinary(int decimal) {
    stackClass stack;

    while (decimal > 0) {
        stack.Push(decimal % 2);
        decimal /= 2;
    }

    std::cout << "Binary: ";
    while (!stack.IsEmpty()) {
        std::cout << stack.Pop();  // 스택에서 값을 하나씩 꺼내어 출력
    }
    std::cout << std::endl;
}

int main() {
    int decimal = 26;
    std::cout << "Decimal: " << decimal << std::endl;
    DecimalToBinary(decimal);  // 26을 2진수로 변환하여 출력
    return 0;
}
