bool isOneBitCharacter(int* bits, int bitsSize)
{
    int i=0,count;
    while(i < bitsSize)
    {
        if(bits[i] == 0)
        {
            i++;
            count = 1;
        }
        else
        {
            i = i+2;
            count = 2;
        }
    }
    if(count == 1)
    {
        return true;
    }
    return false;
}
