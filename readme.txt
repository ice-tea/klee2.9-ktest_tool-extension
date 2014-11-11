Problem description:
as Mark R. Tuttle said, there is no effective and elegant way to 
print out the complex layout messages of an aggregate type,
from website:http://comments.gmane.org/gmane.comp.compilers.llvm.klee/1619
and Cristian Cadar suggested the best solution would be to extend 
the ktest-tool (a small program written in Python) to output data in the 
desired format.

In this project, I just Modified the getSymbolicSolution function in the file Executor.cpp
which is called by function KleeHandler::processTestCase in the file main.cpp.

By some implementation codes into klee 2.9 version (mainly modified Executor.cpp) to
extent the test-tool's function such as print out the specific layout message of aggregate type.

Here is an example:

>>source coe to be tested:
    typedef struct s{
        int a;
        int b;
     }ss;
  ss a[2];
  klee_make_symbolic(&a, sizeof(a), "a”);

>>and the out put messages are follows:
     ktest file : 'test000001.ktest'
     args       : ['two_input.o']
     num objects: 4
     object    0: name: 'a[0](0)'
     object    0: size: 4
     object    0: data: 0
     object    1: name: 'a[0](1)'
     object    1: size: 4
     object    1: data: 0
     object    2: name: 'a[1](0)'
     object    2: size: 4
     object    2: data: 0
     object    3: name: 'a[1](1)'
     object    3: size: 4
     object    3: data: 0

in which a is an array with length 2, and the element type is a struct with two int fields.
My implementation code can be seen from: https://bitbucket.org/ice_tea/klee2.9-ktest_tool-extension