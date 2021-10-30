#include <stdio.h>
#include <stdlib.h>
#define total_frame 20

// CODE SUBMITTED BY ASHISH LALWANI
// ROLL NO:- 18UCS194

int c1 = 0;
int c2 = 0;

void local_strategy(int page_per_process,int process_no,int page_no,int memory[][10],int timer[][10],int free_frame_list[][10],int total_process)
{
  int i,j;
  int check = 0;
  int check2 = 0;
  printf("Free frame list\n");
   for(i=0;i<total_process;i++)
    {
        for(j=0;j<page_per_process;j++)
        {
            printf("%d ",free_frame_list[i][j]);
        }
        printf("\n");
    }

  for(i=0;i<page_per_process;i++)
  {

     if(memory[process_no][i]==page_no)
      {
          printf("Hi1\n");
          check = 1;
          timer[process_no][i] = 0;
          for(j=0;j<page_per_process;j++)
          {
              if(j!=i)
              {
                  timer[process_no][j]++;
              }
          }
          break;
      }
  }

      if(check==0)
      {
          printf("Hi2\n");
          for(j=0;j<page_per_process;j++)
          {
              if(free_frame_list[process_no][j]==0)
              {
                  check2 = 1;
                  free_frame_list[process_no][j] = 1;
                  timer[process_no][j] = 0;
                  memory[process_no][j] = page_no;
                  printf("memory[][] %d\n",memory[process_no][j]);
                  break;
              }
          }
      }
      if(check2==0)   // apply LRU
      {
          printf("Hi3\n");
          int max = -1;
          int index;
          for(j=0;j<page_per_process;j++)
          {
              if(timer[process_no][j] > max)
              {
                  index = j;
                  max = timer[process_no][j];
              }
          }
          printf("Victim page for corressponding process is %d\n",memory[process_no][index]);
          timer[process_no][index] = 0;
          memory[process_no][index] = page_no;
          c1++;
      }
  }


