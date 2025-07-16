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
        std::cout << stack.Pop();  // ���ÿ��� ���� �ϳ��� ������ ���
    }
    std::cout << std::endl;
}

int main() {
    int decimal = 26;
    std::cout << "Decimal: " << decimal << std::endl;
    DecimalToBinary(decimal);  // 26�� 2������ ��ȯ�Ͽ� ���
    return 0;
}
