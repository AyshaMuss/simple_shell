# 0x16. C - Simple Shell group project by 


General
Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?
Requirements
General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded

More Info
Output
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
Example of error with sh:

$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
Same error with your program hsh:

$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$

List of allowed functions and system calls
* ```access``` (```man 2 access```)
* ```chdir``` (```man 2 chdir```)
* ```close``` (```man 2 close```)
* ```closedir``` (```man 3 closedir```)
* ```execve``` (```man 2 execve```)
* ```exit``` (```man 3 exit```)
* ```exit``` (```man 2 _exit```)
* ```fflush``` (```man 3 fflush```)
* ```fork``` (```man 2 fork```)
* ```free``` (```man 3 free```)
* ```getcwd``` (```man 3 getcwd```)
* ```getline``` (```man 3 getline```)
* ```getpid``` (```man 2 getpid```)
* ```isatty``` (```man 3 isatty```)
* ```kill``` (```man 2 kill```)
* ```malloc``` (```man 3 malloc```)
* ```open``` (```man 2 open```)
* ```opendir``` (```man 3 opendir```)
* ```perror``` (```man 3 perror```)
* ```read``` (```man 2 read```)
* ```readdir``` (```man 3 readdir```)
* ```signal``` (```man 2 signal```)
* ```stat``` (```xstat```) (```man 2 stat```)
* ```lstat``` (```lxstat```) (```man 2 lstat```)
* ```fstat``` (```fxstat```) (```man 2 fstat```)
* ```strtok``` (```man 3 strtok```)
* ```wait``` (```man 2 wait```)
* ```waitpid``` (```man 2 waitpid```)
* ```wait3``` (```man 2 wait3```)
* ```wait4``` (```man 2 wait4```)
* ```write``` (```man 2 write```)

# ```Compilation```
our shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Testing
Your shell should work like this in interactive mode:

```$ ./hsh```
```($) /bin/ls```
hsh main.c shell.c
```($)```
```($) exit```
```$```

# But also in non-interactive mode:

```$ echo "/bin/ls" | ./hsh```
```hsh main.c shell.c test_ls_2```
```$```
```$ cat test_ls_2```
```/bin/ls
/bin/ls```
```$```
```$ cat test_ls_2 | ./hsh```
```hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2```
```$```

Tasks
0. README, man, AUTHORS
mandatory
Write a README
Write a man for your shell.
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker
Repo:

GitHub repository: simple_shell
File: README.md, man_1_simple_shell, AUTHORS
  
1. Betty would be proud
mandatory
Score: 0.00% (Checks completed: 0.00%)
Write a beautiful code that passes the Betty checks

Repo:

GitHub repository: simple_shell
    
2. Simple shell 0.1
mandatory
Score: 0.00% (Checks completed: 0.00%)
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
julien@ubuntu:~/shell$ ./shell 
#cisfun$ ls
./shell: No such file or directory
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ /bin/ls -l
./shell: No such file or directory
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#cisfun$ exit
./shell: No such file or directory
#cisfun$ ^C
julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
#cisfun$ barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ julien@ubuntu:~/shell$
Repo:

GitHub repository: simple_shell
    
3. Simple shell 0.2
mandatory
Score: 0.00% (Checks completed: 0.00%)
Simple shell 0.1 +

Handle command lines with arguments
Repo:

GitHub repository: simple_shell
    
4. Simple shell 0.3
mandatory
Score: 0.00% (Checks completed: 0.00%)
Simple shell 0.2 +

Handle the PATH
fork must not be called if the command doesn’t exist
julien@ubuntu:~/shell$ ./shell_0.3
:) /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls -l /tmp 
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
:) ^C
julien@ubuntu:~/shell$ 
Repo:

GitHub repository: simple_shell
    
5. Simple shell 0.4
mandatory
Score: 0.00% (Checks completed: 0.00%)
Simple shell 0.3 +

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
Repo:

GitHub repository: simple_shell
    
6. Simple shell 1.0
mandatory
Score: 0.00% (Checks completed: 0.00%)
Simple shell 0.4 +

Implement the env built-in, that prints the current environment
julien@ubuntu:~/shell$ ./simple_shell
$ env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$ exit
julien@ubuntu:~/shell$ 
Repo:

GitHub repository: simple_shell
    
7. What happens when you type `ls -l *.c` in the shell
mandatory
Write a blog post describing step by step what happens when you type ls -l *.c and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).

Have at least one picture, at the top of the blog post
Publish your blog post on Medium or LinkedIn
Share your blog post at least on LinkedIn
Only one blog post by team
The blog post must be done and published before the first deadline (it will be part of the manual review)
Please, remember that these blogs must be written in English to further your technical ability in a variety of settings
When done, please add all urls below (blog post, LinkedIn post, etc.)

