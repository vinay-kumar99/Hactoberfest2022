#include <stdio.h>
#define sz 10

struct stack
{
    float arr[sz];
    int top;
};

void initStack(struct stack *s){
	s->top = -1;
}

float value (char ch)
{
    float ct = 1;
    for (char j = 'a'; j <= 'z'; j++)
    {
        if (ch == j)
        {
        	return ct;
		}
         ct++;
    }
}

int operand(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    	return 1;
    return 0;
}

int operatorr(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

void push (struct stack *s, float val)
{
    if (s->top == sz-1)
        printf("Stack is Full!");
        
    else
    {
        s->top = s->top + 1;
        s->arr[s->top] = val;
    }
}

float pop (struct stack *s)
{
    if (s->top == -1)
    {
        return -1;
    }
    else
    {
        float y = s->arr[s->top];
        s->top = s->top - 1;
        return y;
    }
}

int main()
{
    struct stack s;
    initStack(&s);
    
    char postfix[sz];
    printf("Enter postfix expression to be evaluated: ");
    scanf("%s", postfix);
    
    int i = 0;
    float result;
    int fg = 1;
    
    while (postfix[i] != '\0')
    {
        if (operand(postfix[i]))
        {
            push(&s, value(postfix[i]));
        }
        
        else if (operatorr(postfix[i]))
        {
            float op2 = pop(&s);
            float op1 = pop(&s);
            
            if (op1 == -1 || op2 == -1)
            {
                fg = 0;
                printf("Invalid Postfix Expression");
                break;
            }
            
            switch(postfix[i])
            {
                case '+':
                	result = op1+op2;
					break;
                case '-':
					result = op1-op2;
                    break;
                case '*':
					result = op1*op2;
                    break;
                case '/':
					result = op2/op1;
                    break;
    
            }
            
            push(&s, result);
        }
        
        else
        {
            fg = 0;
            printf("ERROR");
            break;
        }
        
        i++;
    }
    
    if (fg == 1)
    {
        result = pop(&s);
        if(s.top != -1){
        	printf("Invalid Postfix Expression!");
        	return -1;
		}
        printf("Result: %f", result);
    }

}