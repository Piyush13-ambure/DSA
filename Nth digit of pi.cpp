/*Calculate the Nth digit in the representation of Pi.
this solotion is with python 
*/

def sqrt(n, MAX):
    #Using floating point arithmetic to get a more accurate result.
    float_max = 10**16
    n_float = float((n*float_max)//MAX)/float_max
    
    #Calculating an initial approximation using the floating point square root.
    curr = (int(float_max*math.sqrt(n_float))*MAX)//float_max
    
    n_MAX = n*MAX
    
    #Iteratively improving the approximation using Newton's method.
    while True:
        prev = curr
        curr = (curr+n_MAX//curr)//2
        if curr == prev:
            break
    return curr

#Function to calculate the power of 10.
def power(n):
    if n==0:
        return 1
    ans = power(n//2)
    if n%2==0:
        return ans*ans
    return ans*ans*10

#Function to calculate the nth digit of pi.
def pi(n):
    MAX = power(n+10)
    c = (640320**3)//24
    n = 1
    a_n = MAX
    a_summation = MAX
    b_summation = 0
    
    #Calculating the series expansion of pi up to the nth term.
    while a_n != 0:
        a_n *= -(6*n-5)*(2*n-1)*(6*n-1)
        a_n //= n*n*n*c
        a_summation += a_n
        b_summation += n*a_n
        n += 1
    
    #Using the series expansion to calculate pi.
    ans = (426880*sqrt(10005*MAX,MAX)*MAX)//(13591409*a_summation+545140134*b_summation)
    
    return ans

#Solution class to solve the problem.
class Solution:
        
    def nthDigOfPi(self, N):
        #Calculating the nth digit of pi.
        p=str(pi(N))
        
        return p[N-1]
