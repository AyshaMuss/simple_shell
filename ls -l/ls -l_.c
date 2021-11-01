The UNIX ls -l Command Explained

The UNIX ls -l command can provide you with detailed information about each file and subdirectory in the current folder. Using this function is equivalent to entering "dir /V" at the Windows command prompt. The ls -l UNIX command reveals seven facts about each item in a directory. Here is an example of its output:

$ ls -l
total 14
lrwxrwxrwx 1 lfl03b users 27 Aug 8 09:59 contacts_work -> datafiles/contacts_work.txt
drwxr-xr-x 2 lfl03b users 2048 Apr 9 15:04 datafiles
-rwxr-xr-x 1 lfl03b users 10130 Apr 9 15:02 demo_ksh_array_shell_script
drwxr-xr-x 2 lfl03b users 2048 Apr 10 09:29 perl5

The word "total" is followed by the number of file system blocks that the directory's files occupy. Each subsequent line supplies details on a single item. The first character specifies the folder or file type. It is a directory if the letter "d" appears. UNIX uses hyphens to identify standard files; various letters denote specialized data files and links.
This identifier is directly followed by a set of nine letters and hyphens. They disclose the item's security permissions. The first three permissions apply to the file's owner, and the next set pertains to members of the owner's group. The final three characters identify access permissions for all other users.

A user or group is allowed to read an item if its permissions contain the letter "r." The letter "w" indicates that someone can modify the file by writing to it. An "x" means that users have permission to run the file if it's an executable program. Hyphens appear when permissions have not been granted.

The next item in each ls -l listing is the number of links. A file typically has one link, but there are more links if it has aliases. The count starts at two for folders because UNIX considers the parent and current directories to be links. This figure includes the number of subdirectories in a folder as well.

The UNIX ls -l command's listings also indicate the owner and group assigned to a file. You can use this data in conjunction with the permission flags to determine what access rights you have. The file size follows the group name; it is measured in bytes. Regardless of how many files it contains, the size of a directory is normally 2,048 bytes.
A calendar date appears after the file size. It may also include the year or a specific time. This is the date when the item was last modified; you will see the creation date if a file has never been changed. Finally, the name of a file or directory appears at the end of each line.

The fourth line of our sample reads "-rwxr-xr-x 1 lfl03b users 10130 Apr 9 15:02 demo_ksh_array_shell_script." This means that the file is part of the "users" group and owned by "lfl03b." It consists of 10,130 bytes and was modified on April 9. Everyone may read or execute this file, but the owner is the only user who can modify it.
There are many reasons to use the ls -l command in UNIX. For example, you might want to determine how long ago you updated a statistic on your website. It also comes in handy when you need to verify that a certain file will fit on an external storage device. This command is useful for reviewing UNIX security settings as well.


The Command Line with ls -l
What happens when you type ls -l on the command line?
There is a command I use a lot and it is ls -l

The -l switch turns on long listing format


<p align="center">
<img src="https://miro.medium.com/max/500/1*egOfhljkOrUTB-grQu6T-w.png" alt="what happens when ls -l is typed">
</p>

Before we answer the question, let’s take a deeper look into the shell. 
What is a shell? A shell is simply, the command line.
 The shell is a program that takes a keyboard command like ls -land passes
 it to the OS (operating system) to carry out. 
The user should understand that the file system resembles a file system tree. 
Files are organized in a tree like shape pattern of directories.
“Unix-like operating system such as Linux organizes its files in what is
called a hierarchical directory structure. (The Linux Command Line, William Shotts)
The shell is a textual representation of the file system on your computer. 
So, a graphical interface in contrast uses icons of folders to represent the files they hold.
The user can double click the folders to gain access to the files.

Graphical user interface (GUI) in a Mac OS
An everyday user like you and I would interact with our computer using a GUI. 
There is also, another way to interact with your computer and that is typing commands like ls -l in the shell.
 The ls -lcommand is the most used bash command. It is a helpful tool that allows navigation around the shell. 
The user interacts with the shell by opening the computer’s terminal.
 The user types in commands to navigate through the file system. The shell waits for the user to invoke a command. 
