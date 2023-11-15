#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student_info//Studnet information stack
{ 
    struct Student_info* next;
    float CGPA;
    char First_Name[200];
    char Last_Name[200];
    char SRN[13]; 
}Stu;
typedef struct first
{
        struct Student_info* top;
}first;
typedef struct scholarships//Student scholarships
{
 
    struct scholarships* next;
    float CGPA;
    char First_Name[200];
    char Last_Name[200];
    char SRN[13]; 
}SC;
typedef struct scholarships_first
{
        struct SC* top;
}SC_first;
first init_Student_Info(first Stu_info)//Funtion for reseting the stack
{
    Stu *head=malloc(sizeof(Stu));
    printf("Enter the first name\n");
    scanf("%s",&head->First_Name);
    printf("Enter the last name\n");
    scanf("%s",&head->Last_Name);
    printf("Enter the CGPA\n");
    scanf("%f",&head->CGPA);
    printf("Please Enter the SRN\n");
    scanf("%s",&head->SRN);
     printf("----------------------------------\n");
    char cmp[10];
     for(int i = 0; i <= 9; i++)
   {
        cmp[i] = head->SRN[i];
   }
    char SRN_Parttern[10] ="PES2UG22CS";
    int count=1;
    while(count!=2)
    {
    if(head->CGPA>10 || head->CGPA<0)
    {
        printf("Please enter the correct CGPA\n");
        scanf("%f",&head->CGPA);
    }
    else if (strcmp(SRN_Parttern,head->SRN)<=0)
    {
        printf("Please Enter the correct SRN\n");
        scanf("%s",&head->SRN);
        char cmp[11];
        for(int i = 0; i <= 9; i++)
        {
        cmp[i] = head->SRN[i];
       }
    }
    
    else
        {
            count++;
        }
    }
      Stu_info.top=head;
      head->next=NULL;
    return Stu_info;
}
void display(first Stu_info)//Funtion for display
{
    if(Stu_info.top==NULL)
    {
        printf("the stack is empty\n");
    }
    else
{
    Stu*p =malloc(sizeof(Stu_info));
    p=Stu_info.top;
    //printf("%s\n",p->First_Name);
    while(p!=NULL)
    {
        printf("First name:%s\n",p->First_Name);
        printf("Last name:%s\n",p->Last_Name);
        printf("CGPA:%f\n",p->CGPA);
        printf("SRN:%s\n",p->SRN);
          printf("----------------------------------\n");
        p=p->next;
    }
}
}
Stu* create_node(first Stu_info)//Function for creating nodes
{
   Stu* new=malloc(sizeof(Stu));
    printf("Enter the first name\n");
    scanf("%s",&new->First_Name);
    printf("Enter the last name\n");
    scanf("%s",&new->Last_Name);
    printf("Enter the CGPA\n");
    scanf("%f",&new->CGPA);
    printf("Enter the SRN\n");
    scanf("%s",&new->SRN);
     printf("----------------------------------\n");
    char SRN_Parttern[10] ="PES2UG22CS";
    int count =1;
    int n;
    char cmp[11];
     for(int i = 0; i <= 9; i++)
   {
        cmp[i] = new->SRN[i];
   }
    while(count!=2)
    {
    if(new->CGPA>10 || new->CGPA<0)
    {
        printf("Please enter the correct CGPA\n");
        scanf("%f",&new->CGPA);
    }
    else
        {
            count++;
        }
    }
    Stu* q =Stu_info.top;
    while(q!=NULL)
    {
        if(strcmp(new->SRN,q->SRN)==0)
        {
            printf("The Student's SRN matches with other Student's SRN\n");
            printf("Enter the SRN\n");
            scanf("%s",&new->SRN);
            q=Stu_info.top;
        }
        else
        {
            q=q->next;
        }

    }
    new->next=Stu_info.top;
    Stu_info.top=new;
    return new;
}
first Enter_info(first First)//Funtion that use another funtio(create_node) to Enter it into the Stack
{
    Stu* new=malloc(sizeof(Stu));
    new = create_node(First);
    new->next=First.top;
    First.top=new;
    return First;
}
void check_info(first head)//Funtion to search student details by SRN
{
    if(head.top==NULL)
    {
        printf("The stack is empty\n");
        
    }
    else{
    Stu*p=head.top;
    char srn[13];
    printf("Enter the SRN\n");
    scanf("%s",&srn);
    int count = 0;
    while(p!=NULL)
    {
        if(strcmp(srn,p->SRN)==0)
        {
        printf("First name:%s\n",p->First_Name);
        printf("Last name:%s\n",p->Last_Name);
        printf("CGPA:%f\n",p->CGPA);
        printf("SRN: %s\n",p->SRN);
          printf("----------------------------------\n");
        count++;
        break;
        }
        p=p->next;
        
    }
    if(count<1)
    {
        printf("Student not found\n");
    }
    }
}
first pop(first head)//Function to pop the top element/head
{
    if(head.top==NULL)
    {
        printf("The stack is empty\n");
        return head;
    }
    Stu*p=head.top;
    Stu*q=p->next;
    head.top=q;
    free(p);
    return head; 
}
first scholarships(first head,SC_first list)//Function to get top 20% of the people
{ 
    if (head.top == NULL) 
    {
        printf("The stack is empty\n");
        return head;
    }
    Stu* p = head.top;
    int n = 0;
    while (p != NULL) 
    {
        p = p->next;
        ++n;
    }
    int top_20_percent = (int)(n * 0.2);
    if(top_20_percent==0)
    top_20_percent=top_20_percent+1;
    p = head.top;
    Stu* sorted = NULL;
    while (p != NULL) 
    {
        Stu* current = p;
        p = p->next;

        if 
        (sorted == NULL || current->CGPA >= sorted->CGPA) 
        {
            current->next = sorted;
            sorted = current;
        } else 
        {
            Stu* temp = sorted;
            while (temp->next != NULL && temp->next->CGPA < current->CGPA) 
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    p = sorted;
    Stu* h=sorted;
    /*while(h!=NULL)
    {
        printf("%s\n",h->First_Name);
        printf("%s\n",h->Last_Name);
        printf("%s\n",h->SRN);
        printf("%f\n",h->CGPA);
        h=h->next;
    }*/
    int count = 0;
    while (p != NULL && count < top_20_percent) 
    {
        SC* new_scholarship = malloc(sizeof(SC));
        strcpy(new_scholarship->First_Name, p->First_Name);
        strcpy(new_scholarship->Last_Name, p->Last_Name);
        new_scholarship->CGPA = p->CGPA;
        strcpy(new_scholarship->SRN, p->SRN);
        new_scholarship->next = list.top;
        list.top = new_scholarship;
        p = p->next;
        count++;
    }
    p = sorted;
    while (p != NULL) 
    {
        Stu* temp = p;
        p = p->next;
        free(temp);
    }
    printf("Student with the highest CGPA:\n", top_20_percent);
    p = head.top;
    count = 0;
    while (p != NULL && count < top_20_percent) 
    {
        printf("First name: %s\n", p->First_Name);
        printf("Last name: %s\n", p->Last_Name);
        printf("CGPA: %.2f\n", p->CGPA);
        printf("SRN: %s\n", p->SRN);
        printf("----------------------------------\n");
        p = p->next;
        count++;
    }
    return head;
}
int main()
{
    int ch,n;
    first Stu_info;
    SC_first SC_info;
    Stu_info.top=NULL;
    while(1)
    {
        printf("1:Insert\n2:Display\n3:Reset\n4:Pop\n5:Search\n6:Scholarships\n7:Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 3:
           Stu_info= init_Student_Info(Stu_info);
            break;
        case 2:
            display(Stu_info);
            break;
        case 1:
            printf("Please enter The number of Students\n");
            scanf("%d",&n);
            while(n)
            {
               Stu_info=Enter_info(Stu_info);
                --n;
            }
            break;
        case 4:
                Stu_info=pop(Stu_info);
            break;
        case 5:
            check_info(Stu_info);
            break;
        case 6:
            Stu_info=scholarships(Stu_info,SC_info);
            break;
        case 7:
           exit(0);
            break;
        }
    }
    return 0;
} 