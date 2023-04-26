# Linux Commands

This is a list of the most commonly used Linux commands and their usage.

## 1. ls

**Syntax** : `ls [options] [directory]`

**Usage** : `ls` is used to list the contents of a directory. It can be used to list the contents of the current directory or any other directory.

**Commands Used**:

```bash
ls # list the contents of the current directory
ls -l # list the contents of the current directory in long format
ls -a # list the contents of the current directory including hidden files
ls -la # list the contents of the current directory in long format including hidden files
```

## 2. cd

**Syntax** : `cd [directory]`

**Usage** : `cd` is used to change the current working directory. It can be used to change the current working directory to the home directory or any other directory.

**Commands Used**:

```bash
cd # change the current working directory to the home directory
cd / # change the current working directory to the root directory
cd /home # change the current working directory to the home directory
cd Documents # change the current working directory to the Documents directory of the user
cd .. # change the current working directory to the parent directory
cd ../.. # change the current working directory to the grandparent directory
```

## 3. grep

**Syntax** : `grep [options] pattern [file]`

**Usage** : `grep` is used to search for a pattern in a file. It can be used to search for a pattern in a file or in the output of a command.

**Commands Used**:

=> _replace `pattern` like: "abc" and `file` like: note.txt_

```bash
grep pattern file # search for a pattern in a file
grep pattern file1 file2 # search for a pattern in multiple files
grep pattern file1 file2 | grep pattern # search for a pattern in multiple files and then search for another pattern in the output of the first grep command
grep -i pattern file # search for a pattern in a file ignoring the case
grep -v pattern file # search for a pattern in a file and print all the lines that do not match the pattern
grep -c pattern file # search for a pattern in a file and print the number of lines that match the pattern
grep -n pattern file # search for a pattern in a file and print the line numbers of the lines that match the pattern
grep -l pattern file1 file2 # search for a pattern in multiple files and print the names of the files that contain the pattern
grep -r pattern directory # search for a pattern in all the files in a directory and its subdirectories
grep -w pattern file # search for a pattern in a file and print only the lines that contain the pattern as a word
grep -x pattern file # search for a pattern in a file and print only the lines that contain the pattern as a line
grep -E pattern file # search for a pattern in a file using extended regular expressions
grep -F pattern file # search for a pattern in a file using fixed strings
grep -A n pattern file # search for a pattern in a file and print n lines of context after the matching lines
grep -B n pattern file # search for a pattern in a file and print n lines of context before the matching lines
grep -C n pattern file # search for a pattern in a file and print n lines of context before and after the matching lines
```

## 4. su/ sudo

**Syntax** : `su [options] [username]` or `sudo [options] command`

**Usage** : `su` is used to switch to another user. It can be used to switch to the root user or any other user.

`sudo` is used to execute a command as another user. It can be used to execute a command as the root user or any other user.

_replace `username` like: sam_

```bash
su # switch to the root user
su - # switch to the root user and start a new shell
su - username # switch to the user with the username and start a new shell
su username # switch to the user with the username
```

```bash
sudo command # execute a command as the root user
sudo -u username command # execute a command as the user with the username
```

## 5. pwd

**Syntax** : `pwd`

**Usage**: `pwd` is used to print the current working directory.

**Commands Used**:

```bash
pwd # print the current working directory
```

## 6. mv

**Syntax** : `mv [options] source destination`

**Usage** : `mv` is used to move or rename a file or directory. It can be used to move or rename a file or directory in the same directory or in a different directory.

**Commands Used**:

```bash
mv file1 file2 # rename the file1 to file2
mv file1 file2 directory # move the file1 to the directory and rename it to file2
mv file1 directory # move the file1 to the directory
```

## 7. cp

**Syntax** : `cp [options] source destination`

**Usage** : `cp` is used to copy a file or directory. It can be used to copy a file or directory in the same directory or in a different directory.

**Commands Used**:

```bash
cp file1 file2 # copy the file1 to file2
cp file1 file2 directory # copy the file1 to the directory and rename it to file2
cp file1 directory # copy the file1 to the directory
```

## 8. rm

**Syntax** : `rm [options] file`

**Usage** : `rm` is used to remove a file or directory. It can be used to remove a file or directory in the same directory or in a different directory.

**Commands Used**:

```bash
rm file # remove the file
rm -r directory # remove the directory and all its contents
rm -f file # remove the file without prompting for confirmation
rm -rf directory # remove the directory and all its contents without prompting for confirmation
```

## 9. mkdir

**Syntax** : `mkdir [options] directory`

**Usage** : `mkdir` is used to create a directory.

**Commands Used**:

```bash
mkdir directory # create the directory
```

## 10. rmdir

**Syntax** : `rmdir [options] directory`

**Usage** : `rmdir` is used to remove a directory.

**Commands Used**:

```bash
rmdir directory # remove the directory
```

## 11. chmod

**Syntax** : `chmod [options] permissions file`

**Usage** : `chmod` is used to change the permissions of a file or directory.

**Commands Used**:

