#include <stdio.h>
#include <string.h>

int count_re = 0;

int recursion(const char *s, int l, int r){
    count_re++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    int T;
    scanf("%d", &T);

    char s[100];
    while (T--)
    {
        count_re = 0;
        scanf("%s", s);
        printf("%d %d\n", isPalindrome(s), count_re);
    }
    
    return 0;
}