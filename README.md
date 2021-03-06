# Picrin [![Build Status](https://travis-ci.org/wasabiz/picrin.png)](https://travis-ci.org/wasabiz/picrin)

Picrin is a lightweight scheme implementation intended to comply with full R7RS specification. Its code is written in pure C99 and does not requires any special external libraries installed on the platform.

## Features

- R7RS compatibility (but partial support)
- reentrant design (all VM states are stored in single global state object)
- bytecode interpreter (based on stack VM)
- direct threaded VM
- internal representation by nan-boxing
- conservative call/cc implementation (users can freely interleave native stack with VM stack)
- exact GC (simple mark and sweep, partially reference count is used as well)
- string representation by rope data structure
- support full set hygienic macro transformers, including implicit renaming macros
- extended library syntax
- advanced REPL support (multi-line input, etc)
- tiny & portable library (all functions will be in `libpicrin.so`)

## Libraries

    - `(scheme base)`
    - `(scheme write)`
    - `(scheme cxr)`
    - `(scheme file)`
    - `(scheme inexact)`
    - `(scheme time)`
    - `(scheme process-context)`
    - `(scheme load)`
    - `(scheme lazy)`
    - `(picrin macro)`
    
        - `define-macro`
        - `gensym`
        - `macroexpand`
    
            Old-fashioned macro.
    
        - `make-syntactic-closure`
        - `identifier?`
        - `identifier=?`
    
            Syntactic closures.
    
        - `er-macro-transformer`
        - `ir-macro-transformer`
    
            Explicit renaming macro family.

    - `(picrin regexp)`

        - `(regexp? obj)`
        - `(regexp ptrn [flags])`

            Compiles pattern string into a regexp object. A string `flags` may contain any of #\g, #\i, #\m.

        - `(regexp-match re input)`

            Returns two values: a list of match strings, and a list of match indeces.

        - `(regexp-replace re input txt)`
        - `(regexp-split re input)`

    - `(picrin control)`

        - `(reset h)`
        - `(shift k)`

            delimited control operators

	- `(picrin user)`

		When you start the REPL, you are dropped into here.
    
    - `(srfi 1)`
    
        List manipulation library.

    - `(srfi 95)`

        Sorting and Marging.
    

## The REPL

At the REPL start-up time, some usuful built-in libraries listed below will be automatically imported.

- `(scheme base)`
- `(scheme load)`
- `(scheme process-context)`
- `(scheme write)`
- `(scheme file)`
- `(scheme inexact)`
- `(scheme cxr)`
- `(scheme lazy)`
- `(scheme time)`

## Compliance with R7RS

