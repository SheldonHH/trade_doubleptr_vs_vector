#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Order {
public:
    int orderId;
    double price;
    int quantity;
    bool isBuy; // true for buy order, false for sell order

    Order(int id, double pr, int qty, bool buy) 
        : orderId(id), price(pr), quantity(qty), isBuy(buy) {}
};

void processOrder(vector<Order>& orders, int id, double pr, int qty, bool buy) {
    orders.emplace_back(id, pr, qty, buy);
}

void testVectorPerformance(int amount) {
    vector<Order> orders;
    orders.reserve(amount); // 预先分配内存

    auto start = chrono::high_resolution_clock::now();

    // 插入订单
    for (int i = 0; i < amount; ++i) {
        processOrder(orders, i, 100.0 + i, 10 + i, i % 2 == 0);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Vector performance: " << duration.count() << " seconds." << endl;
}
