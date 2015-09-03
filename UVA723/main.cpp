#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>

#define MAXLINE 1000
#define DEFAULT 0
#define COMMENT_0 1
#define COMMENT_1 2
#define STRING_LITERAL 3

using namespace std;

bool isEmpty(char *s, int len) {
    if (len == 0) {
        return true;
    }
    for (int i = 0; i < len; i++) {
        if (!isspace(s[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    char buffer[MAXLINE], c, prev = 0;
    int pos = 0, state = DEFAULT;
    bool stringLiteral = false;
    memset(buffer, 0, sizeof(buffer));
    while ((c = getchar()) != EOF) {
        if (state == COMMENT_0) { /* Ignore until a '*)' is read */
            if (c == ')' && prev == '*') {
                state = DEFAULT;
            }
        } else if (state == COMMENT_1) { /* Ignore until a '}' is read */
            if (c == '}') {
                state = DEFAULT;
            }
        } else {
            if (c == ' ') {
                if (state != STRING_LITERAL && prev == ' ') {
                /* Ignore */
                } else { /* The previous char is NOT a blank */
                    buffer[pos++] = c;
                }
            } else if (c == '*') {
                if (state != STRING_LITERAL && prev == '(') {
                    /* inside a comment */
                    state = COMMENT_0;
                    buffer[--pos] = 0;
                } else {
                    /* add to buffer */
                    buffer[pos++] = c;
                }
            } else if (state != STRING_LITERAL && c == '{') {
                state = COMMENT_1;
            } else if (c == '\'') {
                stringLiteral = !stringLiteral;
                state = (stringLiteral) ? STRING_LITERAL : DEFAULT;
                buffer[pos++] = c;
            } else if (state != STRING_LITERAL && c == '\n') {
                if (!isEmpty(buffer, pos)) {
                    buffer[pos] = 0;
                    printf("%s\n", buffer);
                }
                pos = prev = 0;
                buffer[0] = 0;
            } else {
                buffer[pos++] = c;
            }
        }
        prev = c;
    }
    return 0;
}
