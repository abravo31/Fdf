/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:20:05 by abravo            #+#    #+#             */
/*   Updated: 2022/11/07 18:09:02 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int check_file_name (const char *filename)
{
    int i;
    int j;
    char *type;

    i = 0;
    j = 0;
    type = ".fdf";
    if(filename[i] == '.')
        return(1);
    while (filename[i] != '.')
        i++;
    while (filename[i] && type[j] && filename[i] == type[j])
    {
        i++;
        j++;
    }
    if (!filename[i] && !type[j])
        return (0);
    else
        return (1);
}

int check_file(const char *filename)
{   
    int file;

    if(check_file_name(filename))
       return (printf("File format is wrong.\n"),1); 
    file = open(filename, O_RDONLY);
    if (file == -1)
        return (printf("Problem with file.\n"), 1);
    return (0);
}