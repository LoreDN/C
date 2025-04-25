# :computer: CODE - C
This repository is a collection of libraries for programming in <b>C</b>.
<br>
Every library works as a template, but since in pure C there are no templates, for each type you want to use the library with, it must be used an unic <i>'library.c'</i> file. 
More instruction will be given in the single <i>'library.h'</i> file.
<br>
<br>

## :question: How to use the repo
The repo is diveded in the following subfolders:<br>
  - <b>libraries :file_folder: :</b> this is the core of the repo, in which are collected all the <i>'library.h'</i> files, as well as the corrispective <i>'library.c'</i> ones. 
    All the libraries are open source, and they start with a brief explanation of how to use them.
  - <b>functions :heavy_check_mark: :</b> in this folder can be found all the single functions used in the libraries, everyone in a <i>'function.c'</i> (or <i>'function.S'</i>) file.
  <br>
Since the libraries work as templates, the files are divided in: a <i>'library.h'</i> file, the template simulation, a <i>'library_type.h'</i> file, the one to include in your code, a <i>'library_type.c'</i> file, the real <b>C</b> library for the given type.
<br>
<br>

## :small_red_triangle_down: Optimization to Low-Level (Machine Instructions) 
In order to optimize the library, some functions have been implemented directly in <b>Assembly</b>; in particular have been used <b>x86_64</b> and <b>RISC-V</b> Assembly, but it can vary for each library.
If a library has been optimized in Assembly, all the needed info are given in the corrispective <i>'library.h'</i> file.

## :open_book: Contents of the libraries
Here is a list of the libraries wich can be found in the repo, everyone in their subfolder:<br>
### 1. <b>myArray</b>
>a simple library wich allows to work with arrays, such as scanning and printing an array from or to different sources (terminal,file), sorting an array, use some statistics and maths functions.