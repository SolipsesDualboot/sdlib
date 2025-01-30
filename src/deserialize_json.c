#include "deserialize_json.h"


//long unsigned int i;
long unsigned int i;
long unsigned int s;
int list_depth;
_Bool title_in;
_Bool string_in;
_Bool escape_char;
char read_buffer[256];
char title_buffer[32];
char string_buffer[32];
char* tmpbuf;


//static int symbol_matcher();
static char* span_string();
void deserialize_json(FILE * infile);


// static int symbol_matcher(char* input_char)
// {
//     //if (input_char == '\0') {return 1;}
//
//     //if (input_char == '{' || input_char == '}') {return 2;}
//
//
//     else {return 0;}
// }


static char* span_string(const char* start_char, int delimiter)
{
    //char* stringy = strchr(start_char + 1, delimiter);
    //printf("%c", stringy[0]);
    return strchr(start_char + 1, delimiter);
}


void deserialize_json(FILE *infile)
{
    while(!(fgets(read_buffer, sizeof(read_buffer), infile) == NULL))
    {
        for (i = 0; i < sizeof(read_buffer); i++)
        {
            int stop = 0;

            /*! Character pattern matching */
            if (read_buffer[i] == '"')
            {
                s = 0;

                stop++;
                tmpbuf = span_string(&read_buffer[i], '"');
                //printf("%i %i %i\n", &tmpbuf[0], &read_buffer[i], &tmpbuf[0] - &read_buffer[i]);

                while (&read_buffer[i] != &tmpbuf[0 - 1] && s < sizeof(string_buffer))
                {
                    //printf("\nreadbuf: %c\n", read_buffer[i]);
                    string_buffer[s] = read_buffer[i + 1];
                    s++;
                    i++;
                }

                string_buffer[s] = '\0';
                printf("\nstringbuf: %s", string_buffer);

                //printf("\n%c, %c || %li, %li || %li || %c", read_buffer[i], tmpbuf[0], &read_buffer[i], &tmpbuf[0], (long int)&tmpbuf - (long int)&read_buffer[i], (int)&tmpbuf);
            }

            if (stop == 1) {/*!printf("\nStop\n"); */break;}

            // symbol_matcher(&read_buffer[i]);
            //
            // if (read_buffer[i] == '{' || read_buffer[i] == '}') {}
            //
            // //if (title_in == 1) {printf("%c", read_buffer[i]);}
            //
            // if (read_buffer[i] == '"') {title_in = !title_in;}
            //
            // if (read_buffer[i] == '\\') {escape_char = !escape_char;}
            //
            // else
            // {
            //     if (title_in == 1)
            //     {
            //
            //     }
            // }

            //printf("%i", list_depth);
            //printf("%i", title_in);
            //printf("%c", read_buffer[i]);
        }
    }

    return;
}
