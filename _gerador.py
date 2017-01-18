#-*- coding: utf-8 -*-
# quantidade de números, nome do arquivo
import sys
from random import randint

#argv[1] - quantidade de valores
#argv[2] - onda real
#argv[3] - arquivo de entrada (onda com erros)

arq = open('%s.txt' %sys.argv[2],'w')
arq_erro = open('%s.txt' %sys.argv[3],'w')


for i in range(int(sys.argv[1])):
    valor = randint(0,100)
    arq.write(str(valor))
    arq.write('\n')
    arq_erro.write(str(valor+randint(0,10)))
    arq_erro.write('\n')

arq.close()
arq_erro.close()



