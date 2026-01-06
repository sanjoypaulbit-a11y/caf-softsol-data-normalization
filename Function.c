#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}


const char* normalizeCompanyName(char *companyName)
{
    static const char standardName[] = "CAF SoftSol India Pvt Ltd.";

    if (companyName == NULL || strlen(companyName) == 0)
        return NULL;

    toLowerCase(companyName);

    if (strstr(companyName, "caf") &&
       (strstr(companyName, "soft") || strstr(companyName, "solution")))
    {
        return standardName;
    }

    return NULL;
}
