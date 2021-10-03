#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include <windows.h>

int main()
{
STARTUPINFO si;
PROCESS_INFORMATION pi;
ZeroMemory(&si, sizeof(si));
si.cb = sizeof(si);
ZeroMemory(&pi, sizeof(pi));
BOOL cCreateProcess = NULL;
struct dirent *de;
DIR *dr = opendir(".");
char file_ner[100];
char command[100];
char text[100];
char hner[100];
char shner[100];
char pner[100];
printf(">>");
scanf("%s",&command);
while(command!=0)
    {
        if(strcmp(command,"dir")==0)
        {
	        DIR *directory;
		    struct dirent *entry;
		    int n = 0;
		
		    directory = opendir(".");
		    if(directory == NULL){
		        perror("Unable to read directory");
		        return(1);
		    }
		
		    while( (entry=readdir(directory)) ){
		        n++;
		        printf("File %3d: %s\n", n, entry->d_name);
		    }
		
		    closedir(directory);
        }
        else
            if(strcmp(command,"create")==0)
        {
          scanf("%s",&file_ner);
          FILE* file_ptr=fopen(file_ner, "w");
          fclose(file_ptr);
        }
        else
            if(strcmp(command,"input")==0)
        {
            scanf("%s",&file_ner);
            FILE* fptr=fopen(file_ner, "w");
            gets(text);
            fprintf(fptr,"%s",text);
            fclose(fptr);
        }
        else
            if(strcmp(command,"createProcess")==0)
			{
				scanf("%s",&file_ner);
				if (!CreateProcess(file_ner, NULL, NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))
					printf("\nSorry! CreateProcess() failed.\n\n");
				else

					printf("\nWell, CreateProcess() looks OK.\n\n");
					
					WaitForSingleObject(pi.hProcess, INFINITE);
					printf("\n");
					CloseHandle(pi.hProcess);
					CloseHandle(pi.hThread);
			}
			else
            if(strcmp(command,"rename")==0)
        {
            scanf("%s",&hner);
            scanf("%s",&shner);
            if(rename(hner,shner)==0)
            printf("File ner soligdson\n");
            else
                printf("hner ner tanigdsngui\n");
        }
        else
            if(strcmp(command,"del")==0)
      {
            scanf("%s",&file_ner);
            if(remove(file_ner)==0)
            printf("amjilttai ustsan");
            else
            printf("im nertei file oldsongui");
      }
        else
            printf("Bhgui command bna!!!");
        scanf("%s",&command);
    }
    
    


// Start the child process.

 

// Close process and thread handles.

return 0;
}
