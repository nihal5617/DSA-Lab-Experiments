/*Write a program to perform Infix to Postfix conversion and its evaluation.*/
#include<stdio.h>
#include<ctype.h>
#include<math.h>

char stack[100];
int top = -1;

int stack1[100];
int top1 = -1;

void push(char x)
{
    stack[++top] = x;
}

void push1(int x)
{
    stack1[++top1] = x;
}
char topmost(){
    if(top == -1)
        return -1;
    else
        return stack[top];
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int pop1()
{
    if(top1 == -1)
        return -1;
    else
        return stack1[top1--];
}

int priority(char x)
{

    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}

void intopost(char temp[100],char temp2[100]){
    int i=0;
    int j=0;
    char x;
    while(temp[i]!='\0'){
        if(isalnum(temp[i])){
            printf("%c",temp[i]);
            temp2[j++]=temp[i];
        }
        else if(temp[i]=='(')
            push(temp[i]);
        else if(temp[i]==')'){
            while((x=pop())!='('){
                printf("%c ", x);
                temp2[j++]=x;
            }
        }
        else{
             while(priority(stack[top]) >= priority(temp[i])){
                if((priority(stack[top]) == priority(temp[i])) && (priority(stack[top])==3)){
                    break;
                }else{
                    temp2[j++]=topmost();
                    printf("%c ",pop());
                }
             }
                
            push(temp[i]);
        }
        i++;
    }
    while(top != -1)
    {
        temp2[j++]=topmost();
        printf("%c ",pop());
    }
}

int operation(int i1,int i2, char x)
{
    int res;
    if(x=='+'){
        res=i1+i2;
    }if(x=='-'){
        res=i1-i2;   
    }if(x=='*'){
        res=i1*i2;
    }if(x=='/'){
        res=i1/i2;
    }if(x=='^'){
        res=pow(i1,i2);
    }
    return res;
}
void eval(char temp[100]){
    int i=0;
    int result,opnd1,opnd2;
    while(temp[i]!='\0'){
        if(isdigit(temp[i]))
            push1(temp[i]-48);
        else{
            opnd2=pop1();
            opnd1=pop1();
            result = operation(opnd1,opnd2,temp[i]);
            push1(result);
        }
        i++;
    }
    while(top1 != -1)
    {
        printf("%d ",pop1());
    }
}

int main()
{
    char exp[100],temp[100];
    int i=0;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    printf("Postfix Expression is : ");
    intopost(exp,temp);
    printf("\nFor Evaluation \n");
    // temp[i]=exp[i];
    while(temp[i]!='\0'){
        if(isalnum(temp[i])){
            int t;
            printf("Enter value: ");
            scanf("%d",&t);
            temp[i]=t+'0';
        }
        // printf("%c",temp[i]);
        i++;
    }
    printf("\nExpression with value is : ");
    i=0;
    while(temp[i]!='\0'){
        printf("%c",temp[i]);
        i++;
    }
    printf("\nEvaluation of Expression is : ");
    eval(temp);
    return 0;
}
