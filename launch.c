#include "main.h"

/**
 * hsh_launch - launchs a program
 * @args: NULL terminated list of arguments
 *
 * Return: Always returns 1
 */
int hsh_launch(char **args)
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      //perror(args[0]);
      //perror(args[2]);
      fprintf(stderr, "not found\n");
      //exit(EXIT_FAILURE);
    }
    //exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    //perror("lsh");
    //perror(args[0]);
    fprintf(stderr, "not found\n");
  } else {
    // Parent process
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return (1);
}
