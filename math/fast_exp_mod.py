
# return (base ˆ exp) % mod;

def exp_mod (base, exp, mod):
    if (mod == 1):
        return 0;
    
    number = 1;
    
    while (exp):
        if (exp & 1):
            number = (number * base) % mod;
        exp >>= 1
        base = (base * base) % mod;
    
    return number;

