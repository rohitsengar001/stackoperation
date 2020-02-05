#include<stdio.h>
#include<stdlib.h>
//=====================================MACROS DEFINE=============================================
#define MAXSTACK 10
#define NIL -1

//========================================structure ofstack======================================
typedef struct stacktype //typedef provides the alias name to the structure
{
 int a[MAXSTACK];//MAXSTACK in define in defination
 int top;//showing top index no of stack element
}stack;//alias name of structure
//=========================================structure end=========================================


void main()
{
 //=====================================Declaration Section===================================================================
 int item,choice,x,*p;
 void push(stack *,int);//push methode helps to insert element into the stack and argument list are stack and item which is want to insert into the stack

 int pop(stack *);//pop helps to Retrive the all stack element by fetching top of element when it will be called by programmer.
 int peep(stack *);//
 int isoverflow(stack *);//argumentlist are stack and item
 int isunderflow(stack *);//argumentlist are stack and item
//===================================Declaration Sectionends==================================================================
 
 stack s;
 s.top=NIL;//intially declare top of stack=0
 while(1)
 {
  printf("\npress \n1 for push \n 2 for pop \n3 for peep \n4 for exit");//menu for user get select which operation they want to execute
  printf("\nenter the choice");//ask choice from the user
  scanf("%d",&choice);//get choice by the user
  switch(choice)
  {
   case 1: x=isoverflow(&s);//function isoverflow is calling and gives return '1' in case of true and '0' in case of false
           if(x==1)//check over flow of stack
           {
            printf("stack is overflow");//stack is overflow then it will be executed
           }
           else
           {
            printf("enter the pushing item");//stack is not overflow it will be executed
            scanf("%d",&item);
            push(&s,item);//calling push function
           }
          break;
  case 2: x=isunderflow(&s);//check underflow of stack
           if(x==1)
           {
            printf("stack is underflow");
           }
           else
           {
            item=pop(&s);//calling pop function and stored pop value into 'item' variable.
            printf("\npop up item is :%d",item);
            
           }
          break;
  case 3:x=isunderflow(&s);//check underflow of the stack.
         if(x==1)
         {
           printf("stack is inderflow");
         }
         else
          {
           printf("stack is underflow");
           item=peep(&s);//peep function calling and giving top of the stack element only.
           printf("\npeep item is :%d",item);
          }
         break;
 case 4: 
       printf("enter the postfix expression :");
       scanf("%s",Postfix);
       for(i=0;Postfix[i]!='\0';i++)
       {
         if(Postfix[i]>='0' && Postfix[i]<='9')
         {
           push(&s,Postfix[i]-48);
         }
         else
         {
           a=pop(&s);
           b=pop(&s);
           if(Postfix[i]=='+')
           {
            r=a+b;
            push(&s,r);
           }
           else if(Postfix[i]=='*')
           {
              r=a*b;
              push(&s,r);
           }
           
         }
        printf("result is %d",r);
       }
       break;
 case 5:exit(0);
  default:printf("please enter the correct choice");
  }
 }
}
//===================================sub-section=================================================
void push(stack *p,int item)//argument list : stack *p(passing structure object ) and push item
{
 p->top=p->top+1;//existing top of stack's index increase by 1 
 p->a[p->top]=item;//inserting item at top of stack
}
int pop(stack *p)
{
 int item;
 item=p->a[p->top];//retrival stack's top element into the "item" referencing variable
 p->top=p->top-1;//decrease the stack top index by 1
 return item;
}
int isoverflow(stack *p)
{
 if(p->top==MAXSTACK)
   return 1;
 else
   return 0;
}
int isunderflow(stack *p)
{
  if(p->top==NIL)
    return 1;
  else
    return 0;
}
int peep(stack *p)
{
 int item;
 item=p->a[p->top];
 return item;
}
//===================================sub-section ends========================================================
