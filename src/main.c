#include "deserialize_json.h"
#include "silvio.h"


int main()
{
    FILE *fptr;
    char name[10];

    fptr = fopen("test.json", "r");
    if (fptr == NULL)
    {
        perror("");
    }
    else
    {
    deserialize_json(fptr);
    }
    fclose(fptr);

    for(;;) /*! - Endless loop */
    {
        char maintmpbuf[11] = "\nabcdefghi\0";
        char* maintmpptr = &maintmpbuf[4];
        printf("%s %s %li %li", maintmpbuf, maintmpptr, (long int)&maintmpbuf[4], (long int)&maintmpptr[1]);
        sil_Cin(name, CHAR_NAME_LIMIT, CLEAR_CIN);
        printf("\n%s\n", name);
        break;
    }

    return 0;
}
