int maxProfit(int* prices, int pricesSize)
{
    int max = 0;
    int min = prices[0];
    for(int i=1; i<pricesSize; i++)
    {
        min = minNum(min,prices[i]);
        max = maxNum(max,prices[i] - min);
    }
    return max;
}
int minNum(int a, int b)
{
    if(a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int maxNum(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
