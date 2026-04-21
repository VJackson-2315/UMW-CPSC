#include <string.h>
#include <stdio.h>
#include <ctype.h>

void uppercase(char* s) {
    int r = 0;
    char i = s[r];
    while (strlen(s) != r) {
        i = toupper(i);
        s[r] = i;
        r++;
        i = s[r];
    }
}

int main() {
    char msg [32] = "this should be upper case!";
    uppercase(msg);
    printf("%s", msg);
    return 0;
} 
