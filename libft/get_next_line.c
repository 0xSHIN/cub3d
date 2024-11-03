/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:44:23 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/30 01:18:24 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str)
	{	
		while (str[i])
		{
			if (str[i] == (unsigned char)c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*dest;

	len1 = 0;
	len2 = 0;
	j = 0;
	i = 0;
	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	dest = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dest)
		return (NULL);
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	while (j < len2)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (free(s1), dest);
}

char	*get_current_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*add_left_to_stash(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*left;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	left = malloc((gnl_strlen(stash) - i) * sizeof(char));
	if (!left)
		return (free(stash), NULL);
	j = i + 1;
	k = 0;
	while (stash[j])
		left[k++] = stash[j++];
	left[k] = '\0';
	return (free(stash), left);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	char			*buffer;
	int				bytes_read;

	bytes_read = 1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes_read && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	line = get_current_line(stash);
	stash = add_left_to_stash(stash);
	return (free(buffer), line);
}

/*
   int	main(int argc, char **argv)
   {
   char	*str;
   int		fd;

   if (argc != 2)
   return (1);
   fd = open(argv[1], O_RDONLY);
   str = get_next_line(fd);
   while (str)
   {
   printf("%s", str);
   free(str);
   str = get_next_line(fd);
   }
   free(str);
   return (0);
   }
 */
