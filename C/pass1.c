#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arr[10];
int address[10];
char symbol[10][100];
int val;
void main()
{
for(int i=0;i<10;i++) 
	arr[i]=0;
char str;
printf("PASS 1 ASSEMBLER\n");
FILE *f1,*f2,*f3,*f4;
int lc,sa,l,op1,o,len;
char m1[20],la[20],op[20],otp[20];

f1=fopen("input.txt","r");
f3=fopen("symtab.txt","w");
fscanf(f1,"%s %s %d",la,m1,&op1);
printf("OUTPUT\n");
if(strcmp(m1,"START")==0)
{
 sa=op1;
 lc=sa;
 printf("\t%s\t%s\t%d",la,m1,op1);
 }
 else
 lc=0;
fscanf(f1,"%s %s",la,m1);
while(!feof(f1))
{
 fscanf(f1,"%s",op);
 printf("\n%d\t%s\t%s\t%s",lc,la,m1,op);
 if(strcmp(la,"-")!=0)
 {
 int temp=0;
 val=lc%10;
 while(temp<10) {
 	temp++;
 	if(arr[val]==0) {
 		arr[val]=1;
 		fprintf(f3,"%d\t%s\n",lc,la);
 		strcpy(symbol[val],la);
 		address[val]=lc;
 		break;
 		}
 	else
 		val=(val+1)%10;
 	}
 if(temp==10)
 	printf("TABLE FULL\n");
 }
 f2=fopen("optab.txt","r");
 fscanf(f2,"%s %d",otp,&o);
 while(!feof(f2))
 {
  if(strcmp(m1,otp)==0)
  {
    lc=lc+3;
    break;
  }
  fscanf(f2,"%s %d",otp,&o);
  }
  fclose(f2);
  if(strcmp(m1,"WORD")==0)
 
    {
   lc=lc+3;
   }
   else if(strcmp(m1,"RESW")==0)
   {
    op1=atoi(op);
    lc=lc+(3*op1);
    }
    else if(strcmp(m1,"BYTE")==0)
    {
    if(op[0]=='X')
      lc=lc+1;
      else
      {
      len=strlen(op)-2;
      lc=lc+len;}
    }
    else if(strcmp(m1,"RESB")==0)
    {
     op1=atoi(op);
     lc=lc+op1;
     }
    fscanf(f1,"%s%s",la,m1);
    }
    if(strcmp(m1,"END")==0)
    {
    fclose(f3);
    printf("\n");
    printf("\n\n\tsymtab in hashing table\n\n");
 printf("\n\tIndex\tAddress\tSymbol\n\n");
 for(int i=0;i<10;i++) {
    	if(arr[i]==1) {		printf("\t%d\t%d\t%s\n",i,address[i],symbol[i]);
    		}
    	}
    printf("\n\tLength:%d\n",lc-sa-3);
    }
    fclose(f1);
    }
