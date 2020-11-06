import sys

a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
s = str(a*b)
i = 0

for e in range(0, len(s)):
  print(s[e], end = '')
  i += 1
  if(i%10 == 0):
    print("\n", end='')