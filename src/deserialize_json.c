#include <stdio.h>
#include "deserialize_json.h"


void deserialize_json(FILE *infile)
{
    long unsigned int i;
    char read_buffer[4096];
    fgets(read_buffer, sizeof(read_buffer) - 6, infile);
    for (i = 0; i < sizeof(read_buffer); i++)
    {
        printf("%lu", i);
    }
    fclose(infile);
    return;
}
