#include <iostream>

void testPointerPerformance(int amount);
void testVectorPerformance(int amount);

int main() {
    int amount = 1000000; // 1,000,000 笔交易或订单

    std::cout << "Testing pointer-based Trade performance:" << std::endl;
    testPointerPerformance(amount);

    std::cout << "\nTesting vector-based Order performance:" << std::endl;
    testVectorPerformance(amount);

    return 0;
}

/*
g++ -o performance main.cpp trade_ptr.cpp trade_vector.cpp
./performance
双指针（Trade**）的优势在于它允许动态分配和管理大量对象的内存，
可以灵活地创建和销毁对象，减少不必要的内存分配和释放操作，
提高内存管理的效率
*/