#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
pthread_t th1,th2,th3,temp_t;
char b[10],c[255],k[255];
int found=0;
int i=0;
void* fun(char a[100])
{
  DIR *d,*f;
Struct dirent *de,*fe;
printf(“went into directory %s\n”,a);// here whole path is printed
strncpy(k,a,254);
k[255]=’\0’;
d=opendir(a);
if(d ==NULL)
{ perror(“opendir”);return;}
for(de=readdir(d);de!=NULL;de=readdir(d))
{
    If(strcmp(de->d_name,b)==0)
   {    found=1;
        printf(“%s\n”,de->d_name);
//if the file is found exiting from the thread
    Pthread_exit(th1);
    Pthread_exit(th2);
    Pthread_exit(th3);

         break;
  }
else if((de->d_type==DT_DIR) &&((strcmp(de->d_name,”..”)!=0) && (strcmp(de->d_name,”.”)!=0)))
{
            //clearing the memory to send new datapath     
            memset(c,0,sizeof(c));

                 strcat(k,”/”);
                 i++;
                 strcat(k,de->d_name);  //every time new directory opened and copied to c
                 i++; 
                 strncpy(c,k,254);
              c[255]=’\0’;
//New data path is sent into function after clearing “c[]”  
   fun(c);
//removing directory path that has been searched
t1=k[i];
 i--;
t2=k[i];
//printf(“t1%c t2 %c”,t1,t2);  
}
}
Closedir(d);
}

Int main()
{
    Char *b;
  Printf(“Enter the string name”);
  gets(b);
pthread_t th1,th2,th3;
//we have declared three directories to be fetched only a,m,p
pthread_create(&th1,NULL,&fun,”a”);
pthread_create(&th2,NULL,&fun,”m”);
pthread_create(&th3,NULL,&fun,”p”);
pthread_join(th1,&status);
pthread_join(th2,&status);
pthread_join(th3,&status);
}
/**
Input :
A: B C D I
I:F G H K
D:c d f
F:k l m
C:z y
OutPut:
Enter the file name to be searched:m
Went into directory:A
Went into directory:D
Went  into directory:I
Went into directory:F
File Found path:A/I/F/m
**/
