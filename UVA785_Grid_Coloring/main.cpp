#include <iostream>
#include <vector>

/*
Accepted: 0.132s
Description: dfs, flood fill
*/

using namespace std;

#define read cin
#define out cout
#define MAXROWS 30
#define MAXCOLS 80

void clearArray(bool visited[MAXROWS][MAXCOLS]) {
    for (int i = 0; i < MAXROWS; i++)
        for (int j = 0; j < MAXCOLS; j++)
            visited[i][j] = false;
}

void dfs(vector<string> &v, char borderChar, int row, int col, char fillChar, bool visited[MAXROWS][MAXCOLS]) {
    if (row < 0 || col < 0 || row >= (int) v.size() || !v[row][col] || visited[row][col] || v[row][col] == borderChar)
        return;
    visited[row][col] = true;
    v[row][col] = fillChar;
    dfs(v, borderChar, row, col - 1, fillChar, visited);
    dfs(v, borderChar, row - 1, col, fillChar, visited);
    dfs(v, borderChar, row, col + 1, fillChar, visited);
    dfs(v, borderChar, row + 1, col, fillChar, visited);
}

char findBorderChar(vector<string> v) {
    for (int i = 0; i < (int) v.size(); i++)
        for (int j = 0; v[i][j]; j++)
            if (!isspace(v[i][j]) && v[i][j] != '_')
                return v[i][j];
    return 0;
}

int main() {
	string line, sepLine;
	bool process, visited[MAXROWS][MAXCOLS];

	while (1) {
        vector<string> v;
        process = false;
        while (!process && getline(read, line)) {
            if (line[0] == '_') {
                sepLine = line;
                process = true;
            } else
                v.push_back(line);
        }
        if (process) {
            clearArray(visited);
            char borderChar = findBorderChar(v);
            for (int i = 0; i < (int) v.size(); i++)
                for (int j = 0; v[i][j]; j++)
                    if (v[i][j] != borderChar && !isspace(v[i][j]) && !visited[i][j])
                        dfs(v, borderChar, i, j, v[i][j], visited);
            for (int i = 0; i < (int) v.size(); i++)
                out << v[i] << endl;
            out << sepLine << endl;
        } else
            break;
	}
    return 0;
}
