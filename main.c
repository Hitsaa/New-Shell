#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <macros.h>

int main()
{   
    int status;
    char ch[2]={"\n"};
    getcwd(current_directory, sizeof(current_directory));
    signal(SIGINT, sigintHandler);
    while (1)
    {
      clear_variables();
      prompt();
      fgets(input_buffer, 1024, stdin);
      if(strcmp(input_buffer, ch)==0)
            {
              continue;
            }
      if(input_buffer[0]!='!')
            {
                fileprocess();
                filewrite(); 
            }         
      len = strlen(input_buffer);
      input_buffer[len-1]='\0';
      strcpy(his_var, input_buffer);
      if(strcmp(input_buffer, "exit") == 0) 
            {
              flag = 1;
              break;
            }
      if(input_buffer[0]=='!')  
              {
                fileprocess();
                bang_flag=1;
                bang_execute();
              }
      with_pipe_execute();
      waitpid(pid,&status,0);
         
    }  
    if(flag==1)
      {
      printf("Bye...\n");
      exit(0);       
      return 0;
      }
return 0;
}
