#include "deserialize_json.h"


void deserialize_json(FILE *infile)
{
    long unsigned int i;
    int list_depth;
    _Bool title_in;

    char read_buffer[256];

    while(!(fgets(read_buffer, sizeof(read_buffer), infile) == NULL))
    {
        for (i = 0; i < sizeof(read_buffer); i++)
        {
            if (read_buffer[i] == '\0') {break;}

            if (read_buffer[i] == '{') {list_depth++;}

            if (read_buffer[i] == '}') {list_depth--;}

            if (read_buffer[i] == '"') {title_in = !title_in;}



            //printf("%i", list_depth);
            printf("%i", title_in);
            //printf("%c", read_buffer[i]);
        }
    }

    return;
}
