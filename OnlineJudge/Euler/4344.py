import sys

sum = 0
i = 0
while 1:
  i += 1
  a = int(sys.stdin.readline())
  if(a != 0): sum += a;
  else: break

  if i == 100: break

print(sum)