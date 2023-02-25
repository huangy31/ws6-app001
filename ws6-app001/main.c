#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>
#include "log4c.h"
#include "assert.h"


int main(void)
{
    char errMsg[L4C_ERROR_MSG_MAX + 1] = { 0 };
    struct Log4cStruct log = l4cOpen("log.txt", 0);
    /*if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);
    else
    {
        l4cError(&log, "error msg");
        if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

        l4cWarning(&log, "warning msg");
        if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

        l4cInfo(&log, "info msg");
        if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

        l4cPrintf(&log, L4C_INFO, "I am %d years old", 47);
        if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

        l4cClose(&log);
    }*/
    char testStr[] = { "This is a\n string with embedded newline characters and \n12345 numbers inside it as well 7890" };
    struct StringIndex index = indexString(testStr);
    int i;
    char text[20];
    printf("LINES\n");
    l4cInfo(&log, "info msg");
    sprintf(text, "%d", index.numLines);
    l4cInfo(&log, "the value of index.numLines is ");
    l4cInfo(&log, text);

    int nol = 1;
    for (int i = 0;testStr[i] != '\0';i++) {
        if (testStr[i] == '\n')
            ++nol;
    }
    printf("number of lines=%d\n", nol);

    //assert(index.numLines == nol);

    for (i = 0; i < nol; i++)
    {
        
        //l4cInfo(&log, "the value of i is ", sprintf(text,"%d",i));
        sprintf(text, "%d", i);
        l4cInfo(&log, "the value of i is ");
        l4cInfo(&log,  text);

        

        printUntil(index.str, index.lineStarts[i], '\n');
        printf("\n");
    }
    printf("\nWORDS\n");
    for (i = 0; i < index.numWords; i++)
    {
        printUntilSpace(index.str, index.wordStarts[i]);
        printf("\n");
    }
    printf("\nNUMBERS\n");
    for (i = 0; i < index.numNumbers; i++)
    {
        printUntilSpace(index.str, index.numberStarts[i]);
        printf("\n");
    }

    return 0;
}