It waits for you — the pilot. Ultimately, you have the luxury and the power to explore your system in any way that you desire.

A terminal, with the command ls -l typed in the shell.
Don’t be afraid. Don’t let the simplicity fool you either. The command line is a direct interaction with the computer system. 
There are so many commands and tools the user can utilize, which makes the shell a powerful tool.
The simple command of ls -lmeans, to list files and directories. 
It has an option of -l, which lists the contents in a long format like the picture on the left. 
It allows you to look through the file system. When you type commands like ls on a keyboard, the shell — a program executes the commands. 
Remember, it’s how the user interacts with the OS. On most Linux systems, the default shell is called bash.
There’s a lot to unpack there. So, let’s start with answering the question: What happens when you type ls -l on the command line?
Let’s go through the steps:
Type the command, $ls -land hit the enter button on the computer to execute the command.
A new line will attach to the end of ls -l\n
What? Ok… back up.
It’s all in the details. When the command ls -l is entered, the new line \nis cut from the end of the command. 
A null byte, '\0'takes its place and specifies the end of the command. 
The null byte is important because it lets the computer know how many commands and flags to execute.
A powerful function called strtok()parses the command. The command is now a character string that is saved into an array of strings.
 The function separates the lsand -linto their own designated spots. It is concatenated. 
Keep note: the original command of ls and the concatenated string of ls and -l will be saved. This is an important detail.
The PATH
Most bash commands entered by users will come come across the PATH when operating the shell. 
First, before a command enters the path, the shell will check if the command falls under a built in command or an alias. 
If the command follows either case, the computer will push the command to enter another process.
If the command is neither like ls -l, then the command will be compared to the PATH. What is the PATH? 
It is a string of directories and they are separated by colons.
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
What do these directories hold? They hold most of the commands that a user can enter.
When the user types in ls -l, the command goes through the PATH.
It looks for the location of ls in the PATH and the path for this command is /bin/ls.
To search through these directories:

the shell needs to find the correct variable, PATH. 
It is part of the shell’s environment and shell has many variables.
The shell will have to search through the environment’s variables until it finds PATH.
When the PATH is found, it is separated by the strtok ( ) function and it is parsed. 
It will also, search for colons (:) — the directory, instead of spaces.
The PATH and the colons are saved into an array of strings.
Almost done… and time to string compare
The shell now has an array of strings that contains all of PATHs directories. 
Sweet! So, ls should be attached to /bin. 
What does shell do?
It will search through the list of directories.
Append ls to each directory.
Check to see if it exists and if it does, then it executes the command!
In detail, shell goes through the array of strings and 
when it comes across the /, it will concatenate, then ls.
 It will go through a check of each directory’s path to verify if the file exists. 
If the file exists (yay!), it will return the concatenated string, /bin/ls.
Let’s EXECUTE!
Alright, does the shell sound pretty amazing? It gets better. 
So, the shell has been running one process and it’s pretty much doing all the work. 
It will now create an identical child process to execute the ls -l. 
The parent process (the original) will wait 
until the child process is done — whether it will execute the command or return an error message.
The shell now has the full path of the executable file, /bin/ls and now, it will attach the flag, -l. 
The execution is ready to complete and if successful, 
it will display the file contents of the directory in long format. In completion of the process, 
it returns the parent process, which prompts the user to enter another command. 
The return to the prompt allows the user to enter more commands and look around the shell.

What is ls -l?
Ls is the name of a Linux executable file in the /bin directory that when 
executed, lists the visible files in the directory specified as argument. 
However, if no directory is specified, ls lists the files in the current working directory. 
Ls, like most other executable files or commands, has a 
different behavior of execution when a flag is passed to it. 
But you may ask: “What is a flag?”. A flag (usually recognized by its first character “-”)
 is an argument passed to an executable command to change the specification of its output. 
So, to answer the main question; ls -l is a Linux command that will 
list all “visible” files in current directory in long format and sorted in descending and alphabetical order. 
The output of the command would look something like this:

Own elaboration
Also, there are many other flags that change the output of 
the executable command ls and can be combined to acquire a more specific output. Some examples are:

