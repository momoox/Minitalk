#include <unistd.h>
#include <signal.h>

void signal_handler(int signum)
{
    if(signum == SIGUSR2)
        printf("%d\n", signum);
}

char    *btoc(int stringb)
{

}

int main()
{
    int stringb;
    char *result;
    int i;

    i = 0;
    pid_t getpid;
    while(pid[i])
    {
        write(1, &pid, 1);
        i++;
    }
    signal(pid, SIGUSR1);
    sleep(500);
    result = btoc(SIGUSR2);
    signal(SIGUSR2, signal_handler);
}