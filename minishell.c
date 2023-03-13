#include "minishell.h"

// changes Ctrl+C to \n
void    sig_handler()
{
    write(1, "\n", 1);
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
}

void    ignore_signal()
{
    signal(SIGINT, sig_handler);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGSEGV, SIG_IGN);
}

int	main(void)
{	
	char	*command;

    ignore_signal();
	while (1)
	{
		command = readline(YELLOW"minishell> " RESET);
		if (command && *command)
			add_history(command);
        // handles Ctrl+D
        if (command == NULL)
        {
            write(1, "\n", 1);
            free(command);
            exit(1);
        }
        if (!check_quotation_marks(command))
            printf("Error! Missing closing \"\n");
        tokenizer(command);
        free(command);
	}
	return (0);
}