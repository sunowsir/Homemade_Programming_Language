# Homemade_Programming_Language
>   Use 'antlr' to generate a syntax tree, a self-made programming language



## Environmental configuration

1. Please configure the java environment yourself.
2. install antlr C library
    ```bash
      wget http://www.antlr3.org/download/C/libantlr3c-3.4.tar.gz
      tar -xzvf ./libantlr3c-3.4.tar.gz
      ./configure --enable-64bit
      make
      sudo make install
    ```



## Generation interpreter

``` bash
# Go to the 'build' directory
cd build

# Run 'antlr' to generate the syntax tree code via the grammar file ('ExprCppTree.g')
make genTree

# Generate an interpreter by compiling
make 

# install program to system '/usr/bin/'
make install 
```





