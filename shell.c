//shell.c

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
 
int main ()
{
    
    char  in[30];
    char* strp;
    char* args[30];
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
      if (strlen(in) == 0)
	{
	  continue;
	}
      else
	{
	  strp = strtok(in," ");
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
	  else
	    {
	      switch (fork())
		{
		case -1:break;
		case 0:
		  execvp(args[0],args);
		  exit(0);
		  break;
		default:
		  wait();
		  break;
		}
	    }
	}
    }
    return 0;
  


}

