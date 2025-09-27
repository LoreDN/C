# 💻 CODE - C
This repository is a collection of libraries for programming in **C**.
<br>
Some libraries work as templates, despite their absence in pure **C**; for each type you want to use this libraries with, it must be used an unic *'library_type.c'* file.<br>
More instructions will be given in the single *'library.h'* file.
<br>
<br>

## ❓ How to use the repo
There is a folder for each library, which contains the *'library.h'* and the *'library.c'* files.<br>
For each library can be found also a *'/assembly'* subfolder for the **Assembly** implemented functions, with a **Makefile**, which will automatize the compilation process.

For the libraries that work as templates, the files are divided in the following way:
  - *'library.h'*: the template simulation.
  - *'library_type.h'*: the one to include in your code.
  - *'library_type.c'*: the real **C** library for the given type.
<br>

## 🔻 Optimization to Low-Level (Machine Instructions) 
In order to optimize the libraries, some functions have been implemented directly in **Assembly**; in particular have been used**x86_64** and **RISC-V** Assembly, but it can be different depending from the library.
If a library has been optimized in Assembly, all the needed info are given in the corrispective *'library.h'* file.
<br>
<br>

## 📖 Contents of the libraries
Here is a list of the libraries wich can be found in the repo, everyone in their folder:
### 1. myArray
>A library wich allows to work with arrays; contains usefull functions such as scanning and printing an array from or to different sources (terminal,file), sorting an array, use some statistics and maths functions.
### 2. myList
>A library wich allows to work with Linked-Lists; contains usefull functions such as scanning and printing a List from or to different sources (terminal,file), operate with Nodes (inserting, deleting), ordinate a Linked-List.
