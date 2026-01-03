#include <stdio.h>
#include <string.h>
#define MAX 50
char stack[MAX];
int top=-1;
void push(char ch){
    if (top<MAX -1){
        top++;
        stack[top]=ch;
    }
}
char pop(){
    if (top !=-1){
        return stack[top--];
    }
    return '\0';
}
int ismatch(char open, char close){
 if (open =='('&& close == ')')
    return 1;
 if (open =='{'&& close == '}')
    return 1;
 if (open =='['&& close == ']')
    return 1;
return 0;
}
int main(){
    char exp[MAX];
    int i,flag=1;
    printf("Enter expression: ");
    fgets(exp, MAX,stdin);
    for(i=0; exp[i] !='\0'; i++){
        if (exp[i]== '(' || exp[i]== '{' || exp[i]== '['){
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i]== '}' || exp[i]== ']'){
            if (top == -1){
                flag =0;
                break;
            } else {
                char temp = pop();
                if (!ismatch(temp,exp[i])){
                    flag = 0;
                    break;
                }
            }
        }
    }
    if (top !=-1)
    flag = 0;
if (flag == 1)
printf("Expression has balanced parantheses");
else
printf("Expression has not balanced parantheses");

return 0;
}