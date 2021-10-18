#include<stdio.h>
typedef struct Priority_Queue
{
       int num;
       int p;
}P_que;

int main()
{
       int opt;
       printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n);
       while(1)
       {
              printf("Enter option:");
              scanf("%d",&opt);
              switch(opt)
              {
                     case 1:
                            Enqueue(
       
