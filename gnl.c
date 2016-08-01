/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:03:56 by tsanzey           #+#    #+#             */
/*   Updated: 2015/12/15 11:03:58 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int		get_next_line(int const fd, char **line)
{
	static char		*dst = NULL;
	int				i;

	if (fd < 0 || !line)
		return (-1);
	i = get_line_len(fd, &dst);
	if (i == -1)
		return (0);
	if (i == -2)
		return (-1);
	*line = ft_strsub(dst, 0, i);
	dst = del_line(dst, i + 1);
	return (1);
}

char		*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (i + j + 1));
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	// free(s1);
	return (dest);
}

int		checknewline(char *s)

{
	int i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		return (i);
	else
		return (-1);
}

char	*del_line(char *s, int i)
{
	int		j;
	char	*tmp;

	tmp = (char *)malloc(sizeof(ft_strlen(s) - i));
	j = 0;
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		tmp[j] = s[i];
		j++;
		i++;
	}
	return (tmp);
}

int		get_line_len(int const fd, char **dst)
{
	int		i;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	ret = 1;
	while (ret != 0 && (i = checknewline(*dst)) == -1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-2);
		buf[ret] = '\0';
		if (*dst == NULL)
			*dst = ft_strdup(buf);
		else
			*dst = ft_strjoin2(*dst, buf);
	}
	if (ret == 0 && i == -1 && ft_strcmp("", *dst))
		return (ft_strlen(*dst));
	return (i);
}
