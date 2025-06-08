#include <iostream>
int main() {
    int* ptr = new int[10];
    ptr[0] = 1;
    std::cout << ptr[0] << std::endl;
    // delete[] ptr; // Intencionalmente omitido
    return 0;
}
