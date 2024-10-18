/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:09:17 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/17 23:05:19 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_h

#include "../libft/libft.h"
#include <stdio.h>      // printf, perror, strerror
#include <stdlib.h>     // malloc, free, exit, getenv
#include <unistd.h>     // read, write, close, fork, pipe, dup, dup2, isatty, ttyname, ttyslot, access, chdir, getcwd
#include <sys/types.h>  // wait, waitpid
#include <sys/wait.h>   // wait, waitpid, wait3, wait4
#include <signal.h>     // signal, sigaction, sigemptyset, sigaddset, kill
#include <sys/stat.h>   // stat, lstat, fstat, unlink
#include <fcntl.h>      // open
#include <dirent.h>     // opendir, readdir, closedir
#include <termios.h>    // tcsetattr, tcgetattr
#include <term.h>       // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
#include <string.h>     // memset

#include <readline/readline.h>
#include <readline/history.h>

// colors
 # define RESET "\033[0m"
 # define GREEN "\e[32m"
 # define CYAN "\33[1;36m"
 # define YELLOW "\e[033m"
 # define BLUE "\e[34m"
 # define WHITE "\e[00m"
 # define RED "\033[1;31m"
 # define BOLD "\033[1;1m"

#endif