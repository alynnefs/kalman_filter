import sys
import matplotlib.pyplot as plt

arq_in = open('%s' %sys.argv[1],'r')
arq_out = open('%s' %sys.argv[2],'r')
arq_real = open('%s' %sys.argv[3],'r')

entrada = []
saida = []
real = []

for line in arq_in:
    entrada.append([line])

for line in arq_out:
    saida.append([line])

for line in arq_real:
    real.append([line])


x = [c for c in range(len(entrada))]

#print y1
print len(entrada)
print len(saida)

plt.plot(x, saida, linestyle='--', color='b', marker='s', linewidth=3.0)
plt.plot(x, entrada, linestyle='--', color='r', marker='s', linewidth=3.0)
plt.plot(x, real, linestyle='--', color='g', marker='s', linewidth=3.0)

plt.axis([0,50,0,100])

plt.xlabel(u'Tempo')
plt.ylabel(u'Valores')
plt.show()

arq_in.close()
arq_out.close()