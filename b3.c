#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
constexpr int MAX_NODES = 20;
struct Node {
std::vector<unsigned> dist;
std::vector<unsigned> from;
};
std::vector<Node> rt(MAX_NODES);
int main() {
int costmat[MAX_NODES][MAX_NODES];
int nodes;
std::cout << "\nEnter the number of nodes: ";
std::cin >> nodes;
std::cout << "\nEnter the cost matrix:\n";
for (int i = 0; i < nodes; i++) {
for (int j = 0; j < nodes; j++) {
std::cin >> costmat[i][j];
costmat[i][i] = 0; // Diagonal of cost matrix is 0
rt[i].dist.push_back(costmat[i][j]);
rt[i].from.push_back(j);
}
}
int count = 0;
do {
count = 0;
for (int i = 0; i < nodes; i++) {
for (int j = 0; j < nodes; j++) {
for (int k = 0; k < nodes; k++) {
if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
rt[i].from[j] = k;
count++;
}
}
}
}
} while (count != 0);
std::cout << "\n\nSOLUTION:\n\n";
for (int i = 0; i < nodes; i++) {
std::cout << "\n\nFor router " << i + 1 << "\n";for (int j = 0; j < nodes; j++) {
std::cout << "\t\nNode " << j + 1 << " via " << rt[i].from[j]
+ 1 << " distance " << rt[i].dist[j] << std::endl;
}
}
return 0;
}
