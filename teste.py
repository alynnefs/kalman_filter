import matplotlib.pyplot as plt
from numpy import *
x = arange(0.0,10.0,0.0000001) #start, stop, step
y = sin(2*pi*x)
plt.plot(x,y)
plt.show()