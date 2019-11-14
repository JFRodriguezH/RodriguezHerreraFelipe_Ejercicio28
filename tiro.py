import numpy as np
import matplotlib.pyplot as plt

plt.figure()
data = np.loadtxt("tiro.dat")
t = data[:,0]
x = data[:,1]
y = data[:,2]
vx = data[:,3]
vy = data[:,4]
plt.plot(x, y)
plt.savefig("tiro.png")