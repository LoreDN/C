# 💻 CODE - C
This repository is a collection of libraries for programming in **C**.
<br>
Some libraries work as templates, despite their absence in pure **C**; for each type you want to use this libraries with, it must be used an unic *'library_type.c'* file.<br>
More instructions will be given in the single *'library.h'* file.
<br>
<br>

## ❓ How to use the repo
There is a folder for each library, which contains the *'library.h'* and the *'library.c'* files.<br>
For each library can be found also a *'/assembly'* subfolder for the **Assembly** implemented functions, with a **Makefile**, which will automate the compilation process.

For the libraries that work as templates, the files are divided in the following way:
  - `library.h`: the template simulation.
  - `library_type.h`: the one to include in your code.
  - `library_type.c`: the real **C** library for the given type.
<br>

## 🔻 Optimization to Low-Level (Machine Instructions) 
In order to optimize the libraries, some functions have been implemented directly in **Assembly**; in particular have been used**x86_64** and **RISC-V** Assembly, but it can be different depending on the library.
If a library has been optimized in Assembly, all the necessary info are provided in the corrisponding *'library.h'* file.
<br>
<br>

# 📦 Packages Releases
In order to make as easy as possible to get and use the libraries, the only thing that the user needs to do is to install the wanted *.deb* package.<br>
It can be done with the following **bash** commands:

```bash
# change LIB / PACKAGE with the wanted ones (as myArray / myarray_amd64)

# download the wanted package
wget https://github.com/LoreDN/code-C/releases/download/LIB/PACKAGE.deb

# install the package
sudo dpkg -i PACKAGE.deb

# add the "LDN" subfolder path (one time --- works for all libraries)
echo "/usr/lib/LDN" | sudo tee /etc/ld.so.conf.d/ldn.conf
sudo ldconfig
```

Finally, in order to compile your program using the library, all you have left to do is to add this command to the compilation one:

```bash
# -lLIB indicates the library binary file, you have to change LIB with the wanted one (as myArray)
-L/usr/lib/LDN -lLIB
```

<br>
<br>

## 📖 Contents of the libraries
Here is a list of the libraries which can be found in the repo, everyone in their folder:
<br>

### 1. myArray
A library which allows to work with Arrays; contains usefull functions such as scanning and printing an Array from or to different sources (terminal,file), Sorting Algorithms, use some statistics and maths functions.

```bash
# x86_64 latest
wget https://github.com/LoreDN/code-C/releases/download/myArray/myarray_amd64.deb
sudo dpkg -i myarray_amd64.deb

# RISC-V64 latest
wget https://github.com/LoreDN/code-C/releases/download/myArray/myarray_riscv64.deb
sudo dpkg -i myarray_riscv64.deb
```

### 2. myList
A library which allows to work with Linked-Lists; contains usefull functions such as scanning and printing a Linked-List from or to different sources (terminal,file), operate with Nodes (inserting, deleting), sort a Linked-List.

```bash
# x86_64 latest
wget https://github.com/LoreDN/code-C/releases/download/myList/mylist_amd64.deb
sudo dpkg -i mylist_amd64.deb

# RISC-V64 latest
wget https://github.com/LoreDN/code-C/releases/download/myList/mylist_riscv64.deb
sudo dpkg -i mylist_riscv64.deb
```