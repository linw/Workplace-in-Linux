import datetime

def bsearch(array,key):
  i = 0
  j = len(array)-1
  while i<=j:
    m = (i+j)/2
    if array[m] > key:
      j = m - 1
      continue
    elif array[m] < key:
      i = m + 1
      continue
    else:
      return m
  return -1

def line_search(array,key):
  for i in range(len(array)):
    if array[i] == key:
      return i
  return -1

def test_search(algnum,n,numtests):
  a = []
  for i in range(n):
    a.append(i) 
  starttime = datetime.datetime.now()
  for i in range(numtests):
    for j in range(n):
      if algnum == 0:
        if bsearch(a,j) != j:
          print "something wrong!"
      elif algnum == 1:
        if line_search(a,j) != j:
          print "something wrong!"
  endtime = datetime.datetime.now()
  interval=(endtime - starttime).seconds
  print interval
  
    




if __name__ == '__main__':
  test_search(0,10000,100)
  test_search(1,10000,100)
