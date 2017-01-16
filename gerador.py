#-*- coding: utf-8 -*-
# quantidade de números, nome do arquivo
import sys
from random import randint

arq = open('%s.txt' %sys.argv[2],'w')


for i in range(int(sys.argv[1])):
    arq.write(str(randint(0,100)))
    arq.write('\n')

arq.close()



