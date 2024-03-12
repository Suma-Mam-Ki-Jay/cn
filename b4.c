#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
constexpr int bucketSize = 512;
void bktInput(int a, int b) {
if (a > bucketSize) {
std::cout << "\n\t Bucket Overflow";
} else {
usleep(500);
while (a > b) {
std::cout << "\n\t" << b << " bytes outputted";
a -= b;
usleep(500);
}
if (a > 0) {
std::cout << "\n\tlast " << a << " bytes sent\t";
std::cout << "\n\t\tBucket output successful";
}
}
}
int main() {
int op, pktsize;
srand(time(nullptr)); // Use nullptr instead of NULL for modern C++
std::cout << "Enter output rate: ";
std::cin >> op;
for (int i = 1; i <= 5; i++) {
usleep(rand() % 1000);
pktsize = rand() % 1000;
std::cout << "\nPacket no = " << i << " Packet size = " <<
pktsize;
bktInput(pktsize, op);
}return 0;
}
