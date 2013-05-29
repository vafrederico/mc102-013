###########################################################
# Created: Ter 21 Mai 2013 11:06:24 BRT
#
# Author: Carla N. Lintzmayer, carlanl@ic.unicamp.br
#
###########################################################

#!/bin/bash


# Fazendo leitura dos parâmetros:

self="${0##*/}"
turma=${1:?"Uso: ./$self <turma> <laboratorio> <executavel>"}
lab=${2:?"Uso: ./$self <turma> <laboratorio> <executavel>"}
executavel=${3:?"Uso: ./$self <turma> <laboratorio> <executavel>"}

# Fazendo download dos arquivos:

if [ ! -d "testes-lab12b" ]; then
    mkdir testes-lab12b
fi

for (( i=1; i<=10; i++ )); do
    input1="arq$(printf '%02d' $i).in1"
    input2="arq$(printf '%02d' $i).in2"
    result="arq$(printf '%02d' $i).res"

    if [ ! -f "testes-lab12b/$input1" ]; then
    	wget -P testes-lab12b https://susy.ic.unicamp.br:9999/mc102$turma/$lab/dados/$input1 --no-check-certificate > lixo
    	wget -P testes-lab12b https://susy.ic.unicamp.br:9999/mc102$turma/$lab/dados/$input2 --no-check-certificate > lixo
	    wget -P testes-lab12b https://susy.ic.unicamp.br:9999/mc102$turma/$lab/dados/$result --no-check-certificate > lixo
        rm lixo
    fi
done


# Executando os testes:
cd testes-lab12b

for (( i=1; i<=10; i++ )); do
    arq="arq$(printf '%02d' $i)"
    .././$executavel $arq.in1 < $arq.in2 $arq.out
done


# Comparando os resultados:
erros=0
for (( i=1; i<=10; i++ )); do
    arq="arq$(printf '%02d' $i)"

    cmp=$(diff $arq.res $arq.out)

    if [ "$cmp" != "" ]; then
        echo
        echo "==============="
        echo "Erro encontrado ao testar $executavel com arquivos de entrada $arq.in1 e $arq.in2"
        echo ">> Seu arquivo binário difere do esperado."
        echo "==============="
        erros=$(($erros+1))
    fi

    rm $arq.out
done

echo
echo "Total de erros encontrados: $erros"
cd ../
