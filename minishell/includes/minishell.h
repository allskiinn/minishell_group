/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:09:17 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/24 01:11:06 by aliberal         ###   ########.fr       */
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


typedef struct s_prompt
{
	char	*command;
	char	*prompt;
	size_t	len;
	int		i;
	int		start;
	char	quote_char;
} t_prompt;

typedef enum	e_token_type 
{
    TOKEN_COMMAND,      // Ex: 'ls', 'cat', 'grep'
    TOKEN_ARGUMENT,     // Ex: '-l', 'arquivo.txt'
    TOKEN_PIPE,         // Ex: '|'
    TOKEN_REDIRECT_IN,  // Ex: '<'
    TOKEN_REDIRECT_OUT, // Ex: '>'
    TOKEN_APPEND,       // Ex: '>>'
    TOKEN_HEREDOC,      // Ex: '<<'
    TOKEN_SINGLE_Q,		// Ex: 'texto'
    TOKEN_DOUBLE_Q,		// Ex: "palavra"
    TOKEN_EOF           // Fim da entrada de comando
}				t_token_type;

typedef struct	s_token 
{
    t_token_type	type;
    char			*content;
    struct s_token	*next;
}				t_token;

typedef struct	s_command
{
    char	**args;        // Lista de argumentos do comando
    char	*input_file;   // Arquivo de entrada para redirecionamento
    char	*output_file;  // Arquivo de saída para redirecionamento
    int		append_mode;  // Modo de append para >>
    int		is_pipe;      // Indica se o comando está antes de um pipe
    struct	s_command *next;
}				t_command;



// tokens
t_token			*create_token (t_token_type type, char *content);
int				is_delimiter (char c);
t_token_type	get_token_type (char *content);
void			add_token_to_list(t_token **tokens, t_token *new_token);
t_token			*tokenize (t_prompt *pos);
const char		*token_type_to_string(t_token_type type);
void			print_tokens (t_token *tokens);
void            free_tokens(t_token *token);

// commands
t_command	*parsing(t_token *tokens);
void        print_cmd(t_command *cmds);

#endif