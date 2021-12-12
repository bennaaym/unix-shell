#include "prompt/prompt.h"
#include "parser/parser.h"
#include "command_handler/handler.h"
#include "config/config.h"
#include <stdio.h>
#include "__tests__/tests.h"

int main()
{
    run_tests();
    
    char input[CONFIG.COMMAND_MAX_CHARS];
    char* parsed[CONFIG.COMMAND_MAX_WORDS];
    int COMMAND_TYPE = -1;

    initPrompt();

    while(1)
    {
        prompt();
        if(!readInput(input)) continue;
        /**
         * COMMAND_TYPE
         * 0 : builtin
         * 1 : system command
         */

        COMMAND_TYPE = processInput(input,parsed);
        
        if(COMMAND_TYPE == 1)
            handleSystemCommand(parsed);
        
    }
  
    return 0;
}