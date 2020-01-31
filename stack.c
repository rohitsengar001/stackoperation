#include<stdio.h>
#include<stdlib.h>
#define MAXSTACK 10
#define NIL -1
//----------structure of stack-------------------
typedef struct stacktype
{
 int a[MAXSTACK];
 int top;//showing top index no of stack element
}stack;
//------------structure end----------------------

void main()
{
 int item,choice,x,*p;
 void push(stack *,int);
 int pop(stack *);
 int peep(stack *);
 int isoverflow(stack *);
 int isunderflow(stack *);

 stack s;
 s.top=NIL;//intially declare top of stack=0
 while(1)
 {
  printf("\npress 1 for push \n 2 for pop \n3 for peep \n4 for exit");
  printf("\nenter the choice");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1: x=isoverflow(&s);
           if(x==1)
           {
            printf("stack is overflow");
           }
           else
           {
            printf("enter the pushing item");
            scanf("%d",&item);
            push(&s,item);
           }
          break;
  case 2: x=isunderflow(&s);
           if(x==1)
           {
            printf("stack is underflow");
           }
           else
           {
            item=pop(&s);
            printf("\npop up item is :%d",item);
            
           }
          break;
  case 3:x=isunderflow(&s);
         if(x==1)
         {
           printf("stack is underflow");
           item=peep(&s);
           printf("\npeep item is :%d",item);
         }
 case 4:exit(0);
  default:printf("please enter the correct choice");
 
  }
 }

}
//sub-section
void push(stack *p,int item)
{
 p->top=p->top+1;
 p->a[p->top]=item;
}
int pop(stack *p)
{
 int item;
 item=p->a[p->top];
 p->top=p->top-1;
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
