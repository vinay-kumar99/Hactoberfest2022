#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char stack[100];
int top = -1;
char y[100];
void push(char s)
{
    int i;
    if(top>=99)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        top++;
        stack[top] = s;
    }
}
char pop()
{
    char ch;
    if(top<0)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        ch = stack[top];
        top--;
        return ch;
    }
}
int isoperator(char ch)
{
    if(ch=='*'|| ch=='/'|| ch=='^' || ch=='+'|| ch=='-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
int check(char ch)
{
    if(ch=='^')
    {
        return (3);
    }
    else if(ch== '/' || ch== '*')
    {
        return (2);
    }
    else if(ch=='-' || ch=='+')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
void scan(char s[])
{
    push('(');
    int i,l,k = 0;
    char ch;
    l = strlen(s);
    //printf("%d",l);
    for(i = 0; i<l; i++)
    {
       if(s[i]=='(')
       {
           push(s[i]);
       }
       else if(s[i]==')')
       {
           //ch = pop();
           while(stack[top]!='(')
           {
               ch = pop();
               y[k] = ch;
               k++;
           }
           char no = pop();
       }
       else if(isoperator(s[i])==1)
       {
           if(check(stack[top])>=check(s[i]))
           {

               while(stack[top]!= '(')
               {
                   ch = pop();
                   y[k]= ch;
                   k++;
               }
               push(s[i]);
           }
           else
           {
              push(s[i]);
           }
       }
       else
       {
           y[k] = s[i];
           k++;
       }
    }
    y[k] = '\0';
}
int main()
{

    while(1){
        char s[100];
        int i,l;
        printf("ENTER THE INFIX EXPRESSION : ");
        gets(s);
        strcat(s,")");
        scan(s);
        printf("\n===============\n");
        puts(y);
        printf("===============\n");
        printf("\n");
    }
    return 0;
}
