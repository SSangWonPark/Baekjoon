#include <stdio.h>

float heap[100001];
int idx = 0;

void addheap(float v){

    idx++;
    heap[idx] = v;
    int cur = idx;

    while (cur > 1)
    {
        int p = cur / 2;

        if (p < 1)
        {
            return;
        }
        
        if (heap[p] > heap[cur])
        {
            float temp = heap[p];
            heap[p] = heap[cur];
            heap[cur] = temp;
            cur = p;
        }
        else{
            return;
        }
        
    } 
}

float delheap(){

    if (idx == 0)
    {
        return -999;
    }

    float res = heap[1];
    heap[1] = heap[idx];
    idx--;

    int cur = 1;

    while (1)
    {
        int c = cur * 2;

        if (c > idx)
        {
            return res;
        }

        if (c + 1 <= idx && heap[c] > heap[c + 1])
        {
            c++;
        }
        
        if (heap[c] < heap[cur])
        {
            float temp = heap[c];
            heap[c] = heap[cur];
            heap[cur] = temp;
            cur = c;
        }
        else{
            return res;
        }
        
    } 
}

int main(){
    int n = 0, m = 0, k = 0;
    float x = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x);

        addheap(x);
    }

    for (int i = 0; i < n - 1; i++)
    {
        float a = delheap();
        float b = delheap();

        addheap((a + b) / 2);
    }

    printf("%f", delheap());

    return 0;
}

// 최소힙을 활용