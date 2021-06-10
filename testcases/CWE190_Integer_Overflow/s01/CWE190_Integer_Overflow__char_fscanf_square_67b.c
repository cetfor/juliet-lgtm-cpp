/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fscanf_square_67b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

typedef struct _CWE190_Integer_Overflow__char_fscanf_square_67_structType
{
    char structFirst;
} CWE190_Integer_Overflow__char_fscanf_square_67_structType;

#ifndef OMITBAD

void CWE190_Integer_Overflow__char_fscanf_square_67b_badSink(CWE190_Integer_Overflow__char_fscanf_square_67_structType myStruct)
{
    char data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: if (data*data) > CHAR_MAX, this will overflow */
        char result = data * data;
        printHexCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_fscanf_square_67b_goodG2BSink(CWE190_Integer_Overflow__char_fscanf_square_67_structType myStruct)
{
    char data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: if (data*data) > CHAR_MAX, this will overflow */
        char result = data * data;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_fscanf_square_67b_goodB2GSink(CWE190_Integer_Overflow__char_fscanf_square_67_structType myStruct)
{
    char data = myStruct.structFirst;
    /* FIX: Add a check to prevent an overflow from occurring */
    if (abs((long)data) <= (long)sqrt((double)CHAR_MAX))
    {
        char result = data * data;
        printHexCharLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

#endif /* OMITGOOD */
