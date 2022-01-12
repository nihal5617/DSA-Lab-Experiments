/*Write a program to perform polynomials operations (addition, subtraction, multiplication) 
using Linked List. Each polynomial should be represented as a list with linked list implementation. 
The first node in the list represents the first Each polynomial should be represented  as  a  
list  with  linked  list implementation. The first node in the list represents the first term 
in the polynomial; the 2nd node represents the 2nd term and so on.  
The structure of a node is as follows.*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    float coeff;
    int expo;
    struct node* link;
};

struct node* insert(struct node* head, float co,int ex){
    
    struct node* temp;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = co;
    newnode->expo = ex;
    newnode->link = NULL;
    
    if(head == NULL || ex > head->expo){
        newnode->link = head;
        head = newnode;
    }else{
        temp = head;
    while(temp->link != NULL && temp->link->expo >= ex){//Sorting the powers in descending order
        temp = temp->link;
    }
        newnode->link = temp->link;
        temp->link = newnode;
    }
    return head;
}
struct node* create (struct node* head){
    int n,i;
    float coeff;
    int expo;
    
    printf("Enter the Number of Terms of the Polynomial: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("Enter the coefficient of Term %d: ",i+1);
        scanf("%f",&coeff);
        printf("Enter the Power of Term %d: ",i+1);
        scanf("%d",&expo);
        head = insert(head, coeff, expo);
    }
    return head;
}
void print(struct node* head){
    if(head==NULL)
        printf("No Polynomial");
    else{
        struct node* temp = head;
        while(temp!=NULL){
            if(temp->expo == 1){
                printf("(%0.1fx)",temp->coeff);
            }
            else if(temp->expo == 0){
                printf("(%0.1f)",temp->coeff);
            }
            else{
                printf("(%0.1fx^%d)", temp->coeff, temp->expo);
            }
            temp = temp->link;
            if(temp!=NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }
    }
}

//The Addition Function
void add(struct node* head1,struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo == ptr2->expo){
            head3 = insert(head3, ptr1->coeff+ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo){
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;//the ptr1 will now point to the next node
        }
        else if(ptr1->expo < ptr2->expo){
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;//the ptr2 will now point to the next node
        }
    }
    while(ptr1 != NULL){
        head3 = insert(head3,ptr1->coeff,ptr1->expo);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL){
        head3 = insert(head3,ptr2->coeff,ptr2->expo);
        ptr2 = ptr2->link;
    }
    printf("Added polynomial is = ");
    print(head3);
}

//The subtract function; Same as the add function.
void subtract(struct node* head1,struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo == ptr2->expo){
            head3 = insert(head3, ptr1->coeff-ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo){
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if(ptr1->expo < ptr2->expo){
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL){
        head3 = insert(head3,ptr1->coeff,ptr1->expo);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL){
        head3 = insert(head3,ptr2->coeff,ptr2->expo);
        ptr2 = ptr2->link;
    }
    printf("Subtracted polynomial is = ");
    print(head3);
}
//The multiply function
void multiply(struct node* head1,struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    if(head1 == NULL || head2 == NULL){
    printf("Zero Polynomial");
    return;
    }
    while(ptr1!=NULL){
        while(ptr2!=NULL)
        {
            head3 = insert(head3, ptr1->coeff*ptr2->coeff, ptr1->expo+ptr2->expo);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }
    /*printf("The Multiplied Polynomial Before Simplication = ");
    print(head3);*/
    
    struct node* ptr3 = head3;
    struct node* temp = NULL;//creating a temp
    while(ptr3->link != NULL){
        if(ptr3->expo == ptr3->link->expo){
            ptr3->coeff = ptr3->coeff + ptr3->link->coeff;//it will simply add the coefficients
            temp = ptr3->link;//using a temp function to remove the node if expo is same
            ptr3->link = ptr3->link->link;//The link of therm will now point to the link of next term
            free(temp);//deleting the temp
        }
        else
            ptr3 = ptr3->link;
    }
    printf("Multiplied Polynomial After Simplification = \n");
    print(head3);
}


int main(){
    int opt;
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    printf("Enter The Polynomial 1\n");
    head1 = create(head1);
    printf("Polynomial 1 = ");
    print(head1);
    printf("Enter The Polynomial 2\n");
    head2 = create(head2);
    printf("Polynomial 2 = ");
    print(head2);
    //performing various operations on the polynomials and printing their output
    while(1){
        printf("\nPerform Operations\n1.Addition\n2.Subtraction\n3.Multiplication\n4.EXIT\n\nEnter option\n");
        scanf("%d",&opt);
        switch(opt){
            case 1: add(head1,head2);
                    break;
            case 2: subtract(head1,head2);
                    break;
            case 3: multiply(head1,head2);
                    break;
            case 4: exit(1);
            default : printf("Enter Correct number\n");
                    break;
        }
    }
    return 0;
}