● ls -la: List all files including hidden files                 

● ls -l --color: List file in long format with variations of color

● ls -n: List all “visible” files in long format and with numeric user and group IDs

● ls -nS: Like above but files are sorted in descending order by size

However, sometimes having to write out a command line that does a 
specific thing for you can take some time because you have to remember what argument to use and 
this is where aliases (one of programmers’ best friends) comes into play. First, you should know that 
aliasing is simply accessing a data location in memory with a symbolic name. To put in simple words, 
an alias is like an “a.k.a”; you can execute long and hard to remember command lines with a single word or 
even a letter. So, if you want to shorten a command line “ls -l” into a single word or letter you can 
use the syntax [alias <shortened name>=” command line”]. An example of this would be:

alias l=”ls -l”
In the terminal it would look like this:

Own elaboration
So now that we know what happens when you type “ls -l” into the shell, let's take a look at what 
really happens behind the scenes for this command line to be executed.

 

How is ls -l executed?
1. Print prompt
First, the shell prints a prompt on the standard input. Once again, you may raise the question: “what is a prompt?”. 
A prompt is any symbol that a shell displays when receiving a command line; usually it is a ‘$’. 

Own elaboration
2. Read input from standard input
Secondly, once the prompt ($) is printed, the shell waits for a command to be inputted. 
The command should be from standard input (ie. isatty (STDIN_FILENO)). When the command is typed in, 
the shell allocates memory for it and saves it in an array (contiguous block of memory) to be passed 
to the sparse function. If nothing is inputted, the shell will just wait and do nothing unless 
it receives an input. Also, if nothing is inputted and 
the enter key is pressed, it will simply print a new line with the prompt and wait for an input again.

Own elaboration
3. Sparse input from standard input into tokens
Thirdly, the sparse function receives the array which holds the input from the standard 
input terminal and separates it into more than one array if possible. This is possible because 
the function recognizes that any space between words means that each word is a different array; 
hence separating them into what are called tokens. “How is this done?” you may ask, well there 
is a special function called strtok that separates a string according to a specified delimiter. 
If the specified delimiter is space (“ “), then strtok will make the first token equal to memory 
data up to a space character. The same thing will happen with the word following that first space 
and so on until it encounters the NULL character. The first token is always the command name or an 
executable file. For example, the command line “ls -l” will be separated into two arrays because of 
the space between the words making “ls” the first argument and “-l” the second. 
These separated arguments are then passed to the next function which will find the path of the first 
argument if it is an executable command.

Own elaboration
4. Check for built-ins then PATH
Once the shell has its inputs separated into arguments, it checks to see if the first argument is 
the name of a built-in alias. If that is not true, then it will check to see if it is the name of 
a built-in script; by the way, scripts can also be aliased. Finally, after not finding any coincidence
 in the built-in commands, the shell moves on to the ‘PATH’, where it checks directory by directory to 
see if it can find an executable command that has the same name as argument one.

No hay texto alternativo para esta imagen
Okay, now this is where it gets interesting, once the coincidence is found, whether it be in the built-in 
commands or in the ‘PATH’, the shell checks to see if the ‘found’ file has permissions or access for execution.
 If it does, then it will return the complete path of the file’s location to the next process (fork). 
If it does not have permissions for execution, then the shell will just print something like “Permission denied”. 
If no file is found, then the shell will print something like “File or directory not found”.

5. Fork and execute
Finally, once the shell has the complete path or location of the executable file and access to execute it, 
it will execute the command with any other argument passed to it as “flags”. But this is not as simple as it sounds. 
Why? Because first, the shell creates a fork (child process), which is a copy of the ‘parent’ process, 
making both programs run simultaneously. And here comes the question: “How does that work?”. Well, the parent process
 waits on a signal from the child process indicating that it has terminated. On the other hand, the child process 
executes the command line that was inputted and once it is done, it sends the signal to the father. If the whole 
process is done successfully, then the program will print an output and then go back to step one. 

Own elaboration
If you are a curious human being and you want to know what was meant by isatty when mentioned in the previous 
paragraph, then it is a good thing you are still reading this post.

