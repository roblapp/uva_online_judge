#include <iostream>
#include <cstring>

/*
Accepted: 0.072s
Category: string processing, string matching
Algorithm: Array representation of a binary tree
*/

using namespace std;

#define VISITED_BUT_NOT_ENDPOINT 1
#define ENDPOINT 2

int main() {
	string line;
	int N = 1;
	bool isDecodable = true;
	int tree[(1<<11) + 1] = {0};

	while (getline(cin, line)) {
        if (line == "9") {
            if (isDecodable)
                cout << "Set " << N++ << " is immediately decodable" << endl;
            else
                cout << "Set " << N++ << " is not immediately decodable" << endl;
            memset(tree, 0, sizeof(tree));
            isDecodable = true;
        } else if (isDecodable) {
            int index = 1, len = line.length();
            for (int i = 0; i < len and isDecodable; i++) {
                if (line[i] == '0') /* go left */
                    index = 2*index;
                else if (line[i] == '1') /* go right */
                    index = 2*index  + 1;
                if (tree[index] == ENDPOINT)
                    isDecodable = false;
                else if (i < len - 1) /* mark it if not the last element */
                    tree[index] = VISITED_BUT_NOT_ENDPOINT;
            }
            if (tree[index] != 0)
                isDecodable = false;
            else
                tree[index] = ENDPOINT;
        }
	}
    return 0;
}
