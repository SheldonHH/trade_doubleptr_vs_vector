#include <iostream>
#include <chrono>

using namespace std;

class Trade {
public:
    int tradeId;
    double price;
    int volume;

    Trade(int id, double pr, int vol) : tradeId(id), price(pr), volume(vol) {}
};

void testPointerPerformance(int amount) {
    Trade** trades = new Trade*[amount];

    auto start = chrono::high_resolution_clock::now();

    // 插入交易数据
    for (int i = 0; i < amount; ++i) {
        trades[i] = new Trade(i, 100.0 + i, 50 + i);
    }

    // 更新交易数据
    for (int i = 0; i < amount; ++i) {
        trades[i]->price += 1.0;
        trades[i]->volume += 1;
    }

    // 访问交易数据
    double totalPrice = 0.0;
    int totalVolume = 0;
    for (int i = 0; i < amount; ++i) {
        totalPrice += trades[i]->price;
        totalVolume += trades[i]->volume;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Pointer performance: " << duration.count() << " seconds." << endl;

    // 清理内存
    for (int i = 0; i < amount; ++i) {
        delete trades[i];
    }
    delete[] trades;
}
