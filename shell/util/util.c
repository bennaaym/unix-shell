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


