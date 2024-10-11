#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef PIPEX_H
# define PIPEX_H 

void    ft_error();
void    get_path(char *command, char **envp);
void    parent(char **argv, int pid, char **env);
void    child(char **argv, char **envp, int *pipe);

#endif