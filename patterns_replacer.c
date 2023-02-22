#include "general.h"
#include "text.h"
#include "commands.h"
/**
 * replacement -  replaces info at a certian index
 * @info: the information to be replaced
 * @index: the position
 * @string: the string containing the info
 * Return: pointer to replacement string
 */
char *replacement(general_t *info, int *index, char *string)
{
	char *tmp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}
/**
 * replace_env - replaces the environment
 * @info: the information
 * @environment: the environment to be replced
 * Return: replaced environment
 */
char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}

