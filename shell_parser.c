#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

  
#define MAXCOM 80 // max number of letters to be supported
#define MAXLIST 10 // max number of commands to be supported
  
// Clearing the shell using escape sequences
#define clear() printf("\033[H\033[J")

//trims the beginning of a string
char* removeLeadingSpaces(char* str)
{
    char* str1 ;
    str1 = malloc(sizeof(char)*(strlen(str)+1));
    int count = 0, j, k;
  
    // Iterate String until last
    // leading space character
    while (str[count] == ' ') {
        count++;
    }
  
    // Putting string into another
    // string variable after
    // removing leading white spaces
    for (j = count, k = 0;
         str[j] != '\0'; j++, k++) {
        str1[k] = str[j];
    }
    str1[k] = '\0';
    return str1;
}


//calculates the number of words  
int getNumberOfWords(char *s){
    int i,j,count=0;
    for(i=0,j=1;i<strlen(s)-1;i++,j++)  
    {
    	if(s[i]==' ')
    	{      
          if(s[j]==' '){
              continue;
          };
          count++;
		}
 	}
 	return (count+1);
}


char* splitString(char* str, char* destinationStr){
    int j=0;
    char *tmp = malloc(sizeof(char)*strlen(str)) ;
    while(str[j] != '\0'){
        if(str[j] == ' '){
            destinationStr[j] = '\0';
            break;
            }
        destinationStr[j] = str[j];
        j++;
    }   
    str = removeLeadingSpaces(str+j+1);
    strcpy(tmp,str);
    memset(tmp+strlen(str),'\0',1);
    return tmp;
}
// function for parsing command words
void parseSpace(char* str, char** parsed)
{
    int i,nmbrOfWords=getNumberOfWords(str);
    for (i = 0; i < nmbrOfWords; i++) {
        int nmbr = getNumberOfWords(str);
        parsed[i] = malloc(sizeof(char)*strlen(str)); 
        if( nmbr > 1)str = splitString(str, parsed[i]);
        else {
            parsed[i]=removeLeadingSpaces(str);
            }
        if (parsed[i] == NULL)
            break;
        if (strlen(parsed[i]) == 0)
            i--;
    }

}

// Function to print Current Directory.
void printDir()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\nDir: %s", cwd);
}
  

// Function to take input
int takeInput(char* str,int max,int max_words)
{
    char* buf;
    printf("\n>>> ") ;
    buf = malloc((max+2)*sizeof(char));
    fgets(buf, max+2, stdin);
    if (strlen(buf)-1 != 0 && strlen(buf) <= max) {
        if(buf[0] == ' '){
            printf("\nerror: command should not start with a space  !\n"); 
            fflush(stdin);
            return 1;          
        }else if(buf[strlen(buf)-2] == ' '){
            printf("\nerror: command should not end with a space  !\n"); 
            fflush(stdin);
            return 1;  
        }else if(getNumberOfWords(buf)>(max_words)){
            printf("\nerror: command should not contain more than 10 words !\n"); 
            fflush(stdin);
            return 1;             
        }else {
            strcpy(str, buf);
            memset(str+strlen(str)-1,'\0',1);
            return 0;            
        }
    } else if (strlen(buf) > max){
        printf("\nerror: command length shouldn't exceed 80 characters !\n"); 
        fflush(stdin);
        return 1;
    } else {
        printf("\nerror: empty command !\n");
        fflush(stdin); 
        return 1;    
    }
}

int main()
{
    char inputString[MAXCOM], *parsedArgs[MAXLIST];
    char* parsedArgsPiped[MAXLIST];
    int execFlag = 0;
    int i;
    while (1) {
        // print shell line
        printDir();
        // take input
        if (takeInput(inputString,MAXCOM,MAXLIST)){
            continue;
        }  
        
        // process
        parseSpace(inputString, parsedArgs);
        printf("\ncommand name : %s\n params: \n",parsedArgs[0]);
        for(i=1;i<getNumberOfWords(inputString);i++){
            printf("param no:%d :%s\n",i,parsedArgs[i]);
        }
    }
    return 0;
}