/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:45:16 by mavissar          #+#    #+#             */
/*   Updated: 2024/10/10 14:57:27 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    execution(char **argv, char **env)
{
    
}

void    parent(char **argv, int pid, char **env)
{   
    int     fd;
              
}

void    child(char **argv, char **envp, int *fd)
{
    int     file;

    file = open(argv[1], O_RDONLY, 0777);
    if (file == -1)
        ft_printf("Error opening file\n");
        return 1;
    dup2(fd[1], STDOUT_FILENO);
    dup2(file, STDIN_FILENO);
    close(fd[0]);
    execute(argv[2], envp);
    
}

// fd[0] = read from fd
// fd[1] = write from fd 
// always close both cause they re indep of each other 
int     main(int argc, char **argv, char **envp)
{
    pid_t   pid;
    int     fd[2];
    
    if (argc == 5)
    {
        if (pipe(fd) == -1)
            ft_printf("Error openinig pipe\n");
            return 1;
        pid = fork();
        if (pid == -1)
            ft_printf("Fork failed\n");
        if (pid == 0)
            create_child(argv, envp, fd);
        
    }
    else
    {
        ft_printf("");
    }
}
