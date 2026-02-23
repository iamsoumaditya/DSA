#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top = -1;
int isFull(){
    if (top == MAX - 1)
        return 1;
    return 0;
}
int isEmpty(){
    if (top == -1)
        return 1;
    return 0;
}
void push(char val){
    if (isFull()){
        printf("Stack overflow!!");
        return;
    }
    top++;
    stack[top] = val;
}
char pop(){
    if (isEmpty())
        return ' ';
    return stack[top--];
}

int prec(char ch){
    if (ch == '^' || ch == '%')
        return 3;
    else if (ch == '*' || ch == '/' )
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
int isOperand(char ch){
    if((ch >= 'A' && ch <='Z') || (ch>= 'a' && ch<= 'z') || (ch>='0'&& ch<='9'))
        return 1;
    return 0;
}
int isOperator(char ch){
    if(ch == '+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='%')
        return 1;
    return 0;
}

void reverse(char arr[]){
    int n = strlen(arr);
    for (int i = 0; i < n / 2;i++){
        char temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++){
        if (arr[i] == '(')
            arr[i] = ')';
        else if (arr[i] == ')')
            arr[i] = '(';
    }
}

void infixToPostfix(char infix[], char postfix[]){
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else if(infix[i]== '('){
            push(infix[i++]);
        }
        else if(infix[i]== ')'){
            while(stack[top]!= '('){
                char ch = pop();
                postfix[j++] = ch;
            }
            pop();
            i++;
        }
        else if(isOperator(infix[i])){
            if(isEmpty()){
                push(infix[i++]);
            }
            else if(stack[top] == '('){
                push(infix[i++]);
            }
            else{
                while(stack[top] != '(' && prec(infix[i]) <= prec(stack[top])){
                    char ch = pop();
                    postfix[j++] = ch;
                }
                push(infix[i++]);
            }
        }
        else{
            printf("ERROR: Input symbol\n");
            exit(0);
        }
    }
    while(!isEmpty()){
        char ch = pop();
        postfix[j++] = ch;
    }
    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[]){
    reverse(infix);
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            prefix[j++] = infix[i++];
        }
        else if(infix[i]== '('){
            push(infix[i++]);
        }
        else if(infix[i]== ')'){
            while(stack[top]!= '('){
                char ch = pop();
                prefix[j++] = ch;
            }
            pop();
            i++;
        }
        else if(isOperator(infix[i])){
            if(isEmpty()){
                push(infix[i++]);
            }
            else if(stack[top] == '('){
                push(infix[i++]);
            }
            else{
                while(stack[top] != '(' && prec(infix[i]) < prec(stack[top])){
                    char ch = pop();
                    prefix[j++] = ch;
                }
                push(infix[i++]);
            }
        }
        else{
            printf("ERROR: Input symbol\n");
            exit(0);
        }
    }
    while(!isEmpty()){
        char ch = pop();
        prefix[j++] = ch;
    }
    prefix[j] = '\0';
    reverse(prefix);
}

int postfixResult(char postfix[]){
    int i = 0, res;
    while(postfix[i] !='\0'){
        if(isOperand(postfix[i])){
            push(postfix[i++]);
        }else{
            int op2 = pop() - '0';
            int op1 = pop() - '0';
            switch(postfix[i]){
                case '+' :
                     res = op2 + op1;
                     break;
                case '-' :
                     res = op2 - op1;
                    break;
                case '*' :
                     res = op2 * op1;
                    break;
                case '/' :
                     res = op2 / op1;
                    break;
                case '^' :
                     res = op2 ^ op1;
                    break;
                case '%' :
                    res = op2 % op1;
                    break;
                default:
                    printf("ERROR: Unsupported operator.\n");
            }
            push(res + '0');
            i++;
        }
    }
    return (int)(stack[top] - '0');
}

int prefixResult(char prefix[]){
    int i = strlen(prefix)-1, res;
    while(i != -1){
        if(isOperand(prefix[i])){
            push(prefix[i--]);
        }else{
            int op1 = pop() - '0';
            int op2 = pop() - '0';
            switch(prefix[i]){
                case '+' :
                     res = op2 + op1;
                     break;
                case '-' :
                     res = op2 - op1;
                    break;
                case '*' :
                     res = op2 * op1;
                    break;
                case '/' :
                     res = op2 / op1;
                    break;
                case '^' :
                     res = op2 ^ op1;
                    break;
                case '%' :
                    res = op2 % op1;
                    break;
                default:
                    printf("ERROR: Unsupported operator.\n");
            }
            push(res + '0');
            i--;
        }
    }
    return (int)(stack[top] - '0');
}

int main(){
    char infix[] = "6+2";
    char postfix[MAX];
    //infixToPostfix(infix, postfix);
    infixToPrefix(infix, postfix);
    printf("The postfix expression is %d", prefixResult(postfix));
    return 0;
}
