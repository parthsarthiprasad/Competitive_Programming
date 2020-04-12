##Containing DAC problems 
- Searching Algorithms
- Sorting Algorithms
- Closest pair points
- Matrix Multiplication problems
- Fourier Transformation
- Karatsuba algorithm

---
DAC(a, i, j)
{
    if(small(a, i, j))
      return(Solution(a, i, j))
    else 
      m = divide(a, i, j)               // f1(n)
      b = DAC(a, i, mid)                 // T(n/2)
      c = DAC(a, mid+1, j)            // T(n/2)
      d = combine(b, c)                 // f2(n)
   return(d)
}
---


RECURRENCE RELATION

T(n) = f1(n) + 2T(n/2) + f2(n)

