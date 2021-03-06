# ft_ls - Recreating of the famous "ls" Unix command. 

## Purpose
Knowing the filesystem inside out, and how files and directories are sorted, all whilst coding one of the most used commands among programmers.

## Implemented Options

    - 1 (default):  Force output to be one entry per line.
    - a:            Include directory entries whose names begin with a dot (.)
    - d:            Directories are listed as plain files (not searched recursively).
    - l:            Long listing format.
    - R:            Recursively list subdirectories encountered.
    - r:            Reverse the order of the sort to get reverse lexicographical order or the oldest entries first.
    - t:            Sort by time modified (most recently modified first) before sorting by lexicographical order.
    
## Usage
```
$ git clone https://github.com/PedroNunezCode/ft_ls.git ft_ls_pnunez
$ cd ft_ls_pnunez
$ make
$ ./ft_ls (-flags) (direcories/files)
```
