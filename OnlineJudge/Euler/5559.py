import sys
import math

def fibo(n):
  u = (math.sqrt(5)+1)/2
  return (u**n-(1-u)**n)/math.sqrt(5)


def pro():
  s = sys.stdin.readline()
  a = int(s.split()[0])
  b = int(s.split()[1])
  cnt = 0
  for i in range(1, 481):
    f = round(fibo(i))
    if f >= a and f <= b:
      cnt += 1;
  print(cnt)

pro()
pro()