If you are a curious human being and you want to know what was meant by isatty when mentioned in the previous 
paragraph, then it is a good thing you are still reading this post.

It is important to mention, that file descriptors, or also known as file handlers, according to [2] is a 
small non-negative integer that identifies a file with the kernel.

The following table shows how this is shared for the three specific cases that they are:

Own elaboration


This process within our terminal can be expressed graphically as shown below:

Reference [2]
In view of the above, we can understand that Isatty is simply a system call which when called, returns 
one as a true value for its purpose. Its purpose is to check if a file descriptor refers to a terminal or not. 
Therefore, if a file descriptor refers to terminal, it will return 1. If this fails, it will return a number other than 1. 
This syscall is in the library unistd.h. And the syntax for the system call is as followed:

int isatty(int fd);
Going back to the topic at hand and bearing in mind what was said before, we cannot finish this 
article without mentioning that the "ls -l" command provides us with very detailed information 
about each of the directories and files. Let us go a little deeper into this topic.

 

When talking about permissions, there are three entities or bodies directly associated 
with the files and directories in your system. They are as followed

● Owner: User who owns the file, directory, or symbolic link, usually also the one who created the file.

● Group: Group of users who have some level of access to the file, directory, or symbolic link

● Others: Other users who may or may not have any level of access to the file/directory.

 

Each user has three possible types of permission, also known as “-rwx” and are described as followed:

● r: Stands for read and it is the permission type that allows users to read a file, directory, or symbolic link.

● w: Stands for write and it is the permission type that allows users to edit a file, directory, or symbolic link.

● x: Stands for execute and it is the permission type that allows users to execute a file, directory, or symbolic link. 

● -: Stands for 0 and it is a permission type that prohibits users from reading, writing or executing a file, directory or symbolic link

 Permit types are structured in an octal system and their values are relative, defined in this way:

● Read (r): 4

● Write (w): 2

● Execute (x): 1

● - (none): 0

 

Also, it is important to consider these values when changing the permissions of our files and directories, 
shortly we will see some examples.

 There are also special flags that indicate whether the permission is for a file, directory, or symbolic link. 
These are usually written before the permission types and are represented as followed:

● -: file

● d: directory

● l: symbolic link



Therefore, putting all this information together we can show how all of this would be represented in a diagram 
followed by examples:

Reference [3]
The permissions and ownership of a file, directory or symbolic link can be assigned, changed, or removed with 
several commands. For more information: man chmod and man chown.

Own elaboration


As you can see in the image, we have a series of files and directories by typing in our terminal the 
command “ls- l”. Most of the files have the same permissions, let us go into detail with it:

● The owner has these permissions: rw-, i.e. he can read and write but not execute; this is represented by the 
number: 6. Why? Read (4) + write (2) + (0) = 6.

● The group and the others have these permissions: r--, that is, they can only read the file; this is represented for 
both cases with the number 4. Read (4) + 0 + 0 = 4.

In this way, we can conclude that the files whose permission representation is rw-r--r--, in the octal system is 644. 
The first digit corresponds to the owner, the second to the group and the third to the others.



 Meanwhile, something very curious happens when we analyze the directory that is in this folder. Let us analyze it:

 ● The owner has these permissions: rwx, he has all the permissions, that is, he can read, write, and execute, 
represented by the number: 7. Why? Read (4) + write (2) + execute (1) = 7.

● The group and the others have these permissions: r-x, that is, they can read the file and execute it, but they 
cannot write on it, represented for both cases with the number 4. Read (4) + execute (1) = 5. Read (4) + 0 + execute (1) = 5.

 

We can then conclude that the current directory whose permission representation is d

rwxr-xr-x, in the octal system is 755.

 

Summarizing, first we have covered how the file system is structured in Linux, we mention important aspects 
of the environment variables, specifically the PATH. After that, we understood how the commands were classified 
and in this way, we talked about the command "ls -l" specifically, what it is, what internal processes occur in 
the terminal when we type the command. Finally, we analyzed the information provided by this command referring to 
the structure of the permissions and applying some concrete examples in the terminal.