| section | status | comments |
| --- | --- | --- |
| 2.2 Whitespace and comments | yes | |
| 2.3 Other notations | incomplete | #e #i #b #o #d #x |
| 2.4 Datum labels | yes | |
| 3.1 Variables, syntactic keywords, and regions | | |
| 3.2 Disjointness of types | yes | |
| 3.3 External representations | | |
| 3.4 Storage model | yes | |
| 3.5 Proper tail recursion | yes | As the report specifies, `apply`, `call/cc`, and `call-with-values` perform tail calls |
| 4.1.1 Variable references | yes | |
| 4.1.2 Literal expressions | yes | |
| 4.1.3 Procedure calls | yes | In picrin `()` is self-evaluating |
| 4.1.4 Procedures | yes | |
| 4.1.5 Conditionals | yes | In picrin `(if #f #f)` returns `#f` |
| 4.1.6 Assignments | yes | |
| 4.1.7 Inclusion | incomplete | `include-ci`. TODO: Once `read` is implemented rewrite `include` macro with it. |
| 4.2.1 Conditionals | incomplete | TODO: `cond-expand` |
| 4.2.2 Binding constructs | yes | |
| 4.2.3 Sequencing | yes | |
| 4.2.4 Iteration | yes | |
| 4.2.5 Delayed evaluation | N/A | |
| 4.2.6 Dynamic bindings | yes | |
| 4.2.7 Exception handling | no | `guard` syntax. |
| 4.2.8 Quasiquotation | yes | can be safely nested. TODO: multiple argument for unquote |
| 4.2.9 Case-lambda | N/A | |
| 4.3.1 Bindings constructs for syntactic keywords | incomplete | (*1) |
| 4.3.2 Pattern language | yes | `syntax-rules` |
| 4.3.3 Signaling errors in macro transformers | yes | |
| 5.1 Programs | yes | |
| 5.2 Import declarations | incomplete | only simple import declarations, no support for import with renaming. |
| 5.3.1 Top level definitions | yes | |
| 5.3.2 Internal definitions | yes | TODO: interreferential definitions |
| 5.3.3 Multiple-value definitions | yes | |
| 5.4 Syntax definitions | yes | TODO: internal macro definition is not supported. |
| 5.5 Recored-type definitions | yes | |
| 5.6.1 Library Syntax | incomplete | In picrin, libraries can be reopend and can be nested. |
| 5.6.2 Library example | N/A | |
| 5.7 The REPL | yes | |
| 6.1 Equivalence predicates | yes | TODO: equal? must terminate if circular structure is given |
| 6.2.1 Numerical types | yes | picrin has only two types of internal representation of numbers: fixnum and double float. It still comforms the R7RS spec. |
| 6.2.2 Exactness | yes | |
| 6.2.3 Implementation restrictions | yes | |
| 6.2.4 Implementation extensions | yes | |
| 6.2.5 Syntax of numerical constants | yes | |
| 6.2.6 Numerical operations | yes | `denominator`, `numerator`, and `rationalize` are not supported for now. Also, picrin does not provide complex library procedures. |
| 6.2.7 Numerical input and output | incomplete | only partial support supplied. |
| 6.3 Booleans | yes | |
| 6.4 Pairs and lists | yes | `list?` is safe for using against circular list. |
| 6.5 Symbols | yes | |
| 6.6 Characters | yes | |
| 6.7 Strings | yes | |
| 6.8 Vectors | yes | |
| 6.9 Bytevectors | yes | |
| 6.10  Control features | yes | |
| 6.11 Exceptions | yes | `raise-continuable` is not supported |
| 6.12 Environments and evaluation | N/A | |
| 6.13.1 Ports | yes | |
| 6.13.2 Input | incomplete | TODO: binary input |
| 6.13.3 Output | yes | |
| 6.14 System interface | yes | |

1. Picrin provides hygienic macros in addition to so-called legacy macro (`define-macro`), such as syntactic closure, explicit renaming macro, and implicit renaming macro. As of now let-syntax and letrec-syntax are not provided.

## Homepage

Currently picrin is hosted on Github. You can freely send a bug report or pull-request, and fork the repository.

https://github.com/wasabiz/picrin

## IRC

There is a chat room on chat.freenode.org, channel #picrin.

## How to use it

- make `Makefile`

	Change directory to `build` then run `cmake` to create Makefile. Once `Makefile` is generated you can run `make` command to build picrin.

		$ cd build
        $ cmake ..

	Actually you don't necessarily need to move to `build` directory before running `cmake` (in that case `$ cmake .`), but I strongly recommend to follow above instruction.
    
- build

 	A built executable binary will be under bin/ directory and shared libraries under lib/.

        $ make

	If you are building picrin on other systems than x86_64, PIC_NAN_BOXING flag is automatically turned on (see include/picrin/config.h for detail).

- install

	Just running `make install`, picrin library, headers, and runtime binary are install on your system, by default into `/usr/local` directory. You can change this value via ccmake.

		$ make install

- run

	Before installing picrin, you can try picrin without breaking any of your system. Simply directly run the binary `bin/picrin` from terminal, or you can use `make` to execute it like this.

		$ make run

- debug run

	If you execute `cmake` with debug flag `-DCMAKE_BUILD_TYPE=Debug`, it builds the binary with all debug flags enabled (PIC_GC_STRESS, VM_DEBUG, DEBUG).

		$ cmake -DCMAKE_BUILD_TYPE=Debug ..
	

## Requirement

Picrin scheme depends on some external libraries to build the binary:

- perl
- lex (preferably, flex)
- getopt
- readline (optional)
- regex.h of POSIX.1 (optional)

Optional libraries are, if cmake detected them, automatically enabled.
The compilation is tested only on Mac OSX and Ubuntu. I think (or hope) it'll be ok to compile and run on other operating systems such as Arch or Windows, but I don't guarantee :(

## Authors

See `AUTHORS`
