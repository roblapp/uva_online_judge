#include <cstdio>
#include <cctype>
#include <map>

/*
Accepted: 0.000s
Category: string processing, encode/decode
Algorithm: ad-hoc
*/

using namespace std;

int main() {
	char c;
	map<char,char> m;
    m['e'] = 'q'; m['d'] ='a'; m['c'] ='z';
    m['r'] ='w'; m['f'] ='s'; m['v'] ='x';
    m['t'] ='e'; m['g'] ='d'; m['b'] ='c';
    m['y'] ='r'; m['h'] ='f'; m['n'] ='v';
    m['u'] ='t'; m['j'] ='g'; m['m'] ='b';
    m['i'] ='y'; m['k'] ='h'; m[','] ='n';
    m['o'] ='u'; m['l'] ='j'; m['.'] ='m';
    m['p'] ='i'; m[';'] ='k'; m['/'] =',';
    m['['] ='o'; m['\''] ='l';
    m[']'] ='p';
    m['\\'] ='[';

    while ((c = getchar()) != EOF)
        (isspace(c)) ? putchar(c) : putchar(m[tolower(c)]);

    return 0;
}
