#include "../includes/minishell.h"

t_token *create_token (t_token_type type, char *content)
{
    t_token *no = malloc(sizeof(t_token));
    if (!no)
        return (NULL);
    no->type = type;
    no->content = ft_strdup(content);
    no->next = NULL;
    return (no);
}

int is_delimiter (char c)
{
    return (c == ' ' || c == '|' || c == '>' || c == '<');
}

t_token_type get_token_type (char *content)
{
    if (ft_strcmp(content, "|") == 0) 
        return TOKEN_PIPE;
    else if (ft_strcmp(content, "<") == 0)
        return TOKEN_REDIRECT_IN;
    else if (ft_strcmp(content, ">") == 0)
        return TOKEN_REDIRECT_OUT;
    else if (ft_strcmp(content, ">>") == 0)
        return TOKEN_APPEND;
    else if (ft_strcmp(content, "<<") == 0)
        return TOKEN_HEREDOC;
    else if (content[0] == '"' || content[0] == '\'')
        return TOKEN_STRING;
    else if (content[0] == '-')
        return TOKEN_ARGUMENT;
    else
        return TOKEN_COMMAND;
}

void add_token_to_list(t_token **tokens, t_token *new_token)
{
    if (!*tokens) {
        *tokens = new_token;
    } else {
        t_token *aux = *tokens;
        while (aux->next)
            aux = aux->next;
        aux->next = new_token;
    }
}

t_token *tokenize (char *prompt)
{
    t_token *tokens = NULL;
    t_token *new = NULL;
    char    *content;
    int i = -1, start = 0;

    while (prompt[++i])
    {
        if (is_delimiter(prompt[i]))
        {
            if (start != i)
            {
                content = ft_strndup(prompt + start, i - start);
                new = create_token(get_token_type(content), content);
                free(content);
                if (new == NULL)
                    return NULL;
                add_token_to_list(&tokens, new);
            }
            if (prompt[i] != ' ')
            {
                content = ft_strndup(prompt + i, 1);
                new = create_token(get_token_type(content), content);
                free(content);
                if (new == NULL)
                    return NULL;
                add_token_to_list(&tokens, new);
            }

            start = i + 1;
        }
    }
    if (start != i)
    {
        content = ft_strndup(prompt + start, i - start);
        new = create_token(get_token_type(content), content);
        free(content);
        if (new == NULL)
            return NULL;
        add_token_to_list(&tokens, new);
    }

    return tokens;
}


const char *token_type_to_string(t_token_type type)
{
    switch (type)
    {
        case TOKEN_COMMAND:
            return "TOKEN_COMMAND";
        case TOKEN_ARGUMENT:
            return "TOKEN_ARGUMENT";
        case TOKEN_PIPE:
            return "TOKEN_PIPE";
        case TOKEN_REDIRECT_IN:
            return "TOKEN_REDIRECT_IN";
        case TOKEN_REDIRECT_OUT:
            return "TOKEN_REDIRECT_OUT";
        case TOKEN_APPEND:
            return "TOKEN_APPEND";
        case TOKEN_HEREDOC:
            return "TOKEN_HEREDOC";
        case TOKEN_STRING:
            return "TOKEN_STRING";
        case TOKEN_EOF:
            return "TOKEN_EOF";
        default:
            return "UNKNOWN";
    }
}

void print_tokens (t_token *tokens)
{
    t_token *aux = tokens;
    while (aux)
    {
        printf("\n\nType: %s\nContent: %s\nlen: %ld", token_type_to_string(aux->type), aux->content, ft_strlen(aux->content));
        aux = aux->next;
    }
}

int main(void)
{
    t_prompt    prompt;
    t_token     *tokens;
	char        *command;

    prompt.len = 34;
    prompt.prompt = GREEN BOLD"\n---(allskiin@shell)-[~]\n $> "RESET;
    
    while ((command = readline(prompt.prompt))) 
    {
        tokens = tokenize(command);
        print_tokens(tokens);
    }
    return (0);
}
