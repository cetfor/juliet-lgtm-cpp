/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_min_predec_61b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for unsigned int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

unsigned int CWE191_Integer_Underflow__unsigned_int_min_predec_61b_badSource(unsigned int data)
{
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = 0;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
unsigned int CWE191_Integer_Underflow__unsigned_int_min_predec_61b_goodG2BSource(unsigned int data)
{
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
unsigned int CWE191_Integer_Underflow__unsigned_int_min_predec_61b_goodB2GSource(unsigned int data)
{
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = 0;
    return data;
}

#endif /* OMITGOOD */