int main()
{
    int i,j,a,b;
    //int total_process = rand()%5 + 1;
    int total_process = 5;
    int page_requiremnet[total_process];
    printf("Page requirement of each process\n");
    for(i=0;i<total_process;i++)
    {
        page_requiremnet[i] = rand()%10 + 1;
        printf("%d page number requirement is %d\n",i,page_requiremnet[i]);
    }
    int page_per_process = total_frame/total_process;
    printf("Each process will get %d th frames\n",page_per_process);
    int memory[total_process][page_per_process];
    int memoryA[total_process][page_per_process];
    int free_frame_list[total_process][page_per_process];
    int free_frame_listA[total_process][page_per_process];
    int timer[total_process][page_per_process];
    int timerA[total_process][page_per_process];
    int total_references,process_no,page_no;
     int check,check2;
     printf("Here I am using LRU Counting Implementation\n");
     printf("Row for each process and column for frames allocated to that process\n");
    for(i=0;i<total_process;i++)
    {
        for(j=0;j<page_per_process;j++)      // initialize memory by -1
        {
            memory[i][j] = -1;
            memoryA[i][j] = -1;
        }
    }

     for(i=0;i<total_process;i++)
    {
        for(j=0;j<page_per_process;j++)
        {
            free_frame_list[i][j] = -1;
            free_frame_listA[i][j] = -1;
        }
    }
    printf("Free frame list\n");
   for(i=0;i<total_process;i++)
    {
        for(j=0;j<page_per_process;j++)
        {
            printf("%d ",free_frame_list[i][j]);
        }
        printf("\n");
    }
      for(i=0;i<total_process;i++)
    {
        for(j=0;j<page_per_process;j++)
        {
            timer[i][j] = 0;
            timerA[i][j] = 0;
        }
    }
    printf("How many reference do you want?\n");
    scanf("%d",&total_references);
    while(total_references--)
    {
        printf("Please enter process number and page number for reference\n");
        scanf("%d %d",&process_no,&page_no);
       // local_strategy(page_per_process,process_no,page_no,memory,timer,free_frame_list,total_process);

       ///////////////////////////////////////////
    /// LOCAL ALLOCATION/////


     check = 0;
    check2 = 0;
    printf("Free frame list in case of GLOBAL ALLOCATION\n");
   for(i=0;i<total_process;i++)
    {
        for(j=0;j<page_per_process;j++)
        {
            printf("%d ",free_frame_list[i][j]);
        }
        printf("\n");
    }
    printf("Memory list in case of LOCAL ALLOCATION\n");
   for(i=0;i<total_process;i++)
    {
        for(j=0;j<page_per_process;j++)
        {
            printf("%d ",memory[i][j]);
        }
        printf("\n");
    }

  for(i=0;i<page_per_process;i++)
  {

     if(memory[process_no][i]==page_no)
      {
         // printf("Hi1\n");
          check = 1;
          timer[process_no][i] = 0;
          for(j=0;j<page_per_process;j++)
          {
              if(j!=i)
              {
                  timer[process_no][j]++;
              }
          }
          break;
      }
  }

      if(check==0)
      {
         // printf("Hi2\n");
          for(j=0;j<page_per_process;j++)
          {
              if(free_frame_list[process_no][j]==-1)
              {
                  check2 = 1;
                  free_frame_list[process_no][j] = 1;
                  timer[process_no][j] = 0;
                    for(i=0;i<page_per_process;i++)
                    {
                          if(j!=i)
                      {
                      timer[process_no][i]++;
                      }
                    }
                  memory[process_no][j] = page_no;
                  printf("memory[][] %d\n",memory[process_no][j]);
                  break;
              }
          }
      }
      if(check2==0 && check!=1)   // apply LRU
      {
        //  printf("Hi3\n");
          int max = -1;
          int index;
          for(j=0;j<page_per_process;j++)
          {
              if(timer[process_no][j] > max)
              {
                  index = j;
                  max = timer[process_no][j];
              }
          }
          printf("Victim page for corressponding process is %d\n",memory[process_no][index]);
          timer[process_no][index] = 0;

            for(i=0;i<page_per_process;i++)
          {
              if(i!= index)
              {
                  timer[process_no][i]++;               // Increase counter for rest of elements
              }
          }
          memory[process_no][index] = page_no;
          c1++;
      }





       ////////////////////////////////////////////
         printf("C1 after each iteration %d\n",c1);

         /////////////////////////////////////////    Apply LRU Global

         ////// GLOBAL ALLOCATION /////

int   checkA = 0;
    int check2A = 0;
    int index_x,index_y;
  printf("Free frame list in case GLOBAL ALLOCATION\n");
   for(i=0;i<total_process;i++)
    {
        for(j=0;j<page_per_process;j++)
        {
            printf("%d ",free_frame_listA[i][j]);
        }
        printf("\n");
    }
    printf("Memory list in case GLOBAL ALLOCATION\n");
   for(i=0;i<total_process;i++)
    {
        for(j=0;j<page_per_process;j++)
        {
            printf("%d ",memoryA[i][j]);
        }
        printf("\n");
    }
    int flag = 0;
 for(a=0;a<total_process;a++){
  for(i=a;i<page_per_process;i++)
  {

     if(memoryA[a][i]==page_no)
      {
        //  printf("Hi1\n");
          check = 1;
          timerA[a][i] = 0;
          for(b=0;b<total_process;b++){
            for(j=b;j<page_per_process;j++)
            {
              if(j!=i && b!=a)
              {
                  timerA[b][j]++;
              }
            }
         }
         flag = 1;
          break;
      }
  }
  if(flag==1)
    break;
 }
 flag = 0;

      if(checkA==0)
      {
         // printf("Hi2\n");
          for(a=0;a<total_process;a++){
          for(j=a;j<page_per_process;j++)
          {
              if(free_frame_listA[a][j]==-1)
              {
                  check2A = 1;
                  free_frame_listA[a][j] = 1;
                  timerA[a][j] = 0;
                  for(b=0;b<total_process;b++){
                    for(i=b;i<page_per_process;i++)
                    {
                        if(i!=j && b!=a)
                  {
                  timerA[b][i]++;
                  }
                   }
                 }
                  memoryA[a][j] = page_no;
                //  printf("memory[][] %d\n",memoryA[a][j]);
                  flag = 1;
                  break;

              }
          }
          if(flag==1)
            break;
        }
      }
      if(check2A==0 && checkA!=1)   // apply LRU
      {
         // printf("Hi3\n");
          int max = -1;
          int index;
          for(a=0;a<total_process;a++){
          for(j=0;j<page_per_process;j++)
          {
              if(timerA[a][j] > max)
              {
                  index_x = a;
                  index_y = j;
                  max = timerA[a][j];
              }
          }
          }
          printf("Victim page for corressponding process is %d\n",memoryA[index_x][index_y]);
          timerA[index_x][index_y] = 0;
           for(b=0;b<total_process;b++){
                for(i=b;i<page_per_process;i++)
                    {
                        if(i!=index_y && b!=index_x)
                       {
                          timerA[b][i]++;
                       }
                    }
                 }
          memoryA[index_x][index_y] = page_no;
          c2++;
      }







         //////////////////////////////////////////////


    }


   printf("Efficiency in terms of total number of LRU Replacement in local or global allocations\n");
   printf("Ratio of global(LRU) vs local(LRU) %d/%d",c2,c1);

    return 0;
}
