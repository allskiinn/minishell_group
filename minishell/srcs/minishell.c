#include "../includes/minishell.h"

int main(void)
{
    t_prompt prompt;
    t_token  *tokens;

    prompt.len = 34;
    prompt.prompt = GREEN BOLD"\n---(allskiin@shell)-[~]\n $> "RESET;
    prompt.command = readline(prompt.prompt); // Aloca memória para `prompt.command`
    
    while ((prompt.command)) 
    {
        if (!ft_strcmp(prompt.command, "exit"))
        {
            free(prompt.command); // Libera memória alocada para `prompt.command`
            free_tokens(tokens); // Aqui, não sabemos se `tokens` é liberado corretamente
            exit(0);
        }
        
        tokens = tokenize(&prompt);
        print_tokens(tokens);
        
        free(prompt.command); // Liberar a memória de `prompt.command` antes da próxima leitura
        
        prompt.command = readline(prompt.prompt); // Nova alocação de memória
    }
    
    free(prompt.command); // Libera a memória ao final
    free_tokens(tokens); // Certifique-se de liberar `tokens` se ele estiver alocado
    return (0);
}

