#-*- coding: utf-8 -*-
from random import randint

arq = open('valores.txt','w')

qtde = int(raw_input("Digite a quantidade de números\n"))

for i in range(qtde):
    arq.write(str(randint(0,1000)/100.0))
    arq.write(', ')

arq.close()



