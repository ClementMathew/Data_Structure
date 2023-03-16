
// Infix to Postfix Conversion and Evaluation Using Stack

#include<stdio.h>
#include<ctype.h>

char stack[100], result[100],*e ,x;
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
    {
        return 0;
    }
    if(x == '+' || x == '-')
    {
        return 1;
    }
    if(x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}

void Evaluation()
{
    int n1,n2,n3,num;
    e = result;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();

            switch(*e)
            {
                case '+': n3 = n1 + n2;
                          break;

                case '-': n3 = n2 - n1;
                          break;

                case '*': n3 = n1 * n2;
                          break;

                case '/': n3 = n2 / n1;
                          break;
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression =  %d",pop());
}

int main()
{
    char exp[100];
    int i= 0;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
        {
            printf("%c ",*e);
            result[i]=*e;
            i++;
        }
        else if(*e == '(')
        {
            push(*e);
        }
        else if(*e == ')')
        {
            while((x = pop()) != '(')
            {
                printf("%c ", x);
                result[i] = x;
                i++;
            }
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
            {
                x = pop();
                printf("%c ",x);
                result[i] = x;
                i++;
            }
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        x = pop();
        printf("%c ",x);
        result[i] = x;
        i++;
    }
    Evaluation();
    return 0;
}
