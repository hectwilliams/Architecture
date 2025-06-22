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

    Warns of undefined identifier prefixed with TARGET_OS is evaluated ( #if directive )

  -Wdeprecated-objc-isa-usage

    Warns about the usage of isa in Objectice-C ( isa is deprecated )

  -Werror 

    Treats all warnings as errors

  -Werror=implicit-function-declaration     

    Warnings of attempted usage of functions not yet declared are treated as errors 

  -emit-obj

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

    control trade-off between performance and flexibility 

    MODE Options:

      - __Static__
        
        - Used for shared libraries 

        - Typical used on embddeded Systems
      
      - __PIC (Poisition Independant Code)__

        - Generated code run at any memory address 

        - Use for shared libraries 

      - __Dynamic__

        - Used for dynamic linking
        
        - Rarely Used
      
      - __Read Only Position Independence__

        - Used for embedded systems for fine grained control 
  
     __M-Relocation Model is concept used in facility location or logistics. It involves reassigning resources or services to minimize costs__

  -pic-level

    Optimize code based on runtime behavior 

  -mframe-pointer=all

    mframe is a frame pointer pointer. Modern compilers omit frame pointers for optimization 
  
  -fno-strict-return

    Disable optimizations which mask strict return type rule

  -ffp-contract=on

    Enable floating point contraction 

  -


------------