# Xrome
A very basic operating system written in **C** and **Assembly**. 

- Note: some assembly files is not written by me.

## Building

You'll need cross-platform compilers like ``x86_64-elf-gbb``, ``x86_64-elf-gcc`` and ``x86_64-elf-ld`` for compiling and linking binaries. You can change the paths of them in "Makefile".

Simply execute
```s
$ make
```
and that's it.

## Running

After building, you can use **qemu** for running rhe binary.

```
$ qemu-system-x86_64 os-image.bin
```

## License
[GNU General Public License v3.0](LICENSE)

## Status
**Development halted. I'm going to develop another OS :D**
