### About

Batari BASIC v1.9 - a Basic Compiler for the Atari 2600

Copyright 2005-2013 by Fred Quimby

Additional code contributions and fixes by various contributors Copyright 2005-2025

Special thanks to OG contributors who kept the dream of simplified coding on the 2600 alive:
- Bob Montgomery
- Michael Rideout
- David Galloway
- Mike Saarna
- Karl Garrison

### License

**batari Basic** is free of charge and provided under the GPL v2 license. See the included `LICENSE.txt` for more information.

The license does not apply to Atari 2600 games created with Batari BASIC. You may license your games however you wish. Many **batari Basic** games have been published, and are available for sale on cartridge.

### What is batari-Basic?

**batari Basic** (bB) is a BASIC-like language for creating Atari 2600 games. It is a compiled language that runs on a computer, and it creates a binary file that can be run on an Atari 2600 emulator or the binary file may be used to make a cartridge that will operate on a real Atari 2600.

If you find any bugs, please report them via GitHub.

To learn how to use **batari Basic**, please refer to the documentation found at [Random Terrain](//www.randomterrain.com/atari-2600-memories-batari-basic-commands.html) and the sample programs included in this release.

### Getting Started

Download this repository as a ZIP file and extract it to a new directory. The name of the directory doesn't matter, but for consistency with this guide and tutorials, you may wish to use `C:\Atari2600\bB`.

#### MS-DOS/Windows:

Download **batari Basic** as a ZIP file by clicking the `<> CODE` button at the top of this page. Unzip it to any location you want to use. Your unzip utility should create subdirectories (`/docs`, `/includes`, etc.) rather than placing all files in a single directory.

Windows users should double-click the provided `install_win.bat` file and follow the instructions presented.

If `install_win.bat` reports failure, you should manually set the following variables to point at your batari Basic directory:

```bat
set bB=c:\Atari2600\bB
path=%path%;c:\Atari2600\bB
```

This may be done differently depending on your version of Windows. Search the Internet for your required procedure - https://tinyurl.com/yx756dug

Once the environment id ready switch to a folder containing a bB source file and type:

```sh
2600bas filename
```

where _filename_ is the name of the BASIC source file you wish to compile. The project folder can be any folder you create to store your files.

To test your installation, several sample programs are included in the "`Samples`" folder. Change directories to this location and type:

```sh
2600basic.sh sample.bas
```

If successful, a file called `sample.bas.bin` will be generated that you can run on an emulator, or add to a flash cart. The sample program is not very interesting, but note how simple it was to write. Open sample.bas in a text editor and take a look at how it was written.

#### Getting Started with Linux/OS X/other Unixes

This version of **batari Basic** comes bundled with 32-bit and 64-bit binaries for both OS X and Linux. If you wish to run **batari Basic** on a platform other than those ones, you'll need to rebuild the binaries. (Refer to the provided `COMPILE.txt` document)

The rest of this section assumes you understand what directory you saved the **batari Basic** zip file to, how to extract the zip file, how to open a Unix shell, and how to use the "cd" command to move into in directories.

#### batari Basic for Linux or OS X - the Easy Way
1. Download and unzip the **batari Basic** distribution to your home directory, ensuring the directory structure in the zip is maintained. (i.e., there should be "`includes`" and "`samples`" subdirectories.)
2. Open a terminal window, and "cd" to the unzipped **batari Basic** directory.
3. Run the installer and follow the instructions: ./install_ux.sh

#### batari Basic for Linux or OS X - Manual_Installation

1. Download and unzip the **batari Basic** distribution to your home directory, ensuring the directory structure in the zip is maintained. (_i.e._, There should be "`includes`" and "`samples`" subdirectories.)

2. Ensure these two environment variables are set...
   ```sh
   export bB=$HOME/bB.1.2
   export PATH=$bB:$PATH
   ```

   **Substitute the actual location of the unzipped bB distribution on your system in the first line.**

3. Compile your basic program using the 2600basic.sh script.

   _e.g._, `2600basic.sh myprogram.bas`

   It should produce a binary named after the basic program, but ending with the file extension "`.bin`".

   If it doesn't work, ensure you have set the bB and PATH variables correctly.

### How It Works

Similar to other compilers, batari BASIC uses a 4-step compilation process:

1. **Preprocess...**
   The preprocessor takes your Basic code, reformats and tokenizes it so the compiler can understand it. Certain errors can be caught at this stage.

2. **Compile...**
   The compiler converts your Basic code into Assembly Language. It will create a temporary file called bB.asm. The Basic code is preserved as comments in this file so you can easily see which Assembly Language code corresponds to your Basic code.

3. **Link...**
   The linker splits the Basic code into sections if needed, then concatenates them, along with the kernel, modules and compilation directives into a composite assembly language file.

   3a. **Optimize...**
       This optional stage runs a peephole optimizer that looks for redundant and unnecessary code in the composite assembly file.

4. **Assemble...**
   The assembler converts the Assembly Language to a binary file containing the machine code to run on your emulator or real Atari 2600.
