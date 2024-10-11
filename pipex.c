/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:45:16 by mavissar          #+#    #+#             */
/*   Updated: 2024/10/11 18:50:46 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//dup2(fd[0], STDIN_FILENO):replaces the standard input with the reading end of the pipe.
//This means the parent process will read from the pipe instead of the terminal.
//dup2(fileout, STDOUT_FILENO):replaces the standard output with the opened file,
//meaning any output from the parent process will be written to the specified file.
void    parent(char **argv, char **env, int *pipe)
{   
    int     file;

    file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (file == -1)
        ft_error();
    dup2(pipe[0], STDIN_FILENO);
    dup2(file, STDOUT_FILENO);
    close(pipe[1]);
    execution(argv[3], env);
}

//dup2(pipe[1], STDOUT_FILENO): replaces the standard output with the writing end of the pipe,
//meaning any output from the child process will be sent to the pipe instead of the terminal.
//dup2(file, STDIN_FILENO): replaces the standard input with the opened file,
//allowing the command executed to read from this file instead of the terminal.
void    child(char **argv, char **envp, int *pipe)
{    int     file;

    file = open(argv[1], O_RDONLY, 0777);
    if (file == -1)
        ft_error();
    dup2(pipe[1], STDOUT_FILENO);
    dup2(file, STDIN_FILENO);
    close(pipe[0]);
    execution(argv[2], envp);
    
}

// fd[0] = read from fd
// fd[1] = write from fd 
// always close both cause they re indep of each other 
int     main(int argc, char **argv, char **envp)
{
    pid_t   pid;
    int     pipe[2];
    
    if (argc == 5)
    {
        if (pipe(pipe) == -1)
            ft_error();
            return 1;
        pid = fork();
        if (pid == -1)
            ft_error();
        if (pid == 0)
            child(argv, envp, pipe);
        parent(argv, envp, pipe)
        
    }
   else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
