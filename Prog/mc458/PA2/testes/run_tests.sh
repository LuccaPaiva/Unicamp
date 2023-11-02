#!/bin/sh

if [ -f escalada.c ]; then
    gcc -std=c99 -pedantic -Wall -O3 -o escalada *.c
elif [ -f escalada.cpp ]; then
    g++ -std=c++11 -pedantic -Wall -O3 -o escalada *.cpp
else
    echo "Arquivo de código não encontrado! Verifique o nome do arquivo."
    exit 0
fi

if [ ! -d minhas_saidas ]; then
    mkdir minhas_saidas
fi

for f in entradas/*.in;
do
    bname=`basename $f`
    ofile=`echo $bname | sed "s/\.[^\.]*$//"`
    ./escalada < $f > minhas_saidas/$ofile.out

    if diff saidas/$ofile.out minhas_saidas/$ofile.out > /dev/null; then
	echo "$bname: Correta."
    else
  	echo "$bname: Incorreta."
    fi
done
