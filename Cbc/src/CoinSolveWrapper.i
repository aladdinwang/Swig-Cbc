%module cbc
%{
#include "CoinSolveWrapper.hpp"
%}
%include "std_string.i"

%typemap(in) (int argc, char *argv[]) { int i;
if (!PyList_Check($input)) { PyErr_SetString(PyExc_ValueError, "Expecting a list"); SWIG_fail;
}
$1 = PyList_Size($input);
$2 = (char **) malloc(($1+1)*sizeof(char *)); for (i = 0; i < $1; i++) {
PyObject *s = PyList_GetItem($input, i); if (!PyString_Check(s)) {
free($2);
PyErr_SetString(PyExc_ValueError, "List items must be strings"); SWIG_fail;
}
$2[i] = PyString_AsString(s); }
$2[i] = 0; }
%typemap(freearg) (int argc, char *argv[]) { if ($2) free($2);
}
/* Required for C++ method overloading */ %typecheck(SWIG_TYPECHECK_STRING_ARRAY) (int argc, char *argv[]) {
$1 = PyList_Check($input) ? 1 : 0; }


std::string cbc_main(int argc, const char * argv[]);
std::string cbc_main2(int argc, const char * argv[]);
