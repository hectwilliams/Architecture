# Architecture

## Architecture Reference 



## C

### GNU Compiler Collection 
------------
  gcc     
    
    command used to compile c and c++ programs 
  
  -c
  
    instructs compiler to compile source to object file 

  -o  
  
    specifies name of output file of linked objects 

------------
### CLANG 
  clang 
  
    compiler front end for programming languages C, C++, Objective-C, OpenMP 
  
  -sysroot
  
    directory serves as compiler's logical root for headers and libraries 

  -isysroot

    directory serves as compiler's logical root for headers

  -cc1

    Indicates the compiler front-end to be used 
  
  -triple

    Standard term used among engineers and developers specifying machine, vendor, and operatingsystem

    e.g. 

    x86_64-linux-gnu (machine-vendor-operatingsystem)

  -Wunder-prefix

    Compiler warns if undefined identifiers prefixed with TARGET_OS are evaluated ( #if directive )

  -Wdeprecated-objc-isa-usage

    Compiler warns of isa in Objectice-C ( isa is deprecated )

  -Werror 

    Treats all warnings as errors

  -Werror=implicit-function-declaration     

    Compiler warns of functions not yet declared and elevates those warning to errors 

  -emit-obj

    ...

  -mrelax-all

    Enables all optimizations 
  
  -disable-free 

    Improve build speed by disabling sanitizer metadata 

  -clear-ast-before-backend 

    Prior to loading backend with IR(Intermediate Representation), clear up memory before backend process 

  -disable-llvm-verifier 

    Always produce result of linking. Produce link information if LTO (link time optimization) verifier fails.  
  
  -discard-value-names 

    Reduce size of generated IR or anonymize artificats 

  -main-file-name somefile.c

    Store info about original input file. 

  -mrelocation-model MODE

    Control trade-off between performance and flexibility 

    MODE Options:

      - Static
        
        - Used for shared libraries 

        - Typical used on embddeded Systems
      
      - PIC (Poisition Independant Code)

        - Generated code run at any memory address 

        - Use for shared libraries 

      - Dynamic

        - Used for dynamic linking
        
        - Rarely Used
      
      - Read Only Position Independence

        - Used for embedded systems for fine grained control 
  
      M-Relocation Model is concept used in facility location or logistics. It involves reassigning resources or services to minimize costs

  -pic-level

    Optimize code based on runtime behavior 

  -mframe-pointer=all

    mframe is a frame pointer pointer. Modern compilers omit frame pointers for optimization 
  
  -fno-strict-return

    Compiler disable optimizations which mask strict return type rule

  -ffp-contract

    Compiler enable floating point contraction 

  -fno-rounding-math

    Disables potentially unsafe or unportable optimization related to rounding and floating point. Compiler will always round-to-nearest set forth by program.  
  
  -funwind-tables

    Compiler generates unwinding tables used by debugging tools like gdb 

  -target-sdk-version

    Compiler sets target sdk version

  -fvisibility-inlines-hidden-static-local-var 
    ...

  -target-cpu  

    Generate code for cpu-type 

  -debug-info-kind=standalone 

    Generate standalone debug information 

  -dwarf-version

    Dwarf is a debugging file format; with clang it provides efficient debugging and analysis 

  -debugger-tuning

    Compiler sets tuning debugger 

  -target-linker

    Compiler sets linker version 

  -fcoverage-compilation-dir

    Compiler sets compilation directory to embed in the coverage mapping 

  -resource-dir 

    Compiler sets directory for clang headers and runtime libraries 

  -I

    Compiler sets path to custom or external header files 

  -internal-isystem 

    Compiler sets directory used to search system header files 

  -internal-externc-isystem

    Compiler sets directory used to search for C system header files used when integrating with C++ 

  -Wall

    Compiler enables all warnings messages 

  -Wno-reorder-init-list 

    Suppress warning about compiler reordering initialized lit 

  -Wno-implicit-int-float-conversion 

    Suppress int to float conversion warning

  -Wno-c99-designator 

    ...

  -Wno-final-dtor-non-final-class 

    ...

  -Wno-extra-semi-stmt 

    ...
  
  -Wno-misleading-indentation 

    Suppress code indentation warnings

  -Wno-quoted-include-in-framework-header 

    Suppress warning for double quoted includes

  -Wno-implicit-fallthrough 

    Suppress fallthrough warnings

  -Wno-enum-enum-conversion 

    Suppress warnings when two different enumeration types are applied to am operand 

  -Wno-enum-float-conversion 

    Suppress arithmetic warning when enum and float type are applied to operand

  -Wno-elaborated-enum-base 
  
    Suppress warning if an invalid enum-base is used in an elaborated type specifier 

  -Wno-reserved-identifier 
    
    Suppress warnings when reserved identifiers are used

  -Wno-gnu-folding-constant 

    Suppress warning when compiler converts a constant variable to a constant expression

  -fdebug-compilation-dir

    Compiler sets paths in debug information 
 
  -ferror-limit 

    Compiler stops emitting diagnostics when error limit is reached 

  -stack-protector

    Compiler protects functions vulnerable to buffer overflows 

  -fstack-check 

    compiler performs stack overflow checking 

  -mdarwin-stkchk-strong-link 
    
    ...

  -fblocks

    Compiler supports Apple's Block extension allowing creation of closures 

  -fencode-extended-block-signature 

    Compiler encodes classes and protocols in signature of block descriptors 

  -fregister-global-dtors-with-atexit 

    Compiler registers destructor functions annotated with __attribute((destructor))

  -fgnuc-version

    Compiler sets GNUC and related macros 

  -fmax-type-align=16 

    Compiler sets maximum alignment to enfore on pointers 

  -fcommon

    Compiler will place uninitialized global variables in a common block

  -fcolor-diagnostics

    Compiler enables colored diagnostics 
  
  -clang-vendor-feature

    Compiler sets hardware/platform specific compiler features 

  -fno-odr-hash-protocols 

    Compiler expects all hash protocol functions to meeting ODR(One Definition Rule) requirement

  -D__GCC_HAVE_DWARF2_CFI_ASM

    Compiler sets macro that controls emission of DWARF CFI(Control Flow Directives) to assembler 

------------