import numpy as np
import matplotlib.pyplot as plt

derive_path = "./PPFM_D.csv" # relative paths
raw_path = "./PPFM.csv"

N = 577
x = np.array([i for i in range(N)])
y = np.zeros(N, np.double)
y2 = np.zeros(N, np.double)

with open(derive_path, 'r') as file1, open(raw_path, 'r') as file2:
  
  for index, (line1, line2) in enumerate(zip(file1, file2)):
    if index > 0:
      record1 = np.array([ (m[:-1] if k == 1 else m) for k,m in enumerate(line1.split(','))] )    
      record2 = np.array([ (m[:-1] if k == 3 else m) for k,m in enumerate(line2.split(','))] )    
      y[index - 1] = record1[1]   
      y2[index - 1] = record2[1]  

plt.plot(x, y, 'r', label='E-Field Derivative')
plt.plot(x, y2, 'g', label = 'E-Field', linestyle='dotted')
plt.scatter(x, y2, s=3)
plt.title("Real-Time Model of the Ionospheric Electric Fields - 2 Day Samples")
plt.legend()
plt.show()
