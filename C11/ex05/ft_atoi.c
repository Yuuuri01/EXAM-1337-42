int ft_atoi(char *s)
{
    int sign;
    int res;

    sign = 1;
    res = 0;

    while(*s == 32 || *s == 9)
        s++;
    while(*s == 45 || *s == 43)
    {
        if(*s == 45)
            sign = -sign;
        s++;
    }
    while(*s >= '0' && *s <= '9')
    {
        res = res * 10 + *s - 48;
        s++;
    }
    return res * sign;
}