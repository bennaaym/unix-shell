/**
 * @file util.c
 * @author Aymen Bennabi
 * @brief Holds the implementation of utility functons
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <string.h>

void displayError(char* errorType, char* errorDescription)
{
    printf("\n");
    printf("%s :",errorType);
    printf("%s",errorDescription);
    printf("\n");
}

//calculates the number of words  
int getNumberOfWords(char *s){
    int i,j,count=0;
    for(i=0,j=1;i<strlen(s)-1;i++,j++)  
    {
        if(s[i]=='"'){
            i++;j++;
            while (s[i]!='"')
            {
                i++;j++;
            }            
        }
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

char* removeLeadingSpaces(char* str)
{
    char* str1 ;
    str1 = malloc(sizeof(char)*(strlen(str)+1));
    int count = 0, j, k;
    while (str[count] == ' ') {
        count++;
    }

    for (j = count, k = 0;
         str[j] != '\0'; j++, k++) {
        str1[k] = str[j];
    }
    str1[k] = '\0';
    return str1;
}

char* splitString(char* str, char* destinationStr){
    int j=0;
    char *tmp = malloc(sizeof(char)*strlen(str)) ;
    while(str[j] != '\0'){
        if(str[j] == '"'){
         destinationStr[j] = str[j];j++;
         while (str[j] != '"')
         {
            destinationStr[j] = str[j]; 
            j++;
         }        
        }
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


