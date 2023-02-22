#ifndef MAIN_H
#define MAIN_H

char *read_line(void);
char **split_line(char *buff);
int bind(char **arr);
int _cd(char **arr);
int _alias(char **arr);
int ls_exit(char **arr);
int _env(char **arr);
int execute(char **arr);

#endif
