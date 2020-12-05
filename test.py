from Euler import miller_rabin as m_r
n_prime, d, avg, n = 0, 1, 1, 2

while avg >= 0.10:
    n_prime += m_r(d + n) + m_r(d + n*2) + m_r(d + n*3)
    d += n*4
    n += 2
    avg = n_prime / (2.0 * n)    # the decimal forces a float calculation

print("Project Euler 58 Solution =", n-1)