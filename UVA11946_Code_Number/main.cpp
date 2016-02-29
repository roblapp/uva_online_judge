#include <cstdio>
#include <cctype>
#include <map>

using namespace std;

int main() {
	int ncases;
	char c;
	map<char,char> m;
	m['0'] = 'O'; m['1'] = 'I'; m['2'] = 'Z'; m['3'] = 'E'; m['4'] = 'A';
	m['5'] = 'S'; m['6'] = 'G'; m['7'] = 'T'; m['8'] = 'B'; m['9'] = 'P';

	scanf("%d\n", &ncases);
	while ((c = getchar()) != EOF)
        (isdigit(c)) ? putchar(m[c]) : putchar(c);
    return 0;
}
