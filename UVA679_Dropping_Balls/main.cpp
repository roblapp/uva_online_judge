#include <iostream>
#include <cmath>

/*
Accepted: 0.159s
Description: binary search(ish), simulation
*/

using namespace std;

int siftDown(int node, int numBalls, int maxNode) {
    /* if current false, set to true and go left */
    /* if current true, set to false and go right */
    int leftChild = 2*node, rightChild = 2*node + 1;
    if (leftChild < maxNode && rightChild < maxNode)
        return (numBalls % 2 == 0) ? siftDown(rightChild, numBalls/2, maxNode) : siftDown(leftChild, numBalls/2 + 1, maxNode);
    else
        return node;
}

int main() {
	int n, depth, numBalls;

	cin >> n;
	while (n--) {
        cin >> depth >> numBalls;
        cout << siftDown(1, numBalls, pow(2, depth)) << endl;
	}
    return 0;
}
