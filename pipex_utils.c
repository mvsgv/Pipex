/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:01:26 by mavissar          #+#    #+#             */
/*   Updated: 2024/10/10 14:49:30 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *get_path(char *c, char **env)
{
    
}
void    open_file(char *file, int pos)
{
    int     res;

    if (pos == 0)
        res = open(file, O_RDONLY, 0777);
    if (pos == 1)
        res = open (file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (res = -1)
        exit (0);
    return (res);
}