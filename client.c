int    *ctob(char *str)
{
    int i;
    int index;
    int result;
    i = 7;

    while(i >= 0)
    {
        result = (str[index] << i);
        i--;
        index++;
    }
    return(result);
}

void signal_handler(int signum)
{
    if(signum == SIGUSR1)
        printf("%d\n", signum);
}

int main(int argc, char **argv)
{
    int stringb;

    stringb = ctob(argv);
    
    kill(, SIGUSR2);
}