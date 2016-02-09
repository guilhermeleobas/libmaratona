
def modular (base, exp, mod):
	if (mod == 1):
		return 0;
	c = 1;
	for e in range (1, exp):
		c *= (c*base)%mod;
	return c;

