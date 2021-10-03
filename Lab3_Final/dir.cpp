#define _WIN32_WINNT 0x0501
#include <stdio.h>
#include <conio.h>
#include <dirent.h>
#include <windows.h>				
#include <stdio.h>

int main(void){
	
	struct dirent *Insert;
	DIR *dr = opendir(".");
	
	char input[20], text[20], a[20], b[20], c[20], d[20];
	scanf("%s",&input);
	
	while(input!=0){
		
	        if(strcmp(input,"dir")==0){
	        	
		        while((Insert = readdir(dr))!=NULL)
		        printf("%s\n",Insert->d_name);
		        closedir(dr);
	        }
	        else
	        	if(strcmp(input, "process")==0){
                  scanf("%s", &d);
                  STARTUPINFO sinfo;        
				  PROCESS_INFORMATION    pinfo;        
				  memset(&sinfo, 0, sizeof(STARTUPINFO));
				  memset(&pinfo, 0, sizeof(PROCESS_INFORMATION));
				  sinfo.dwFlags = STARTF_USESHOWWINDOW;
				  sinfo.wShowWindow = SW_SHOWMAXIMIZED;
				  BOOL bSucess = CreateProcess("C:\\Windows\\notepad.exe", NULL, NULL, NULL, FALSE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &sinfo, &pinfo);
			}
	        else
	            if(strcmp(input,"create")==0){
	            	
		          scanf("%s",&a);
		          FILE* fptr=fopen(a, "w");
		          printf("Successfully created\n");
		          fclose(fptr);
	        	}
	        else
	            if(strcmp(input,"input")==0){
	            	
		            scanf("%s",&a);
		            FILE* fptr=fopen(a, "w");
		            gets(text);
		            fprintf(fptr,"%s",text);
		            fclose(fptr);
	        	}
	        else
	            if(strcmp(input,"rename")==0){
	            	
		            scanf("%s",&a);
		            scanf("%s",&b);
		            
			            if(rename(a,b)==0)
			            printf("Successfully changed\n");
	        	}
	        else
	            if(strcmp(input,"del")==0){
	            	
	            	scanf("%s",&a);
	            	
			        if(remove(a)==0)
			        printf("Successfully deleted\n");
			        
			        else
			        printf("The system cannot find\n");
	       		}
	        else
	            printf("Access is denied!!!\n");
	        	scanf("%s",&input);
	    }
	return 0;
}
