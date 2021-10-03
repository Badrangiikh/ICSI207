#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <Windows.h>

void dir_command(char *path){
	DIR *d;
    struct dirent *dir;
    struct stat filestat;
    puts(path);
    d = opendir(path);
    if(d == NULL)
    {
        printf("Unable to read directory\n");
        return;
    }
    int dirNumber=0, fileNumber=0;
    int totalFileSize=0;
    while((dir = readdir(d))){
        stat(dir->d_name,&filestat);
        char time[50];
        strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&filestat.st_mtime));
        printf ("%s\t", time);
        if(S_ISDIR(filestat.st_mode)){
            dirNumber++;
            printf("<DIR>\t\t%s\n",dir->d_name);
         }
         else {
             fileNumber++;
             printf("%15d %s\n",filestat.st_size,dir->d_name);
             totalFileSize=totalFileSize+filestat.st_size;
         }
    }
    printf("%10d File(s) %15d bytes\n",fileNumber,totalFileSize);
    printf("%10d Dir(s) %15d bytes free\n",dirNumber, &filestat.st_size);
    closedir(d);
}

void createFile(char *fileName){
	FILE *fp;
	fp  = fopen (fileName, "w");
	if(fp == NULL)
    {
        printf("Unable to create file.\n");
        return;
    }
    printf("%s File created\n",fileName);
	fclose (fp);
}

void deleteFile(char *fileName){
    int del = remove(fileName);
    if (!del)
        printf("The file is Deleted successfully\n");
    else
        printf("The file is not Deleted\n");
}

void inputData(char *inputDataFileName,char *inputDatas){
    FILE *fp;
	fp  = fopen (inputDataFileName, "w");
	if(fp == NULL)
    {
        printf("Unable to input data in file.\n");
        return;
    }
    fprintf(fp,"%s",inputDatas);
    printf("Data included in file.\n");
	fclose (fp);
}

void renameFileName(char *fileOldName,char *fileNewName){
    if (rename(fileOldName, fileNewName) == 0)
    {
        printf("File renamed successfully.\n");
    }
    else
    {
        printf("Unable to rename files.\n");
    }
}
void createProcess(char *p_name){
	STARTUPINFO structSi;
	PROCESS_INFORMATION structPi;

	memset(&structSi, 0, sizeof(structSi));
	structSi.cb = sizeof(structSi);
	memset(&structPi, 0, sizeof(structPi));
	
	if(!CreateProcess(
		NULL,
		p_name,
		NULL, //process handle (not inheritable)
		NULL,//thread handle (not inheritable)
		FALSE,//handle inheritance set to FALSE
		0, // no creation flags
		NULL, //use parent's environment block
		NULL, //use parent's starting directory
		&structSi,
		&structPi)
		){
			printf("Problem creating new process.\n");
	}
	
}
int  main(){
    char userInputCommand[100];
	while(1){
		strcpy(userInputCommand,"");
	    gets(userInputCommand);
	    char *command=strtok(userInputCommand, " ");
        puts(command);
        if(strcmp(strupr(command),"DIR")==0){
            char *path=strtok(0, " ");
            if(path!=0){
                dir_command(path);
            }
            else{
                dir_command(".");
            }
        }
        else if(strcmp(strupr(command),"CREATE")==0){
            char *newFileName=strtok(0, " ");
            if(newFileName!=0){
                createFile(newFileName);
            }
            else{
                printf("Error: File name is empty\n");
            }
        }
        else if(strcmp(strupr(command),"INPUT")==0){
            char *inputDataFileName=strtok(0, " ");
            if(inputDataFileName!=0){
                char *inputDatas=strtok(0, "");
                if(inputDatas!=0){
                    inputData(inputDataFileName,inputDatas);
                }
                else{
                    printf("Error: Data is empty\n");
                }
            }
            else{
                printf("Error: File name is empty\n");
            }
        }
        else if(strcmp(strupr(command),"RENAME")==0){
            char *fileOldName=strtok(0, " ");
            if(fileOldName!=0){
                char *fileNewName=strtok(0, " ");
                if(fileNewName!=0){
                    renameFileName(fileOldName,fileNewName);
                }
                else{
                    printf("Error: File new name is empty\n");
                }
            }
            else{
                printf("Error: File old name is empty\n");
            }
        }
        else if(strcmp(strupr(command),"DEL")==0){
            char *delFileName=strtok(0, " ");
            if(delFileName!=0){
                deleteFile(delFileName);
            }
            else{
                printf("Error: File name is empty\n");
            }
        }
	}
	return 0;
}