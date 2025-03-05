#include <stdio.h>

int main(){
    int sb = 0, jb = 0, hb = 0;
    int co = 0, sa = 0;
    int ansh = 0, ansb = 0;

    scanf("%d", &sb);
    ansh = sb;

    scanf("%d", &jb); 
    ansh = (ansh < jb) ? ansh : jb;

    scanf("%d", &hb);
    ansh = (ansh < hb) ? ansh : hb;

    scanf("%d", &co);
    ansb = co;
    
    scanf("%d", &sa);
    ansb = (ansb < sa) ? ansb : sa;

    printf("%d", ansh + ansb - 50);

    return 0;
}