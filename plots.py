import matplotlib.pyplot as plt
import csv
import numpy as np

a= []
b = []
c = []
x = []

with open('info.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=', ')
    for row in plots:
        x.append(int(row[0]))
        a.append(float(row[1]))
        b.append(float(row[2]))
        c.append(float(row[3]))

x = np.array(x)


plt.plot(x, a, label='Grade School')
plt.plot(x, b, label='Divide and conquer')
plt.plot(x, c, label='Karatsuba')

plt.xlabel('Length')
plt.ylabel('Time')
plt.legend()
plt.show()
