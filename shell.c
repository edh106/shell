//shell.c

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

#define MAX_INPUT 100
#define MAX_ARGS 30
 
int main ()
{
    
    char  in[MAX_INPUT];
    char c;
    char* strp;
    char* args[MAX_ARGS];
    char buf[MAX_INPUT];
    int count = 0;
    pid_t pid;
    int temp;
    int status;
    int background = 0;
    while(1)
    {
      background = 0;
      getcwd(buf,MAX_INPUT);
      if(isatty(fileno(stdin)))
	printf("%s$ ",buf);
      if(fgets(in,MAX_INPUT,stdin) == NULL)
	continue;
      size_t end = strlen(in) -1;
      if ((end+1>0) && (in[end] == '\n'))
        in[end] = '\0';
      else
	{
	  printf("You have input more than %d characters\n",MAX_INPUT);
	  while((c = getchar()) != '\n' && c != EOF)
	    continue;
	}
      if(in[end - 1] == '&')
	{
	  background = 1;
	  in[end -1] = '\0';
	}
     if (strlen(in) == 0)
	{
	  continue;
	}
     else
      	{
	  strp = strtok(in," ");
	  count = 0;
	  while (strp != NULL)
	    {
	      args[count] = strp;

	      strp = strtok(NULL," ");
	      count++;
	    }
 
	  args[count] = NULL;
	  count = 0;

	   if (!strcmp(args[0],"cd"))
	    {
	      chdir(args[1]);
	    }
	   else if(!strcmp(args[0],"wait"))
	     {
	       while((pid = wait(&status)) != -1)
		 {
		   printf("%d process ended\n",pid);
		 }
	     }
	   else if(!strcmp(args[0],"exit"))
	     {
	       exit(EXIT_SUCCESS);
	     }
	   else if(!strcmp(args[0],"pwd"))
	     {
	       getcwd(buf,MAX_INPUT);
	       printf("%s\n",buf);
	     }
	   else
	     {
	      switch (pid = fork())
		{
		case -1:break;
		case 0:
		  execvp(args[0],args);
		  exit(0);
		  break;
		default:
		  if(background)
		    {
		      background = 0;
		      printf("new process %d spawned\n",pid);
		    }
		  else
		    waitpid(pid,0,0);
		 
		}
	    }
	}
    }
    return EXIT_SUCCESS;
 }

