//shell.c

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
 
int main ()
{
    
    char  in[30];
    char* strp;
    char* args[30];
<<<<<<< HEAD
    char buf[100];
    int count = 0;
    pid_t pid;
    int temp;
    int background = 0;
    while(1)
    {
      background = 0;
      getcwd(buf,100);
      if(isatty(fileno(stdin)))
	printf("%s$",buf);
      if(fgets(in,30,stdin) == NULL)
	return 0;
      size_t end = strlen(in) -1;
      if ((end+1>0) && (in[end] == '\n'))
        in[end] = '\0';
      if(in[end - 1] == '&')
	{
	  background = 1;
	  in[end -1] = '\0';
	}
=======
    char* buf;
    int count = 0;
    pid_t child,parent;
    int temp;
    while(1)
    {
      
      printf("shell>>");
      fgets(in,30,stdin);
      if ((strlen(in)>0) && (in[strlen (in) - 1] == '\n'))
        in[strlen (in) - 1] = '\0';
>>>>>>> 2a75191ee41d9bdfb6558128ca648e65ecaabf26
      if (strlen(in) == 0)
	{
	  continue;
	}
      else
	{
	  strp = strtok(in," ");
<<<<<<< HEAD
	  count = 0;
=======
>>>>>>> 2a75191ee41d9bdfb6558128ca648e65ecaabf26
	  while (strp != NULL)
	    {
	      args[count] = strp;

	      strp = strtok(NULL," ");
	      count++;
	    }
<<<<<<< HEAD
 
	  args[count] = NULL;
=======
	  args[count] = NULL;
	  count = 0;
>>>>>>> 2a75191ee41d9bdfb6558128ca648e65ecaabf26
	   if (!strcmp(args[0],"cd"))
	    {
	      chdir(args[1]);
	    }
	  else
	    {
<<<<<<< HEAD
	      switch (pid = fork())
=======
	      switch (fork())
>>>>>>> 2a75191ee41d9bdfb6558128ca648e65ecaabf26
		{
		case -1:break;
		case 0:
		  execvp(args[0],args);
		  exit(0);
		  break;
		default:
<<<<<<< HEAD
		  if(background)
		    {
		      printf("new process %d spawned\n",pid);
		    }
		  else
		    wait();
=======
		  wait();
>>>>>>> 2a75191ee41d9bdfb6558128ca648e65ecaabf26
		  break;
		}
	    }
	}
    }
    return 0;
  


}

