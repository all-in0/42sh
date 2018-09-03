#include <stdio.h>
#include <io.h>
#include <malloc.h>

//lib

#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

typedef struct s_map{
    char *key;
    char *value;
}              t_map;

typedef struct  s_shell{
    char *location;
    char *home;
    char **last_command;
    char **envp;
    t_map **env;
}               t_shell;

size_t	ft_strlen(const char *s)
{
    size_t		i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strcpy(char *str1, const char *str2)
{
    int i;

    i = 0;
    while (str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    return (str1);
}


char	*ft_strcat(char *s1, const char *s2)
{
    int	i;
    int	b;

    i = 0;
    b = 0;
    while (s1[i] != '\0')
        i++;
    while (s2[b] != '\0')
    {
        s1[i] = s2[b];
        i++;
        b++;
    }
    s1[i] = '\0';
    return (s1);
}

char	*ft_strdup(const char *s1)
{
    int		i;
    char	*cpy;

    i = 0;
    cpy = (char *)malloc(sizeof(s1) * (ft_strlen(s1) + 1));
    if (!cpy)
        return (0);
    while (s1[i] != 0)
    {
        cpy[i] = s1[i];
        i++;
    }
    cpy[i] = 0;
    return (cpy);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
    int		i;
    int		b;
    char	*str;

    if (!s1)
        return ((char *)s2);
    if (!s2)
        return ((char *)s1);
    i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
    str = (char *)malloc(i + 1);
    if (!str)
        return (0);
    i = -1;
    while (s1[++i])
        str[i] = s1[i];
    b = 0;
    while (s2[b])
    {
        str[i] = s2[b];
        i++;
        b++;
    }
    str[i] = 0;
    return (str);
}


// cd

/*

void	builtin_cd(char **argv, char **env)
{
    if (ft_strequ(argv[0], "cd") && argv[1] == NULL)
        bui_cd(env);
    else if (ft_strequ(argv[0], "cd") && ft_strequ(argv[1], "-"))
        bui_cd_(env);
    else if (ft_strequ(argv[0], "cd") && argv[1])
        bui_cd_arg(argv, env);
}

void	bui_cd(char **env)
{
    char *pwd;

    pwd = NULL;
    pwd = getcwd(pwd, 512);
    builtin_setenv(env, "OLDPWD", pwd);
    free(pwd);
    chdir(get_env("HOME", 5));
    pwd = getcwd(pwd, 512);
    builtin_setenv(env, "PWD", pwd);
}

void	bui_cd_(char **env)
{
    char *tmp;
    char *pwd;

    pwd = NULL;
    if (get_env("OLDPWD", 7))
    {
        tmp = getcwd(pwd, 512);
        chdir(get_env("OLDPWD", 7));
        builtin_setenv(env, "OLDPWD", tmp);
        free(tmp);
        pwd = getcwd(pwd, 512);
        builtin_setenv(env, "PWD", pwd);
        free(pwd);
    }
    else
        ft_putendl("\e[31;5;208mOLDPWD not set\e[0m");
}

void	bui_cd_arg(char **argv, char **env)
{
    char *pwd;

    pwd = NULL;
    if (is_dir(argv[1]) == 1)
    {
        pwd = getcwd(pwd, 512);
        builtin_setenv(env, "OLDPWD", pwd);
        free(pwd);
        chdir(argv[1]);
        pwd = getcwd(pwd, 512);
        builtin_setenv(env, "PWD", pwd);
    }
    else
    {
        ft_putstr("cd: ");
        ft_putstr(argv[1]);
        ft_putendl(": No such file or directory");
    }
}

int		is_dir(char *path)
{
    struct stat st;

    stat(path, &st);
    if (S_ISDIR(st.st_mode))
        return (1);
    else
        return (0);
}
*/
//end_cd

void err(char *str){
    if (str)
        printf("%s\n", str);
    exit(1);
}

void	builtin_setenv(char **env, char *name, char *value)
{
    int		pos;
    int		size;
    char	*tmp;
    char	*tmp_b;

//    size = tab_size(env);
    tmp_b = (char *)malloc(sizeof(char) * ft_strlen(name) + 2);
    ft_strcpy(tmp_b, name);
    if (name[ft_strlen(name) - 1] != '=')
        ft_strcat(tmp_b, "=");
 //   if (loc_var_env(name, ft_strlen(name), env) > 0)
    {
  //      pos = loc_var_env(name, ft_strlen(name), env);
     //   free(env[pos]);
     //   env[pos] = ft_strjoin(tmp_b, value);
    //    var_env_color(env[pos], 2);
    }
 //   else
    {
      //  tmp = ft_strjoin(tmp_b, value);
    //    realloc_env(tmp);
    //    var_env_color(tmp, 1);
    }
    free(tmp_b);
}

void	bui_cd(char **env)
{
    char *pwd;

    pwd = NULL;
    pwd = getcwd(pwd, 512);
//    builtin_setenv(env, "OLDPWD", pwd);
    free(pwd);
 //   chdir(get_env("HOME", 5));
    pwd = getcwd(pwd, 512);
 //   builtin_setenv(env, "PWD", pwd);
}

static size_t		ft_words_len(const char *s, char c)
{
    size_t			i;

    i = 0;
    while (s[i] != '\0' && s[i] != c)
        i++;
    return (i);
}

static size_t		ft_count_w(const char *s, char c)
{
    size_t			i;
    size_t			count;

    i = 0;
    count = 0;
    while (s[i] != '\0')
    {
        while ((s[i] == c) && s[i] != '\0')
            i++;
        if (s[i])
            count++;
        while ((s[i] != c) && s[i] != '\0')
            i++;
    }
    return (count);
}

static char			*ft_paswd(const char *s, size_t len)
{
    char			*word;
    size_t			i;

    i = 0;
    if ((word = (char *)malloc(sizeof(char *) * (len + 1))) == NULL)
        return (NULL);
    while (i < len)
    {
        word[i] = s[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char				**ft_strsplit(char const *s, char c)
{
    char			**str;
    size_t			i;
    size_t			j;

    i = 0;
    j = 0;
    if (s == NULL)
        return (NULL);
    if (!(str = (char **)malloc(sizeof(char *) * (ft_count_w(s, c) + 1))))
        return (NULL);
    while (i < ft_count_w(s, c))
    {
        while ((s[j] == c))
            j++;
        if ((str[i] = ft_paswd(s + j, ft_words_len(s + j, c))) == NULL)
            return (NULL);
        while (s[j] != c && s[j])
            j++;
        i++;
    }
    str[i] = 0;
    return (str);
}

char **split(const char *str){
    return (ft_strsplit(str, ' '));
}

void	echo(char **argv)
{
    int i;

    //i = (strequ(argv[1], "-n")) ? 2 : 1;
    while (argv[i])
    {
     //   ft_putstr(argv[i]);
        if (argv[i + 1])
     //       ft_putchar(' ');
        i++;
    }
    //if (!ft_strequ(argv[1], "-n"))
     //   ft_putchar('\n');
}


void remove_last(char **path, t_shell *shell){
    int i = ft_strlen(*path) - 1;

    while (i > 0 && (*path)[i] != '\\'){
        i--;
    }
    if ((*path)[i] == '\\')
        (*path)[i] = 0;
    else {
        free(*path);
        *path = malloc(sizeof(char) * ft_strlen(shell->home));
        *path = ft_strcpy(*path, shell->home);
    }
}

void join_path(char **path, char *location){
    *path = ft_strjoin((*path), "\\");
    *path = ft_strjoin(*path, location);
}

void remove_env(t_shell *shell, char *key){
    int i = 0;
    int last;
    t_map *tmp;
    while (shell->env[i] != NULL){
        if (!strcmp(key, shell->env[i]->key))
            break ;
        i++;
    }
    if (shell->env[i] == NULL)
        return ;
    last = i + 1;
    while (shell->env[last] != NULL)
        last++;
    tmp = shell->env[i];
    shell->env[i] = shell->env[last - 1];
    shell->env[last - 1] = NULL;
    free(tmp);
}

char *manage_path(t_shell *shell, char *cmd){
    char **cd;
    int i = 0;
    char *tmp;
    char *path;
    path = (char *)malloc(sizeof(char)* ((cmd[0] == '\\') ? ft_strlen(shell->home) : ft_strlen(shell->location)) + 1);
    cmd[0] == '\\' ? ft_strcpy(path, shell->home) : ft_strcpy(path, shell->location);
    cd = ft_strsplit(cmd, '/');
    // tmp = ft_strcpy();
    while(++i >= 0 && cd[i] != NULL) {
        if (strcmp(cd[i - 1], "..") == 0){
            remove_last(&(path), shell);
        }
        else if (strcmp(cd[i - 1], ".") == 0){
            continue;
        } else
            join_path(&path, cd[i - 1]);
        //path = ft_strjoin(path, cd[i]);
    }
    join_path(&path, cd[i - 1]);
    return path;
}

void start_cmd(char *cmd, char **arg){
    pid_t		pid;
    extern char	**environ;//manage shell env
/*
    if ((pid = fork()) < 0)
        ;//error
    if (pid > 0)
        wait(NULL);
    if (pid == 0)
    {
        execve(cmd, arg, environ);
        //error
        exit(-1);
    }
    else
        free(cmd);*/
}

void exec_cmd(t_shell *shell, char **cmd){
    char *path;
    path = manage_path(shell, cmd[0]);
    char *tmp;
    tmp = cmd[0];
    cmd[0] = path;
    free(tmp);
    if ((access(path, F_OK) == 0)){
        start_cmd(path, cmd);
    }
}

int search_env(t_shell *shell, char *name){
    int i = 0;
    while(shell->env[i] != NULL){
        if (!strcmp(shell->env[i]->key, name))
            return i;
        i++;
    }
    return (-1);
}


void add_env(t_shell *shell, char *key, char *value){
    t_map **old;
    int i = 0;
    old = shell->env;
    if ((i = search_env(shell, key)) == -1) {
        while (old[i] != NULL) {
            i++;
        }
        shell->env = (t_map **) malloc(sizeof(t_map *) * i + 2);
        shell->env[i] = (t_map *) malloc(sizeof(t_map));
        shell->env[i]->key = key;
        shell->env[i]->value = value;
        shell->env[i + 1] = NULL;
        while (i > 0) {
            i--;
            shell->env[i] = old[i];
        }
    }
    else if (key == NULL || value == NULL){
        printf("usage: setnenv [env] [value]");
    }
    else {
        free(shell->env[i]->value);
        shell->env[i]->value = value;//strcopy

    }
    free(old);
}


void make_cd(t_shell *shell, char **command, char *line){
    char **cd;
    int i = -1;
    char *tmp;
    char *path;
    path = (char *)malloc(sizeof(char)* ((line[0] == '\\') ? ft_strlen(shell->home) : ft_strlen(shell->location)) + 1);
    line[0] == '\\' ? ft_strcpy(path, shell->home) : ft_strcpy(path, shell->location);
    cd = ft_strsplit(command[1], '/');
   // tmp = ft_strcpy();
    while(++i >= 0 && cd[i] != NULL) { //segfault
        if (strcmp(cd[i], "..") == 0){
            remove_last(&(path), shell);
        }
        else if (strcmp(cd[i], ".") == 0){
            continue;
        } else
            join_path(&path, cd[i]);
            //path = ft_strjoin(path, cd[i]);
    }
 //   for (int i = 0; cd[i] != 0; i++)
  //      printf("%s\n", cd[i]);
    printf("%s\n", path);
}

int is_command(t_shell * shell, char **cmd){

}

int is_exist(char **str){
    int i = 0;
    while(str[i] != NULL)
        i++;
    return i;
}

void do_env(t_shell *shell, char *key){
    int i;
    if (key == NULL)
        printf("usage: env [key]\n");
    else {
        i = search_env(shell, key);
        i == -1 ? printf("%s is unknown\n", key) : printf("%s\n", shell->env[i]->value);
    }
}

void do_getenv(t_shell * shell, char *cmd){
    int i;

    i = 0;
    if (cmd == NULL){
        printf("usage: getenv [value]\n");
    }
    while (shell->env[i] != NULL && (strcmp(shell->env[i]->key, cmd) != 0))
        i++;
    if (shell->env[i] == NULL)
        printf("%s unknown variable\n", cmd);
    else
        printf("%s=%s", shell->env[i]->key, shell->env[i]->value);
}

void do_command(t_shell *shell, char **command, char *line){
    int i;

    i = is_exist(command);
    if (strcmp(command[0], "cd") == 0)
        make_cd(shell, i < 2 ? NULL : command, line);
    else if (strcmp(command[0], "exit") == 0){
        // free all shell!))
        err("Goodbye!\n");
    }
    else if (strcmp(command[0], "getenv") == 0)
        do_getenv(shell, i != 2 ? NULL : command[1]);//if ac != 2
    else if (strcmp(command[0], "setenv") == 0)
        add_env(shell, command[1], command[2]);
    else if (strcmp(command[0], "env") == 0)
        do_env(shell, i == 2 ? command[1] : NULL);
    else if (is_command(shell, command))
        make_cd(shell, command, line);
    else {printf("command %s is unknown, please enter a valid command\n", command[0]); err(NULL);}
}

void print_promt(t_shell *shell){

//    long size;
 //   char *buf;
 //   char *ptr;


  //  size = 2056;
 //   if ((buf = (char *)malloc((size_t)size)) != NULL)
 //       ptr = getcwd(buf, (size_t)size);
    //    char *pwd;

  //  pwd = NULL;
   // pwd = getcwd(pwd, 512);
    printf("$:~%s\n>", shell->location); // add path and username
}

int size_tab(char **s){
    int i = 0;
    while(s[i] != NULL){
        i++;
    }
    return (i);
}

void manage_envp(t_shell *shell, char **envp){
    char **tmp;
    int i = -1;
    int size = size_tab(envp);
    shell->env = (t_map **)malloc(sizeof(t_map*) * size + 1);
    while(envp[++i] != NULL){
        shell->env[i] = (t_map *)malloc(sizeof(t_map));
        tmp = ft_strsplit(envp[i], '=');//check length == 2
        shell->env[i]->key = tmp[0];
        shell->env[i]->value = tmp[1];
    }
    shell->env[i] = NULL;
}


void init_shell(t_shell *shell, char **envp){
    long size;
    char *buf;

    int  i= 0;
    size = 2056;
    shell->envp = envp;
    manage_envp(shell, envp);
    shell->last_command = (char **)malloc(sizeof(char*) * 11);
    shell->last_command[0] = NULL;
    if ((buf = (char *)malloc((size_t)size)) != NULL)
        shell->location = getcwd(buf, (size_t)size);
    while (strncmp("HOMEPATH", envp[i], sizeof("HOMEPATH") - 1) != 0){
        i++;
    }
    if (envp[i] != NULL && !strncmp("HOMEPATH", envp[i], sizeof("HOMEPATH") - 1))
        shell->home = ft_strsplit(envp[i], '=')[1];//leakse
    else {exit(1);}//default path
    //shell
    //if (!getcwd(shell->location, 512))
            //err("can't get pwd\n");
}

void add_cmdmem(t_shell *shell, char *cmd){
    int i = 0;
    char *tmp;

    while (shell->last_command[i] != NULL){
        i++;
    }
    if (i < 10) {
        shell->last_command[i + 1] = NULL;
        shell->last_command[i] = cmd;
    }
    else {
        while(--i > 0){
          //  tmp = shell->last_command[i]
        }
    }
}


void pars_command(t_shell *shell, char *cmd){
    char **cmds;
    int i = 0;
    char **curr_cmd;


    cmds = ft_strsplit(cmd, ';');
    while (cmds[i] != NULL){
        curr_cmd = ft_strsplit(cmds[i], ' ');
        do_command(shell, curr_cmd, cmds[i]);
        i++;
    }
}

void signal_handl(){

}


void  INThandler(int sig)
{
    char  c;

    signal(sig, SIG_IGN);
    printf("OUCH, did you hit Ctrl-C?\n"
           "Do you really want to quit? [y/n] ");
    c = getchar();
    if (c == 'y' || c == 'Y')
        exit(0);
    else
        signal(SIGINT, INThandler);
    getchar(); // Get new line character
}

int main(int ac, char **av, char **envp)
{
    t_shell shell;
    init_shell(&shell, envp);
    char **line;
    char ll[] = "./../test";
    char **command;
    signal(SIGINT, INThandler);
    while (1)
    {
        print_promt(&shell);
        //if (get_next_line(0, &(*line)) < 0)
          //  break ;
//        command = split(line);
        printf("!!!!!!%s!!!!!\n",manage_path(&shell, ll));

     //   pars_command(&shell, line);
while(1) ;



     //   for (int i = 0; envp[i] != NULL; i++)
    //        printf("%d = |%s|%s=%s\n", i, envp[i], shell.env[i]->key, shell.env[i]->value);
     //   remove_env(&shell, "LOCALAPPDATA");
    //    add_env(&shell, "TEST", "test");
    //    for (int i = 0; envp[i] != NULL; i++)
    //        printf("%d = |%s=%s\n", i, shell.env[i]->key, shell.env[i]->value);
       // do_command(&shell, command, line);
        break ;
    }
    return 0;
}