#include "deserialize_json.h"


long unsigned int i;
long unsigned int s;
int list_depth;
_Bool title_in;
_Bool string_in;
_Bool escape_char;
_Bool title_skip;
char read_buffer[256];
char title_buffer[32];
char string_buffer[32];
char* tmpbuf;
enum json_data {NONE, STRING, INTEGER, OBJECT, ARRAY, BOOL} json_data;
enum json_read_mode {PARSE, TITLE, VALUE} json_read_mode;


void deserialize_json(FILE * infile);


void deserialize_json(FILE *infile)
{
    while(!(fgets(read_buffer, sizeof(read_buffer), infile) == NULL))
    {
        for (i = 0; i < sizeof(read_buffer); i++)
        {
            //printf("%c", read_buffer[i]);
            if (json_read_mode == PARSE)
            {
                if (read_buffer[i] == '"')
                {
                    json_read_mode = TITLE;
                }

                else if (read_buffer[i] == ':')
                {
                    json_read_mode = VALUE;
                }

                else
                {
                //printf("0");
                }
            }

            if (json_read_mode == TITLE)
            {
                tmpbuf = strchr(&read_buffer[i] + 1, '"');  // &read_buffer[i] + 1
                int tmpnum = &tmpbuf[0] - &read_buffer[i];
                //printf("%lu || %c\n", &tmpbuf[0] - &read_buffer[i], read_buffer[i]);
                // if (tmpbuf != NULL)
                // {
                //printf("%i ", tmpbuf);
                // }
                // if (tmpbuf = NULL)
                // {printf("%i", tmpbuf);}
                //printf("%i %i\n", tmpbuf[0], &tmpbuf[0], &read_buffer[i]);
                for(s = 0; tmpbuf != 0 && s < (long unsigned int)tmpnum; s++)
                {
                    //printf("tmpbuf %i", &tmpbuf[0]);
                    //printf("\nreadbuf: %c\n", read_buffer[i]);
                    string_buffer[s] = read_buffer[i + 1];
                    //s++;
                    i++;
                }

                string_buffer[s-1] = '\0';
                printf("\ntitle: %s", string_buffer);
                json_read_mode = PARSE;
            }

            if (json_read_mode == VALUE)
            {
                json_read_mode = PARSE;
            }

            /*! OLD CODE */
            // int stop = 0;
            //
            // /*! Character pattern matching */
            // if (read_buffer[i] == '"')
            // {
            //     s = 0;
            //
            //     stop++;
            //     tmpbuf = strchr(&read_buffer[i] + 1, '"');
            //     //printf("%i %i %i\n", &tmpbuf[0], &read_buffer[i], &tmpbuf[0] - &read_buffer[i]);
            //
            //
            //     /*! Read string into string_buffer */
            //     while (&read_buffer[i] != &tmpbuf[0 - 1] && s < sizeof(string_buffer))
            //     {
            //         //printf("\nreadbuf: %c\n", read_buffer[i]);
            //         string_buffer[s] = read_buffer[i + 1];
            //         s++;
            //         i++;
            //     }
            //
            //     string_buffer[s] = '\0';
            //     printf("\nstringbuf: %s", string_buffer);
            //
            //     //printf("\n%c, %c || %li, %li || %li || %c", read_buffer[i], tmpbuf[0], &read_buffer[i], &tmpbuf[0], (long int)&tmpbuf - (long int)&read_buffer[i], (int)&tmpbuf);
            // }
            //
            // if (stop == 1) {/*!printf("\nStop\n"); */break;}
        }
    }

    return;
}
