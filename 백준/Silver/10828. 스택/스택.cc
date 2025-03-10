#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
	int arr[MAX_SIZE];
	int top;
} Stack;

void InitStack(Stack* stack) {
	stack->top = -1;
}

int IsEmpty(Stack* stack) {
	if (stack->top == -1) return true;
	else return false;
}

int IsFull(Stack* stack) {
	if (stack->top + 1 >= MAX_SIZE) return true;
	else return false;
}

int Size(Stack* stack) {
	return ((stack->top) + 1);
}

int Top(Stack* stack) {
	if (IsEmpty(stack)) return -1;
	return stack->arr[stack->top];
}

void Push(Stack* stack, int data) {
	if (IsFull(stack)) return;
	stack->arr[++(stack->top)] = data;
}

int Pop(Stack* stack) {
	if (IsEmpty(stack)) return -1;
	return stack->arr[(stack->top)--];
}

int main() {
	char str[6];
	Stack stack;
	int num, data;

	scanf("%d", &num);
	InitStack(&stack);

	while (num > 0) {
		scanf("%s", str);

		if (!strcmp(str, "push")) {
			scanf("%d", &data);
			fgetc(stdin);
			Push(&stack, data);
		}
		else if (!strcmp(str, "pop")) {
			printf("%d\n", Pop(&stack));
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", Size(&stack));
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", IsEmpty(&stack));
		}
		else if (!strcmp(str, "top")) {
			printf("%d\n", Top(&stack));
		}
		num--;
	}

  scanf("%d", &num);

	return 0;
}
