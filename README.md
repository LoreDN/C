# :computer: CODE - C
This repository is a collection of libraries for programming in <strong>C</strong>.
<br>
Some libraries work as templates, despite their absence in pure <strong>C</strong>; for each type you want to use this libraries with, it must be used an unic <em>'library.c'</em> file.<br>
More instructions will be given in the single <em>'library.h'</em> file.
<br>
<br>

## :question: How to use the repo
The repo is diveded in the following subfolders:<br>
  - <strong>libraries :file_folder: :</strong> this is the core of the repo, in which are collected all the <em>'library.h'</em> files, as well as the corresponding <em>'library.c'</em> ones. 
    All the libraries are open source, and they start with a brief explanation of how to use them.
  - <strong>functions :heavy_check_mark: :</strong> in this folder can be found all the single functions used in the libraries, everyone in a <em>'function.c'</em> ( or <em>'function.S'</em> ) file.
<br>

For the libraries that work as templates, the files are divided in the following way:<br>
  - <em>'library.h'</em> file: the template simulation.
  - <em>'library_type.h'</em> file: the one to include in your code.
  - <em>'library_type.c'</em> file: the real <strong>C</strong> library for the given type.
<br>

## :small_red_triangle_down: Optimization to Low-Level (Machine Instructions) 
In order to optimize the libraries, some functions have been implemented directly in <strong>Assembly</strong>; in particular have been used <strong>x86_64</strong> and <strong>RISC-V</strong> Assembly, but it can be different depending from the library.
If a library has been optimized in Assembly, all the needed info are given in the corrispective <em>'library.h'</em> file.
<br>
<br>

## :open_book: Contents of the libraries
Here is a list of the libraries wich can be found in the repo, everyone in their subfolder:
### 1. <strong>myArray</strong>
>a simple library wich allows to work with arrays, such as scanning and printing an array from or to different sources (terminal,file), sorting an array, use some statistics and maths functions.