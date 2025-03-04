#include <stdio.h>
#include <string.h>

int count = 0;

int recursion(const char* s, int l, int r) {
    count++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else {
        return recursion(s, l + 1, r - 1);
    }
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    int t = 0;
    char string[1001];

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%s", string);

        count = 0;
        int n = isPalindrome(string);
        
        printf("%d %d\n", n, count);
    }
    
    return 0;
}