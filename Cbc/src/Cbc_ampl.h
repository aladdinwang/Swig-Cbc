/* $Id: Cbc_ampl.h 1573 2011-01-05 01:12:36Z lou $ */
/*
  Copyright (C) 2006, International Business Machines Corporation and others.
  All Rights Reserved.

  This code is licensed under the terms of the Eclipse Public License (EPL).
*/

#ifndef AmplInterface_H
#define AmplInterface_H
typedef struct {
    int numberRows;
    int numberColumns;
    int numberBinary;
    int numberIntegers; /* non binary */
    int numberSos;
    int numberElements;
    int numberArguments;
    int problemStatus;
    double direction;
    double offset;
    double objValue;
    double * objective;
    double * rowLower;
    double * rowUpper;
    double * columnLower;
    double * columnUpper;
    int * starts;
    int * rows;
    double * elements;
    double * primalSolution;
    double * dualSolution;
    int * columnStatus;
    int * rowStatus;
    int * priorities;
    int * branchDirection;
    double * pseudoDown;
    double * pseudoUp;
    char * sosType;
    int * sosPriority;
    int * sosStart;
    int * sosIndices;
    double * sosReference;
    int * cut;
    int * special;
    char ** arguments;
    char buffer[300];
    int logLevel;
    int nonLinear;
} ampl_info;
#ifdef __cplusplus
extern "C" {
#endif
    /* return nonzero if bad */
    int readAmpl2(ampl_info * info, int argc, char ** argv,
    void ** coinModel);
    /* frees some input arrays */
    void freeArrays12(ampl_info * info);
    /* frees rest */
    void freeArrays22(ampl_info * info);
    /* frees fake arguments */
    void freeArgs2(ampl_info * info);
    /* writes ampl stuff */
    void writeAmpl2(ampl_info * info);
    /* objective precision */
    int ampl_obj_prec2();
#ifdef __cplusplus
}
#endif
#endif
