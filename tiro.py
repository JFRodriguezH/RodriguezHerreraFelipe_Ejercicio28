import numpy as np
import matplotlib.pyplot as plt

plt.figure()
data = np.loadtxt("tiro.dat")
t = data[:,0]
x = data[:,1]
y = data[:,2]
vx = data[:,3]
vy = data[:,4]
plt.plot(x, y, label="Sin fricción")
data = np.loadtxt("friccion.dat")
t = data[:,0]
x = data[:,1]
y = data[:,2]
vx = data[:,3]
vy = data[:,4]
plt.plot(x, y, label="Con fricción")
plt.legend(loc="upper right")
plt.ylabel("Y")
plt.xlabel("X")
plt.savefig("friccion.png")