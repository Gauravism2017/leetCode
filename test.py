
import sys
temp = sys.stdout
f = open('inp', 'w')
sys.stdout = f
n = int(input())
print(n - 1)
li = list(range(1,n))
li = str(li)[1:-1]
li = li.replace(',', ' ')
print(li)
sys.stdout = temp
f.close()
