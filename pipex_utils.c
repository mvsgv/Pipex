/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:01:26 by mavissar          #+#    #+#             */
/*   Updated: 2024/10/11 21:49:31 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_error()
{
    perror("Error");
    exit(EXIT_FAILURE);
}
//command = ls , cat etc
//path str that holds the constructed path to the command
//part_path combines the directory path with a /
void    get_path(char *command, char **envp)
{
    char    **tab;
    char    *path;
    int     i;
    char    *path_cmd;

    if(!access(command, X_OK))
        return (command);
    while (!ft_strnstr(envp[i], "PATH=", 5))
        i++;
    tab = ft_split(envp[i] + 5, ':');
    if (!tab)
        return (NULL);
    i = 0;
    while (tab[i])
    {
        path_cmd = ft_strjoin(tab[i++], "/");
        path = ft_strjoin(path_cmd, command);
        if (!path_cmd)
            free(path_cmd);
        if (!access(path, X_OK))
            return (path);
        if (path)
            free(path);
    }
    return (0);
}

void    execution(char **argv, char **envp)
{
    int     i;
    char    **cmd;
    char    *path;

    i = -1;
    cmd = ft_split(argv, ' ');
    path = get_path(cmd[0], envp);
    if (path[i])
    {
        while (path[++i])
            free(cmd[i++]);
        free(cmd);
        ft_error();        
    }
    if (execve(path, cmd, envp) == -1)
        error(); 
}
