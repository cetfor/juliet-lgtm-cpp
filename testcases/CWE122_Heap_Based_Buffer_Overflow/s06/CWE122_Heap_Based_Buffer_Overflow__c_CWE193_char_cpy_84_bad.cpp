/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_84_bad.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: cpy
 *    BadSink : Copy string to data using strcpy()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_84
{
CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_84_bad::CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_84_bad(char * dataCopy)
{
    data = dataCopy;
    /* FLAW: Did not leave space for a null terminator */
    data = (char *)malloc(10*sizeof(char));
    if (data == NULL) {exit(-1);}
}

CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_84_bad::~CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_84_bad()
{
    {
        char source[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        strcpy(data, source);
        printLine(data);
        free(data);
    }
}
}
#endif /* OMITBAD */
