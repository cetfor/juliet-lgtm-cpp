/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_w32_execv_12.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-12.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sink: w32_execv
 *    BadSink : execute command with execv
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define COMMAND_INT_PATH "%WINDIR%\\system32\\cmd.exe"
#define COMMAND_INT "cmd.exe"
#define COMMAND_ARG1 "/c"
#define COMMAND_ARG2 "dir "
#define COMMAND_ARG3 data
#else /* NOT _WIN32 */
#include <unistd.h>
#define COMMAND_INT_PATH "/bin/sh"
#define COMMAND_INT "sh"
#define COMMAND_ARG1 "-c"
#define COMMAND_ARG2 "ls "
#define COMMAND_ARG3 data
#endif

#include <process.h>
#define EXECV _execv

#ifndef OMITBAD

void CWE78_OS_Command_Injection__char_console_w32_execv_12_bad()
{
    char * data;
    char dataBuffer[100] = COMMAND_ARG2;
    data = dataBuffer;
    if(globalReturnsTrueOrFalse())
    {
        {
            /* Read input from the console */
            size_t dataLen = strlen(data);
            /* if there is room in data, read into it from the console */
            if (100-dataLen > 1)
            {
                /* POTENTIAL FLAW: Read data from the console */
                if (fgets(data+dataLen, (int)(100-dataLen), stdin) != NULL)
                {
                    /* The next few lines remove the carriage return from the string that is
                     * inserted by fgets() */
                    dataLen = strlen(data);
                    if (dataLen > 0 && data[dataLen-1] == '\n')
                    {
                        data[dataLen-1] = '\0';
                    }
                }
                else
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
            }
        }
    }
    else
    {
        /* FIX: Append a fixed string to data (not user / external input) */
        strcat(data, "*.*");
    }
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* execv - specify the path where the command is located */
        /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
        EXECV(COMMAND_INT_PATH, args);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the "if" so that
 * both branches use the GoodSource */
static void goodG2B()
{
    char * data;
    char dataBuffer[100] = COMMAND_ARG2;
    data = dataBuffer;
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Append a fixed string to data (not user / external input) */
        strcat(data, "*.*");
    }
    else
    {
        /* FIX: Append a fixed string to data (not user / external input) */
        strcat(data, "*.*");
    }
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* execv - specify the path where the command is located */
        /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
        EXECV(COMMAND_INT_PATH, args);
    }
}

void CWE78_OS_Command_Injection__char_console_w32_execv_12_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE78_OS_Command_Injection__char_console_w32_execv_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_console_w32_execv_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
