/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:33:55 by alanders          #+#    #+#             */
/*   Updated: 2019/08/22 14:58:45 by alanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** The gnl function returns a line read from the file descriptor.
** A line is succession of characters that end with a '\n' or '\0'.
** ft_new_line looks for the '\n' or '\0' character.
** If it finds a '\n' it creates a substring for the entire text up until that
** - point, then duplicates that same substring so that s[fd] can be freed.
** We need to free the memory in s[fd] so that we can use it again.
** s[fd] is initialised to contain the duplicated substring.
** If the first character of the substring is a '\0', the function returns 1
** which says that the entire file has been completely read.
** If it finds a '\0' instead, then duplicates the entire read array s[fd]
** - into *line, then frees the address of s[fd] and sets it's pointer to NULL.
** Return (1) to signify that the line has been read.
** Functions used :
** ft_strsub - returns a new substring from string given as argument.
** ft_strdup - allocates sufficient memory for a copy of the argument string
** ft_strdel - takes address of a string and sets pointer to NULL.
** sd
*/

static int	ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

/*
** The first parameter is the file descriptor that will be used to read.
** The second parameter is the address of a pointer to a character that will
** - be used to save the line read from the file descriptor.
** The function will return '1' when the line has been read.
** The function will return '0' when all the lines have been read.
** The function will return '-1' when an error has occured while reading.
** The read function takes in a file descriptor, a character array where
** - the read content will be stored and the number of bytes to read before
** - truncating the data. If the data to be read is smaller than BUFF_SIZE,
** - all data is saved in the buffer.
** Returns the number of bytes that were read.
** If value is negative, then the system call returned an error.
** If a \n is found the function breaks out to the gnl function return.
** This will take you to the ternary operation where if the return value
** - is 0 and s[fd] is NULL or '\0', return 0, otherwise return ft_new_line.
** 255 is the maximum number of file descriptors you can have open.
** Fuctions used:
** ft_strnew  - returns a new string ending with '\0'.
** ft_strjoin - concatenated string of s[fd] and buf.
** ft_strchr  - locates the first occurrence of '\n in buf
*/

int			get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, ret));
}
