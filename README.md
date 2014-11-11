klee2.9-ktest_tool-extension
============================
# Problem description:<br />
as Mark R. Tuttle said, there is no effective and elegant way to <br >
print out the complex layout messages of an aggregate type <br />
from website:[http://comments.gmane.org/gmane.comp.compilers.llvm.klee/1619] <br />
and Cristian Cadar suggested 
>the best solution would be to extend the ktest-tool (a small program written in Python) <br />
>to output data in the desired format.<br />

# My implementation <br >
In this project, I just Modified the **getSymbolicSolution** function in the file __Executor.cpp__<br />
which is called by function **KleeHandler::processTestCase** in the file __main.cpp__<br />

By some implementation codes into klee 2.9 version (mainly modified Executor.cpp) to<br />
extent the test-tool's function such as print out the specific layout message of aggregate type.<br />

Here is an example:<br />
source coe to be tested:<br />
<pre><code>
  typedef struct s{<br />
    int a;<br />
    int b;<br />
  }ss;<br />
  ss a[2];<br />
  klee_make_symbolic(&a, sizeof(a), "a”);<br />
  </code></pre>
<br />
and the out put messages are follows:
<pre><code>
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
</code></pre>
in which a is an array with length 2, and the element type is a struct with two int fields.<br />
My implementation code can be seen from: <br />
+[https://github.com/ice-tea/klee2.9-ktest_tool-extension] <br />
+[https://bitbucket.org/ice_tea/klee2.9-ktest_tool-extension] <br />
