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
        sil_Cin(name, CHAR_NAME_LIMIT, CLEAR_CIN);
        printf("\n%s\n", name);
    }

    return 0;
}