```bash
chmod u+x file # add the execute permission to the user
chmod u-x file # remove the execute permission from the user
chmod u=rwx file # set the permissions of the user to read, write and execute
chmod u=rw file # set the permissions of the user to read and write
chmod u=r file # set the permissions of the user to read
chmod u=w file # set the permissions of the user to write
chmod u=x file # set the permissions of the user to execute
chmod u= file # remove all the permissions of the user
chmod g+x file # add the execute permission to the group
```

## 12. cat

**Syntax** : `cat [options] file1 file2`

**Usage** : `cat` is used to concatenate files and print on the standard output.

**Commands Used**:

```bash
cat file1 file2 # print the contents of file1 and file2
cat file1 file2 > file3 # print the contents of file1 and file2 and save it to file3
cat file1 file2 >> file3 # print the contents of file1 and file2 and append it to file3
```

## 13. chown

**Syntax** : `chown [options] username file`

**Usage** : `chown` is used to change the owner of a file or directory.

**Commands Used**:

```bash
chown username file # change the owner of the file to the user with the username
chown username:group file # change the owner of the file to the user with the username and the group of the file to the group with the groupname
```

## 14. echo

**Syntax** : `echo [options] string`

**Usage** : `echo` is used to display a line of text/string.

**Commands Used**:

```bash
echo "Hello World" # display the string Hello World
```

## 15. wc

**Syntax** : `wc [options] file`

**Usage** : `wc` is used to count the number of lines, words, and bytes in a file.

**Commands Used**:

```bash
wc file # count the number of lines, words, and bytes in the file
wc -l file # count the number of lines in the file
wc -w file # count the number of words in the file
wc -c file # count the number of bytes in the file
```

## 16. man

**Syntax** : `man [options] command`

**Usage** : `man` is used to display the user manual of any command that we can run on the terminal.

**Commands Used**:

It provides a detailed view of the command which includes NAME, SYNOPSIS, DESCRIPTION, OPTIONS, EXIT STATUS, RETURN VALUES, ERRORS, FILES, VERSIONS, EXAMPLES, AUTHORS and SEE ALSO.

## 17. history

**Syntax** : `history [options]`

**Usage** : `history` is used to print the history of commands.

**Commands Used**:

```bash
history # print the history of commands
history | grep command # print the history of commands that contain the command
```

## 18. clear

**Syntax** : `clear`

**Usage** : `clear` is used to clear the terminal screen.

**Commands Used**:

```bash
clear # clear the terminal screen
```

## 19. touch

**Syntax** : `touch [options] file`

**Usage** : `touch` is used to create a file.

**Commands Used**:

```bash
touch file # create the file
```

## 20. locate

**Syntax** : `locate [options] file`

**Usage** : `locate` is used to find the location of a file or directory.

**Commands Used**:

```bash
locate file # find the location of the file
```

## 21. netstat

**Syntax** : `netstat [options]`

**Usage** : `netstat` is used to display network connections, routing tables, interface statistics, masquerade connections, and multicast memberships.

**Commands Used**:

```bash
netstat # display network connections, routing tables, interface statistics, masquerade connections, and multicast memberships
netstat -t # display TCP connections
netstat -u # display UDP connections
netstat -l # display listening sockets
```

## 22. df

**Syntax** : `df [options]`

**Usage** : `df` is used to display the amount of disk space available on the file system.

**Commands Used**:

```bash
df # display the amount of disk space available on the file system
df -h # display the amount of disk space available on the file system in human readable format
```

## 23. du

**Syntax** : `du [options]`

**Usage** : `du` is used to estimate file space usage.

**Commands Used**:

```bash
du # estimate file space usage
du -h # estimate file space usage in human readable format
```

## 24. uname

**Syntax** : `uname [options]`

**Usage** : `uname` is used to print certain system information.

**Commands Used**:

```bash
uname # print certain system information
uname -a # print all system information
```

## 25. passwd

**Syntax** : `passwd [options]`

**Usage** : `passwd` is used to change the password of a user.

**Commands Used**:

```bash
passwd # change the password of the current user
passwd username # change the password of the user with the username
```

## 26. useradd

**Syntax** : `useradd [options] username`

**Usage** : `useradd` is used to add a new user to the system.

**Commands Used**:

```bash
useradd username # add a new user with the username to the system
```

## 27. userdel

**Syntax** : `userdel [options] username`

**Usage** : `userdel` is used to delete a user from the system.

**Commands Used**:

```bash
userdel username # delete the user with the username from the system
```

## 28. apt-get

**Syntax** : `apt-get [options]`

**Usage** : `apt-get` is used to install, remove, and update software packages on Debian based systems.

**Commands Used**:

=> _replace "package" with the name of the package you want to install, remove, or update_

_eg: "vim", "git"_

**Note**: You may need to add sudo before the commands.

```bash
apt-get install package # install the package
apt-get remove package # remove the package
apt-get update # update the package list
apt-get upgrade # upgrade the packages
```

## 29. ping

**Syntax** : `ping [options] hostname`

**Usage** : `ping` is used to test the reachability of a host on an Internet Protocol (IP) network.

**Commands Used**:

