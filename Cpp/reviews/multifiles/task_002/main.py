
import numpy as np
import matplotlib.pyplot as plt

fpath = "./data.csv"

x = np.array([i for i in range(1024)])
y = np.zeros(1024, np.double)

with open(fpath, 'r') as f:
  for i, line in enumerate(f):
    if i > 0:
      record = np.array([ (m[:-1] if k == 2 else m) for k,m in enumerate(line.split(','))] ) 
      z = complex(record[1].astype(np.double) , record[2].astype(np.double) )
      magnitude = abs(z)
      y[i - 1] = magnitude      
  y = y / np.max(y)
  
  plt.plot(x[0:1 + 512], y[0: 512 + 1])
  plt.title('wave.cpp [N=1024, Fs=30]')
  plt.show() 
  
