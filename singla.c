#include "main.h"

/**
  * signal_handler - handles the SIG_INT.
  * @n: just a filler for the signal prototype.
  *
  * Return: no return.
  */
void signal_handler(int n)
{
	(void) n;
	write(STDOUT_FILENO, "\n", 1);
	prompt();
}
