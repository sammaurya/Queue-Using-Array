#include <stdio.h>
#include <stdlib.h>

#define MAX 5


void Create(int [],int *,int *);
void Insert(int [],int *,int *);
void Delete(int [],int *,int *);
void Print(int [],int *,int *);


int main()
{
    int arr[MAX],FRONT,REAR;
    FRONT=REAR=-1;
    int choice;
    START:
    printf("\n\t\t    Queue Using Array\n");
    printf("\t\t--------------------------");
    printf("\n\n1.Insert\n2.Delete\n3.Print\n4.Clear Screen\n5.Exit");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                Insert(arr,&FRONT,&REAR);
                break;
        case 2:
                Delete(arr,&FRONT,&REAR);
                break;
        case 3:
                Print(arr,&FRONT,&REAR);
                break;
        case 4:
                system("cls");
                goto START;
                break;
        case 5: printf("\nExiting");
                break;
        default: printf("\nError! Wrong Choice");
        }
    }while(choice!=5);
    return 0;
}

void Insert(int arr[],int *FRONT,int *REAR)
{
    int data;
    if(*REAR==MAX-1)
    {
        printf("Overflow");
    }
    else if(*FRONT==-1 && *REAR==-1)
    {
        printf("Enter Element : ");
        scanf("%d",&data);
        *FRONT += 1;
        *REAR += 1;
        arr[*FRONT]=data;
    }
    else
    {
        *REAR = *REAR+1;
        printf("Enter Element : ");
        scanf("%d",&data);
        arr[*REAR]=data;
    }
}
void Delete(int arr[],int *FRONT,int *REAR)
{
    if(*FRONT==-1)
    {
        printf("Underflow");
    }
    else
    {
        if(*FRONT==*REAR)
        {
            printf("Element Deleted : %d",arr[*FRONT]);
            arr[*FRONT]=NULL;
            *FRONT = -1;
            *REAR  = -1;
        }
        else
        {
            printf("Element Deleted : %d",arr[*FRONT]);
            arr[*FRONT]=NULL;
            *FRONT = *FRONT+1;
        }
    }
}
void Print(int arr[],int *FRONT,int *REAR)
{
    if(*FRONT==-1)
    {
        printf("Underflow");
    }
    else
    {
        int f = *FRONT;
        while(f<=*REAR)
        {
            printf(" %d",arr[f]);
            f++;
        }
    }
}
