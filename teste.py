import matplotlib.pyplot as plt
import sys
from numpy import *
from random import randint

#argv[1] - quantidade de valores
#argv[2] - onda real
#argv[3] - arquivo de entrada (onda com erros)
arq = open('%s.txt' %sys.argv[2],'w')
arq_erro = open('%s.txt' %sys.argv[3],'w')

def gera_seno():
    x = arange(0,800,1) #start, stop, step
#    y = sin(x)
    y = x
    print len(y)
    for i in range (len(y)): # len(y) = int(sys.argv[1])
        arq.write(str(y[i]))
        arq.write('\n')
    gera_ruido(y)

def gera_ruido(y):
    for i in range (len(y)): # len(y) = int(sys.argv[1])
        #valor = float(y[i]) + randint(0,5) * randint(-1,1)
        valor = randint(0,5)
        if valor < 3:
            valor = valor * randint(-1,1) + float(y[i])
        else:
            valor = float(y[i])
        arq_erro.write(str(valor))
        arq_erro.write('\n')

def main():
    gera_seno()
    #gera_ruido()
    #plt.show()
    arq.close()
    arq_erro.close()

main()
