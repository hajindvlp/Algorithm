import sys

def pro():
  N = int(sys.stdin.readline())
  a = []
  for i in range(1, N):
    a.append(int(sys.stdin.readline()))

  for i in range(1, N-1):
    
  cnt = 0
  for i in range(1, 481):
    f = round(fibo(i))
    if f >= a and f <= b:
      cnt += 1;
  print(cnt)

pro()
pro()