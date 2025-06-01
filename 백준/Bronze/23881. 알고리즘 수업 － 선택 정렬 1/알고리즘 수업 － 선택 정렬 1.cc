#include <stdio.h>

int num[10001];

void selection(int n, int k){
    int cnt = 0;

    for (int i = n - 1; i > 0; i--) {
        int max = i;

        for (int j = 0; j < i; j++) {
            if (num[j] > num[max]) {
                max = j;
            }
        }

        if (max != i) {
            int temp = num[i];
            num[i] = num[max];
            num[max] = temp;

            cnt++;

            if (cnt == k) {
                if (num[i] < num[max])
                    printf("%d %d\n", num[i], num[max]);
                else
                    printf("%d %d\n", num[max], num[i]);
                return;
            }
        }
    }

    printf("-1\n");
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    selection(n, k);

    return 0;
}