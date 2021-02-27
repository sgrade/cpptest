unsigned long long factorial (unsigned long long n)
{
    return (n == 0) || (n == 1) ? 1 : n * factorial(n-1);
}
