// http://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi
double mysqrt(const double x)  
{
    union
    {
        int i;
        double x;
    } u;
    u.x = x;
    u.i = (1<<29) + (u.i >> 1) - (1<<22); 
  
    // Two Babylonian Steps (simplified from:)
    // u.x = 0.5f * (u.x + x/u.x);
    // u.x = 0.5f * (u.x + x/u.x);
    u.x =       u.x + x/u.x;
    u.x = 0.25f*u.x + x/u.x;

    return u.x;
}
