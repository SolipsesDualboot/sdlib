#include "silvio.h"


int CHAR_NAME_LIMIT = 10+1;
int CHAR_INPUT_LIMIT = 20+1;


char* sil_Cin(char* input, int input_len, _Bool clear_cin)
{
    for(;;)
    {
        if(fgets(input, input_len, stdin) == NULL)
        {
            printf("fatal stdin error");
            exit(EXIT_FAILURE);
        }

        if(input[strlen(input)-1] != '\n')
        {
            if(clear_cin)
            {
                scanf("%*[^\n]");
                scanf("%*c");
            }
        }
        return input;
    }
}
