/**
 * @file parser.c
 * @author Hajer Gafsi
 * @brief Holds the implementation of the different functions related to the parser
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <string.h>
#include "../config/config.h"
#include "../command_handler/handler.h"
#include "../util/util.h"
#include <stdio.h>

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

int processInput(char* input, char** parsed)
{

	// checks constraints
	if(strlen(input) > CONFIG.COMMAND_MAX_CHARS)
	{
		displayError("MaxLengthError","length shouldn't exceed 80 characters !");
		return -1;
	}else if(getNumberOfWords(input) > CONFIG.COMMAND_MAX_WORDS){
		displayError("MaxNumberOfWordsError","The maximum number of words allowed in the command is 10 !");
		return -1;
	}


	parseSpace(input, parsed);
	

	if (handleBuiltinCommand(parsed))
		return 0;
	else
		return 1;
}

