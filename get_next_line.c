/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:31:10 by voszadcs          #+#    #+#             */
/*   Updated: 2022/12/19 07:40:28 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char	**decimate(char *victim)
{
	char	**peter;
	int		search;

	search = 0;
	peter = malloc(sizeof(char *) * 2);
	while (victim[search] != '\n' && victim[search] != '\0')//last 
	{							  //12345678901234
		search++; //4
	}
	search++;//5
	peter[0] = malloc(sizeof(char) * (search + 1));//6
	peter[0][search] = '\0';
	peter[1] = malloc(sizeof(char) * (ft_strlen(&victim[search]) + 1));
	peter[1][(ft_strlen(&victim[search]))] = '\0';
	ft_memmove(peter[0], victim, search);
	//printf("peter[0] value: %s\n", peter[0]);
	ft_memmove(peter[1], &victim[search], ft_strlen(&victim[search]));
	//printf("peter[1] value: %s\n", peter[1]);
	return (peter);
}
char	*get_one_line(int fd, char *buffer)
{
	char	*read_value;
	char	*temp;
	int		read_return;

	read_return = 1;
	while (read_return > 0 && !ft_strchr(buffer, '\n'))
	{
		read_value = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!read_value)
			return (NULL);
		read_return = read(fd, read_value, BUFFER_SIZE);
		if (read_return < 0)
			return NULL;
		read_value[read_return] = '\0';
		temp = ft_strjoin(buffer, read_value);
		free(buffer);
		buffer = malloc(sizeof(char) * ft_strlen(temp) + 1);
		ft_memmove(buffer, temp, ft_strlen(temp));
		buffer[ft_strlen(buffer)] = '\0';
		free(temp);
		//printf("read value: %s\n", read_value);
		free(read_value);
		if (read_return < BUFFER_SIZE)
			read_return = 0;
	}
	//printf("buffer: %s\n", buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		**remaining;
	char		*line_to_return;

	if (!buffer)
	{
		buffer = malloc(sizeof(char) * 1);
		buffer[0] = '\0';
	}
	buffer = get_one_line(fd, buffer);
	remaining = decimate(buffer);
	if (buffer)
		free(buffer);
	buffer = remaining[1];
	line_to_return = remaining[0];
	//printf("line to return: %s\n", line_to_return);
	return (line_to_return);
}

// int main (void)
// {
// 	int fd;
// 	int i = 0;

// 	fd = open("input.txt", O_RDONLY);
// 	while (i < 3)
// 	{
// 		printf("Output: %s", get_next_line(fd));
// 		i++;
// 	}
// 	printf("%s", "//**//");
// }

// int main()
// {
// 	mmain();
// 	system("leaks a.out");
// }
