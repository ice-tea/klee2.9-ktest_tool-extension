klee2.9-ktest_tool-extension
============================
Problem description:<br />
as Mark R. Tuttle said, there is no effective and elegant way to <br />
print out the complex layout messages of an aggregate type,<br />
from website:http://comments.gmane.org/gmane.comp.compilers.llvm.klee/1619<br />
and Cristian Cadar suggested the best solution would be to extend <br />
the ktest-tool (a small program written in Python) to output data in the <br />
desired format.<br />

In this project, I just Modified the getSymbolicSolution function in the file Executor.cpp<br />
which is called by function KleeHandler::processTestCase in the file main.cpp.<br />

By some implementation codes into klee 2.9 version (mainly modified Executor.cpp) to<br />
extent the test-tool's function such as print out the specific layout message of aggregate type.<br />

Here is an example:<br />
source coe to be tested:<br />
  typedef struct s{<br />
    int a;<br />
    int b;<br />
  }ss;<br />
  ss a[2];<br />
  klee_make_symbolic(&a, sizeof(a), "a”);<br />
<br />
and the out put messages are follows:
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
My implementation code can be seen from: 
https://github.com/ice-tea/klee2.9-ktest_tool-extension
(https://bitbucket.org/ice_tea/klee2.9-ktest_tool-extension)
