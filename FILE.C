#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct
{
char dname[10],fname[10][10];
int fcnt;
}dir;
struct
{
char dname1[10],fname1[10][10];
int fcnt1;
}dir1[10];
struct tree_element
{
char name[20];
int x, y, ftype, lx, rx, nc, level;
struct tree_element *link[5];
};
typedef struct tree_element node;
void main()
{
int i,ch,c,j,ch1,dcnt,k,c1;
char f[30],f1[30], d[30];
int gd=DETECT,gm;
node *root;
clrscr();
directory:
printf("Enter 1)Single Level 2) Two Level 3)Hierarchichal");
scanf("%d",&c);
switch(c)
{
case 1:
dir.fcnt = 0;
printf("\nEnter name of directory -- ");
scanf("%s", dir.dname);
while(ch!=5)
{
printf("\n\n 1. Create File\t2. Delete File\t3. Search File \n 4. Display Files\t5. Exit\nEnter your choice -- ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\n Enter the name of the file -- ");
scanf("%s",dir.fname[dir.fcnt]);
dir.fcnt++;
break;;
case 2: printf("\n Enter the name of the file -- ");
scanf("%s",f);
for(i=0;i<dir.fcnt;i++)
{
if(strcmp(f, dir.fname[i])==0)
{
printf("File %s is deleted ",f);
strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
break;
}
}
if(i==dir.fcnt)
printf("File %s not found",f);
else
dir.fcnt--;
break;;
case 3: printf("\n Enter the name of the file -- ");
scanf("%s",f);
for(i=0;i<dir.fcnt;i++)
{
if(strcmp(f, dir.fname[i])==0)
{
printf("File %s is found ", f);
break;
}
}
if(i==dir.fcnt)
printf("File %s not found",f);
break;;
case 4: if(dir.fcnt==0)
printf("\n Directory Empty");
else
{
printf("\n The Files are -- ");
for(i=0;i<dir.fcnt;i++)
printf("\t%s",dir.fname[i]);
}
break;;
default:printf("Exit");
	break;;
}
}
break;;
case 2:
dcnt=0;
while(ch1!=6)
{
printf("\n\n 1. Create Directory\t 2. Create File\t 3. Delete File");
printf("\n 4. Search File \t \t 5. Display \t 6. Exit \n Enter your choice -- ");
scanf("%d",&ch1);
switch(ch1)
{
case 1: printf("\n Enter name of directory -- ");
scanf("%s", dir1[dcnt].dname1);
dir1[dcnt].fcnt1=0;
dcnt++;
printf("Directory created");
break;
case 2: printf("\n Enter name of the directory -- ");
scanf("%s",d);
for(j=0;j<dcnt;j++)
if(strcmp(d,dir1[j].dname1)==0)
{
printf("Enter name of the file -- ");
scanf("%s",dir1[j].fname1[dir1[j].fcnt1]);
dir1[j].fcnt1++;
printf("File created");
break;
}
if(j==dcnt)
printf("Directory %s not found",d);
break;
case 3: printf("\nEnter name of the directory -- ");
scanf("%s",d);
for(j=0;j<dcnt;j++)
{
if(strcmp(d,dir1[j].dname1)==0)
{
printf("Enter name of the file -- ");
scanf("%s",f1);
for(k=0;k<dir1[j].fcnt1;k++)
{
if(strcmp(f1, dir1[j].fname1[k])==0)
{
printf("File %s is deleted ",f1);
dir1[j].fcnt1--;
strcpy(dir1[j].fname1[k],dir1[j].fname1[dir1[j].fcnt1]);
goto jmp;
}
}
printf("File %s not found",f1);
goto jmp;
}
}
printf("Directory %s not found",d);
jmp : break;
case 4: printf("\nEnter name of the directory -- ");
scanf("%s",d);
for(j=0;j<dcnt;j++)
{

if(strcmp(d,dir1[j].dname1)==0)
{
printf("Enter the name of the file -- ");
scanf("%s",f1);
for(k=0;k<dir1[j].fcnt1;k++)
{
if(strcmp(f1, dir1[j].fname1[k])==0)
{
printf("File %s is found ",f1);
goto jmp1;
}
}
printf("File %s not found",f);
goto jmp1;
}
}
printf("Directory %s not found",d);
jmp1: break;
case 5: if(dcnt==0)
printf("\nNo Directory's ");
else
{
printf("\nDirectory\tFiles");
for(j=0;j<dcnt;j++)
{
printf("\n%s\t\t",dir1[j].dname1);
for(k=0;k<dir1[j].fcnt1;k++)
printf("\t%s",dir1[j].fname1[k]);
}
}
break;
default:printf("Exit");
	break;;
}
}
break;;
case 3:
root=NULL;
clrscr();
create(&root,0,"root",0,639,320);
clrscr();
initgraph(&gd,&gm,"c:\tc\BGI");
display(root);
getch();
closegraph();
break;;
default:printf("Invalid choice");
	break;;
}
printf("Enter 1)to continue 2) to stop");
scanf("%d",&c1);
if(c1==1)
   goto directory;
else
   printf("Thanks");
getch();
}
create(node **root,int lev,char *dname,int lx,int rx,int x)
{
int i, gap;
if(*root==NULL)
{
(*root)=(node *)malloc(sizeof(node));
printf("Enter name of dir/file(under %s) : ",dname);
fflush(stdin);
gets((*root)->name);
printf("enter 1 for Dir/2 for file :");
scanf("%d",&(*root)->ftype);
(*root)->level=lev;
(*root)->y=50+lev*50;
(*root)->x=x;
(*root)->lx=lx;
(*root)->rx=rx;
for(i=0;i<5;i++)
(*root)->link[i]=NULL;
if((*root)->ftype==1)
{
printf("No of sub directories/files(for %s):",(*root)->name);
scanf("%d",&(*root)->nc);
if((*root)->nc==0)
gap=rx-lx;
else
gap=(rx-lx)/(*root)->nc;
for(i=0;i<(*root)->nc;i++)
create(&((*root)->link[i]),lev+1,(*root)->name,lx+gap*i,lx+gap*i+gap,
lx+gap*i+gap/2);
}
else
(*root)->nc=0;
}
}
display(node *root)
{
int i;
settextstyle(2,0,4);
settextjustify(1,1);
setfillstyle(1,BLUE);
setcolor(14);
if(root !=NULL)
{
for(i=0;i<root->nc;i++)
line(root->x,root->y,root->link[i]->x,root->link[i]->y);
if(root->ftype==1)
bar3d(root->x-20,root->y-10,root->x+20,root->y+10,0,0);
else
fillellipse(root->x,root->y,20,20);
outtextxy(root->x,root->y,root->name);
for(i=0;i<root->nc;i++)
display(root->link[i]); 
}
}