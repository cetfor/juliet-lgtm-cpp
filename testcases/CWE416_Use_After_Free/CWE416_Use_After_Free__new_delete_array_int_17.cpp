/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_array_int_17.cpp
Label Definition File: CWE416_Use_After_Free__new_delete_array.label.xml
Template File: sources-sinks-17.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after delete[]
 * Flow Variant: 17 Control flow: for loops
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_array_int_17
{

#ifndef OMITBAD

void bad()
{
    int i,j;
    int * data;
    /* Initialize data */
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = new int[100];
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5;
            }
        }
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete [] data;
    }
    for(j = 0; j < 1; j++)
    {
        /* POTENTIAL FLAW: Use of data that may have been deleted */
        printIntLine(data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink in the for statements */
static void goodB2G()
{
    int i,k;
    int * data;
    /* Initialize data */
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = new int[100];
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5;
            }
        }
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete [] data;
    }
    for(k = 0; k < 1; k++)
    {
        /* FIX: Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B() - use goodsource and badsink in the for statements */
static void goodG2B()
{
    int h,j;
    int * data;
    /* Initialize data */
    data = NULL;
    for(h = 0; h < 1; h++)
    {
        data = new int[100];
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5;
            }
        }
        /* FIX: Do not delete data in the source */
    }
    for(j = 0; j < 1; j++)
    {
        /* POTENTIAL FLAW: Use of data that may have been deleted */
        printIntLine(data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

void good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE416_Use_After_Free__new_delete_array_int_17; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
