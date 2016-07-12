# returns a tuple with (gcd, x, y)
def extendedEuclidean(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = extendedEuclidean(b % a, a)
        return (g, x - (b // a) * y, y)

