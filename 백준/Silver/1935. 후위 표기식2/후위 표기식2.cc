#include <stdio.h>
#include <string.h>

double stack[101];
int top = -1;
double num[26];

void push(double n){
   top++;
   stack[top] = n;
}

double pop(){
   return stack[top--];
}

int main()
{
   
   int n = 0;
   scanf("%d", &n);

   char string[200];
   scanf("%s", string);

   for (int i = 0; i < n; i++)
   {
      scanf("%lf", &num[i]);
   }
   
   for (int i = 0; i < strlen(string); i++)
   {
      if (string[i] >= 'A' && string[i] <= 'Z')
      {
         push(num[string[i] - 'A']);
      }
      else if (string[i] == '*')
      {
         double a = pop();
         double b = pop();

         push(b * a);
      }
      else if (string[i] == '/')
      {
         double a = pop();
         double b = pop();

         push(b / a);
      }
      else if (string[i] == '+')
      {
         double a = pop();
         double b = pop();

         push(b + a);
      }
      else if (string[i] == '-')
      {
         double a = pop();
         double b = pop();

         push(b - a);
      } 
   }

   printf("%.2lf", stack[top]);

   return 0;
}

// 후위계산식 문제.
// 스택을 이용해 풀이.
// double형 처리 시, %lf를 사용하자.
// 입력 시, double을 %f로 처리하면 잘못된 메모리 접근 발생.