include<stdio.h>

#include<string.h>

void permutation(char *,int,int);

int main()

{

   //int j,i;

   char s[30];

   //int n=strlen(s);

   printf("Enter the string :");

   gets(s);

   permutation(s,0,strlen(s));

  return 0;

}

void permutation(char *s,const int start,int end)

{

  int i,j;

  char temp;

   for(i=start;i<end-1;i++){

      for(j=i+1;j<end;j++){

        // printf("%c",s[j]);

        temp=s[i];

        s[i]=s[j];

        s[j]=temp;

        permutation(s,i+1,end);       

        temp=s[i];

        s[i]=s[j];

        s[j]=temp;

     }

    }

    printf("%s\n",s); 

 }

   