_`hostname` is the name of the host to be pinged_
_eg: "www.google.com"_

```bash
ping hostname # test the reachability of the host with the hostname
```

## 30. find

**Syntax** : `find [options] path`

**Usage** : `find` is used to search for files in a directory hierarchy.

**Commands Used**:

```bash
find path -name "file" # search for the file in the path
find path -type f # search for the files in the path
find path -type d # search for the directories in the path
```

## 31. head

**Syntax** : `head [options] file`

**Usage** : `head` is used to output the first part of files.

**Commands Used**:

```bash
head file # output the first 10 lines of the file
head -n 5 file # output the first 5 lines of the file
```

## 32. rename

**Syntax** : `rename [options]`

**Usage** : `rename` is used to rename multiple files.

**Commands Used**:

```bash
rename 's/old/new/' * # rename all the files in the current directory that contain the old string with the new string
```

## 33. tail

**Syntax** : `tail [options] file`

**Usage** : `tail` is used to output the last part of files.

**Commands Used**:

```bash
tail file # output the last 10 lines of the file
tail -n 5 file # output the last 5 lines of the file
```

## 34. tac

**Syntax** : `tac [options] file`

**Usage** : `tac` is used to concatenate and print files in reverse.

**Commands Used**:

```bash
tac file # concatenate and print the file in reverse
```

## 35. comm

**Syntax** : `comm [options] file1 file2`

**Usage** : `comm` is used to compare two sorted files line by line.

**Commands Used**:

```bash
comm file1 file2 # compare the file1 and file2 line by line
```

## 36. cut

**Syntax** : `cut [options] file`

**Usage** : `cut` is used to remove sections from each line of files.

**Commands Used**:

```bash
cut -d "delimiter" -f "field" file # remove the field from the file using the delimiter
```

## 37. sort

**Syntax** : `sort [options] file`

**Usage** : `sort` is used to sort lines of text files.

**Commands Used**:

```bash
sort file # sort the lines of the file
sort -r file # sort the lines of the file in reverse
sort -n file # sort the lines of the file numerically
```

## 38. date

**Syntax** : `date [options]`

**Usage** : `date` is used to display or set the system date and time.

**Commands Used**:

```bash
date # display the current date and time
date -s "date" # set the date and time
```

## 39. cal

**Syntax** : `cal [options]`

**Usage** : `cal` is used to display a calendar and the date of Easter.

**Commands Used**:

```bash
cal # display the calendar
cal 2019 # display the calendar of the year 2019
```

## 40. time

**Syntax** : `time [options] command`

**Usage** : `time` is used to execute a command and display the time it took to run.

**Commands Used**:

```bash
time command # execute the command and display the time it took to run
```

## 41. host

**Syntax** : `host [options] hostname`

**Usage** : `host` is used to look up the IP address of a host.

**Commands Used**:

```bash
host hostname # look up the IP address of the host with the hostname
```

## 42. wget

**Syntax** : `wget [options] url`

**Usage** : `wget` is used to download files from the web.

**Commands Used**:

```bash
wget url # download the file from the url
```

## 43. id

**Syntax** : `id [options]`

**Usage** : `id` is used to print real and effective user and group IDs.

**Commands Used**:

```bash
id # print the real and effective user and group IDs
```

## 44. ps

**Syntax** : `ps [options]`

**Usage** : `ps` is used to report a snapshot of the current processes.

**Commands Used**:

```bash
ps # report a snapshot of the current processes
```

## 45. top

**Syntax** : `top [options]`

**Usage** : `top` is used to display Linux processes.

**Commands Used**:

```bash
top # display the Linux processes
```

## 46. kill

**Syntax** : `kill [options] pid`

**Usage** : `kill` is used to send a signal to a process.

**Commands Used**:

```bash
kill pid # send a signal to the process with the pid
```

## 47. pkill

**Syntax** : `pkill [options] process`

**Usage** : `pkill` is used to send a signal to a process.

**Commands Used**:

```bash
pkill process # send a signal to the process
```

## 48. killall

**Syntax** : `killall [options] process`

**Usage** : `killall` is used to send a signal to a process.

**Commands Used**:

```bash
killall process # send a signal to the process
```

## 49. bg

**Syntax** : `bg [options]`

**Usage** : `bg` is used to resume suspended jobs in the background.

**Commands Used**:

```bash
bg # resume suspended jobs in the background
```

## 50. fg

**Syntax** : `fg [options]`

**Usage** : `fg` is used to resume suspended jobs in the foreground.

**Commands Used**:

```bash
fg # resume suspended jobs in the foreground
```

## 51. tar

**Syntax** : `tar [options] file`

**Usage** : `tar` is used to create, extract, or list files from a tar archive.

**Commands Used**:

```bash
tar -cvf file.tar file # create a tar archive
tar -xvf file.tar # extract a tar archive
tar -tvf file.tar # list the contents of a tar archive
```

## 52. gzip

**Syntax** : `gzip [options] file`

**Usage** : `gzip` is used to compress or expand files.

**Commands Used**:

```bash
gzip file # compress the file
gzip -d file.gz # expand the file
```