Add URLs here:

  
8. Test suite
#advanced
Contribute to a test suite for your shell.

This is a task shared by everyone in the class.

Every team (who contributed) will get the same score for this task (The repository owner will not get more points)
You have to be pro-active and agree on one and unique repository to use for the test suite
Please provide the link to the repository you contributed to
Your contribution must be relevant (Correcting typos is nice and always appreciated on the open source sphere, but we won’t consider this a contribution at this point, unless it fixes a bug)
Guidelines for your test suite repository:

The test suite should cover every tasks from 0. to 20.
The test suite should cover every regular cases (many different examples) and possible edge cases
The entire class should work on the same test suite. Use only one repository (don’t forget the README.md file)
Start adding tests ASAP and not just before the deadline in order to help everyone from day 0
You can take (or fork) inspiration from this example, but it is not mandatory to follow this format/way
Adopt a style and be consistent. You can, for example, follow this style guide. If you choose a style that already exists, add it to the README.md in a style section. If you write your own, create a Wiki page attached to the project and refer to it in the README.md style section.
If you choose to use this code, make sure to update the style accordingly
You should have an AUTHORS file, listing all individuals having contributed content to the repository. Format, see Docker
Go teams!

Add URLs here:

  
9. Simple shell 0.1.1
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 0.1 +

Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline
You don’t have to:

be able to move the cursor
Repo:

GitHub repository: simple_shell
    
10. Simple shell 0.2.1
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 0.2 +

You are not allowed to use strtok
Repo:

GitHub repository: simple_shell
    
11. Simple shell 0.4.1
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 0.4 +

handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell
julien@ubuntu:~/shell$ ./shell_0.4.1
$ exit 98
julien@ubuntu:~/shell$ echo $?
98
julien@ubuntu:~/shell$ 
Repo:

GitHub repository: simple_shell
    
12. Simple shell 0.4.2
#advanced
Simple shell 0.4 +

Handle Ctrl+C: your shell should not quit when the user inputs ^C
man 2 signal.

julien@ubuntu:~/shell$ ./shell_0.4.2
$ ^C
$ ^C
$ ^C
$ ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  snap  spool  tmp
$ ^C
$ ^C
$ ^C
$ exit
julien@ubuntu:~/shell$ 
Repo:

GitHub repository: simple_shell
  
13. setenv, unsetenv
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 1.0 +

Implement the setenv and unsetenv builtin commands

setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure
unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure
Repo:

GitHub repository: simple_shell
    
14. cd
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 1.0 +

Implement the builtin command cd:

Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
If no argument is given to cd the command must be interpreted like cd $HOME
You have to handle the command cd -
You have to update the environment variable PWD when you change directory
man chdir, man getcwd

Repo:

GitHub repository: simple_shell
    
15. ;
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 1.0 +

Handle the commands separator ;
alex@~$ ls /var ; ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
alex@~$ ls /hbtn ; ls /var
ls: cannot access /hbtn: No such file or directory
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
alex@~$ ls /var ; ls /hbtn
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
ls: cannot access /hbtn: No such file or directory
alex@~$ ls /var ; ls /hbtn ; ls /var ; ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
ls: cannot access /hbtn: No such file or directory
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
alex@~$
Repo:

GitHub repository: simple_shell
    
16. && and ||
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 1.0 +

Handle the && and || shell logical operators
alex@~$ ls /var && ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
alex@~$ ls /hbtn && ls /var
ls: cannot access /hbtn: No such file or directory
alex@~$ ls /var && ls /var && ls /var && ls /hbtn
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
ls: cannot access /hbtn: No such file or directory
alex@~$ ls /var && ls /var && ls /var && ls /hbtn && ls /hbtn
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
ls: cannot access /hbtn: No such file or directory
alex@~$
alex@~$ ls /var || ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
alex@~$ ls /hbtn || ls /var
ls: cannot access /hbtn: No such file or directory
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
alex@~$ ls /hbtn || ls /hbtn || ls /hbtn || ls /var
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
alex@~$ ls /hbtn || ls /hbtn || ls /hbtn || ls /var || ls /var
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
alex@~$
Repo:

GitHub repository: simple_shell
    
17. alias
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 1.0 +

Implement the alias builtin command
Usage: alias [name[='value'] ...]
alias: Prints a list of all aliases, one per line, in the form name='value'
alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value
Repo:

GitHub repository: simple_shell
    
18. Variables
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 1.0 +

Handle variables replacement
Handle the $? variable
Handle the $$ variable
julien@ubuntu:~/shell$ ./hsh
$ ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  snap  spool  tmp
$ echo $?
0
$ echo $$
5104
$ echo $PATH
/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
$ exit 
julien@ubuntu:~/shell$ 
Repo:

GitHub repository: simple_shell
    
19. Comments
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 1.0 +

Handle comments (#)
julien@ubuntu:~/shell$ sh
$ echo $$ # ls -la
5114
$ exit
julien@ubuntu:~/shell$ 
Repo:

GitHub repository: simple_shell
    
20. help
#advanced
Simple shell 1.0 +

Implement the help built-in
Usage: help [BUILTIN]
Repo:

GitHub repository: simple_shell
  
21. history
#advanced
Simple shell 1.0 +

Implement the history built-in, without any argument
The history built-in displays the history list, one command by line, preceded with line numbers (starting at 0)
On exit, write the entire history, without line numbers, to a file named .simple_shell_history in the directory $HOME
When the shell starts, read the file .simple_shell_history in the directory $HOME if it exists, and set the first line number to the total number of lines in the file modulo 4096
Repo:

GitHub repository: simple_shell
  
22. File as input
#advanced
Score: 0.00% (Checks completed: 0.00%)
Simple shell 1.0 +

Usage: simple_shell [filename]
Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin
Repo:

GitHub repository: simple_shell

## List of functions :page_facing_up:

| Function Name | Description |
|---------------- | -----------|
|[func_exit](https://github.com/AyshaMuss/simple_shell/built-ins.c)    | Exit the shell.|
|[func_printenv](https://github.com/AyshaMuss/simple_shell/blob/master/built-ins.c) | Prints the current environment.|
|[read_input](https://github.com/AyshaMuss/simple_shell/loop_functions.c) | Stores whatever is passed to it as standard input. |
|[sparse_str](https://github.com/AyshaMuss/simple_shell/loop_functions.c) | Devides a string into and array of strings. |
|[execute](https://github.com/AyshaMuss/simple_shell/loop_functions.c) | Executes a command that is passed to it as the first aguement. |
|[prompt](https://github.com/AyshaMuss/simple_shell/loop_functions.c) | Prints '$' and waits for a user's input. |
|[_getenv](https://github.com/AyshaMuss/simple_shell/loop_sub_functions.c) | Provides the value of the environment passed to it as arguement. |
|[_which](https://github.com/AyshaMuss/simple_shell/loop_sub_functions.c) | Identifies the path of the command(\*args) that is being passed. |
|[child_process](https://github.com/AyshaMuss/simple_shell/loop_sub_functions.c) | Executes a command if the path of it is an executable file. |
|[search_func](https://github.com/AyshaMuss/simple_shell/loop_sub_functions.c) | Search directory. |
|[_realloc](https://github.com/AyshaMuss/simple_shell/memory.c) | Reallocates a space in memory. |
|[_count_point](https://github.com/AyshaMuss/simple_shell/memory.c) | Memory buffer. |
|[handle_signal](https://github.com/AyshaMuss/simple_shell/signals.c) | Prints new line and prompt when CTRL + C is passed as input. |
|[_stat](https://github.com/AyshaMuss/simple_shell/signals.c) | Displays file or file system status. |
|[_strstr](https://github.com/AyshaMuss/simple_shell/str_func.c) | Locates a substring. |
|[_strlen](https://github.com/AyshaMuss/simple_shell/str_func.c) | Returns a string. |
|[_strcpy](https://github.com/AyshaMuss/simple_shell/str_func.c) | Copies a string pointed to by src to dest. |
|[_strcat](https://github.com/AyshaMuss/simple_shell/str_func.c) | Concatenates two strings. |
|[_strcmp](https://github.com/AyshaMuss/simple_shell/str_func.c) | Compare two strings. |
|[_strdup](https://github.com/AyshaMuss/simple_shell/str_func_2.c) | Copies a string to another. |
    

## Synopsis :thought_balloon:
This is a humble and simple implementation of a UNIX command line interpreter.

## Description :speech_balloon:
Custom version UNIX command language interpreter built as a project for Holberton School. This mini shell reads commands from either interactive  mode and non-interactive mode.


## Requeriments :bookmark_tabs:

* Allowed editors: ```vi```, ```vim```, ```emacs```
* Programs and functions will be compiled with ```gcc 4.8.4``` using the flags ```-Wall``` ```-Werror``` ```-Wextra``` ```and -pedantic```
* All files should end with a new line
* Code should use the ```Betty``` style. it will be checked using [betty-style.pl](https://github.com/AyshaMuss/simple_shell) and [betty-doc.pl](https://github.com/AyshaMuss/simple_shell)
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to
* Authorized functions and system calls:
  * ```access``` (```man 2 access```)
  * ```chdir``` (```man 2 chdir```)
  * ```close``` (```man 2 close```)
  * ```closedir``` (```man 3 closedir```)
  * ```execve``` (```man 2 execve```)
  * ```exit``` (```man 3 exit```)
  * ```fork``` (```man 2 fork```)
  * ```free``` (```man 3 free```)
  * ```stat``` (```__xstat```)(```man 2 stat```)
  * ```lstat``` (```__lxstat```)(```man 2 lstat```)
  * ```fstat``` (```__fxstat)(```man 2 fstat```)
  * ```getcwd``` (```man 3 getcwd```)
  * ```getline``` (```man 3 getline```)
  * ```kill``` (```man 2 kill```)
  * ```malloc``` (```man 3 malloc```)
  * ```open``` (```man 2 open```)
  * ```opendir``` (```man 3 opendir```)
  * ```perror``` (```man 3 perror```)
  * ```read``` (```man 2 read```)
  * ```readdir``` (```man 3 readdir```)
  * ```signal``` (```man 2 signal```)
  * ```strtok``` (```man 3 strtok```)
  * ```wait``` (```man 2 wait```)
  * ```waitpid``` (```man 2 waitpid```)
  * ```wait3``` (```man 2 wait3```)
  * ```wait4``` (```man 2 wait4```)
  * ```write``` (```man 2 write```)
  * ```_exit``` (```man 2 _exit```)
  * ```isatty``` (```man 3 isatty```)
  * ```fflush``` (```man 3 fflush```)

## Flowchart :pushpin:
Below you can see all the process flow in general terms that was taken into account at the time of making the code. 



## Quick start :runner:
Git clone the repository:

```
git clone https://github.com/AyshaMuss/simple_shell.git 
```

## Usage :computer:
All the files are to be compiled on an Ubuntu 14.04 LTS machine with:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

Once compiled, to start the program, run:
```./hsh```
  
To exit the program, run:
```$ exit```
  



## List of functions :page_facing_up:

| Function Name | Description |
|---------------- | -----------|
|[func_exit](https://github.com/AyshaMuss/simple_shell/blob/master/built-ins.c)    | Exit the shell.|
|[func_printenv](https://github.com/AyshaMuss/simple_shell/blob/master/built-ins.c) | Prints the current environment.|
|[read_input](https://github.com/AyshaMuss/simple_shell/blob/master/loop_functions.c) | Stores whatever is passed to it as standard input. |
|[sparse_str](https://github.com/AyshaMuss/simple_shell/blob/master/loop_functions.c) | Devides a string into and array of strings. |
|[execute](https://github.com/AyshaMuss/simple_shell/blob/master/loop_functions.c) | Executes a command that is passed to it as the first aguement. |
|[prompt](https://github.com/AyshaMuss/simple_shell/blob/master/loop_functions.c) | Prints '$' and waits for a user's input. |
|[_getenv](https://github.com/AyshaMuss/simple_shell/blob/master/loop_sub_functions.c) | Provides the value of the environment passed to it as arguement. |
|[_which](https://github.com/AyshaMuss/simple_shell/blob/master/loop_sub_functions.c) | Identifies the path of the command(\*args) that is being passed. |
|[child_process](https://github.com/AyshaMuss/simple_shell/blob/master/loop_sub_functions.c) | Executes a command if the path of it is an executable file. |
|[search_func](https://github.com/AyshaMuss/simple_shell/blob/master/loop_sub_functions.c) | Search directory. |
|[_realloc](https://github.com/AyshaMuss/simple_shell/blob/master/memory.c) | Reallocates a space in memory. |
|[_count_point](https://github.com/AyshaMuss/simple_shell/blob/master/memory.c) | Memory buffer. |
|[handle_signal](https://github.com/AyshaMuss/simple_shell/blob/master/signals.c) | Prints new line and prompt when CTRL + C is passed as input. |
|[_stat](https://github.com/AyshaMuss/simple_shell/blob/master/signals.c) | Displays file or file system status. |
|[_strstr](https://github.com/AyshaMuss/simple_shell/blob/master/str_func.c) | Locates a substring. |
|[_strlen](https://github.com/AyshaMuss/simple_shell/blob/master/str_func.c) | Returns a string. |
|[_strcpy](https://github.com/AyshaMuss/simple_shell/blob/master/str_func.c) | Copies a string pointed to by src to dest. |
|[_strcat](https://github.com/AyshaMuss/simple_shell/blob/master/str_func.c) | Concatenates two strings. |
|[_strcmp](https://github.com/AyshaMuss/simple_shell/blob/master/str_func.c) | Compare two strings. |
|[_strdup](https://github.com/AyshaMuss/simple_shell/blob/master/str_func_2.c) | Copies a string to another. |

## Authors :
* **Musse Kalil** [Github](https://github.com/AyshaMuss)
* **** [Github](https://github.com/AyshaMuss)
<p align="center">
<img src="http://www.holbertonschool.com/holberton-logo.png" alt="Holberton School logo">
</p>


