#include<stdio.h>
#include<conio.h>
int h=0, mutex=1,full=0,empty=0,x=0;
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return(++s);
}
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer produces the item %d",x);
    mutex=signal(mutex);
}
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=signal(mutex);
}
void main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("enter max no of buffers");
    scanf("%d",&h);
    empty=h;
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(n!=3)
    {
	printf("\nEnter your choice:");
	scanf("%d",&n);
	switch(n)
	{
	    case 1:    if((mutex==1)&&(empty!=0))
			producer();
		    else
			printf("Buffer is full!!");
		    break;
	    case 2:    if((mutex==1)&&(full!=0))
			consumer();
		    else
			printf("Buffer is empty!!");
		    break;
	    case 3:
		    exit(0);
		    break;
	}
    }
 getch();
}



