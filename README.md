# Homemade_Programming_Language
Use 'antlr' to generate a syntax tree, a self-made programming language


* Environmental configuration
    1. Please configure the java environment yourself.
    2. install antlr C library
        ```bash
          wget http://www.antlr3.org/download/C/libantlr3c-3.4.tar.gz
          tar -xzvf ./libantlr3c-3.4.tar.gz
          ./configure --enable-64bit
          make
          sudo make install
        ```

* Generation interpreter

    Run the 'Generate_Translater' script in the './3.CC_Program/' directory.

    ```bash
    cd ./3.CC_Program/
    
    # Run 'antlr' to generate the syntax tree code via the grammar file ('2.CC_src/ExprCppTree.g')
    ./Generate_Translater -g
    
    # Generate an interpreter by compiling
    ./Generate_Translater -t
    
    # Parameters can be superimposed 
    # eg.
    ./Generate_Translater -gt
    ```

    
