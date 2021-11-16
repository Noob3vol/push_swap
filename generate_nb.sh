#!/bin/bash

ARG[0]=$RANDOM
I=0


#if (( $# > 1 ))
#then
	while [ $I -lt $1 ]
	do
		ARG[$I]=$RANDOM
		I=$(( $I + 1 ))
	done
#fi

##echo ${ARG[@]}

make bonus > /dev/null

I=1
echo "${ARG[0]}" > input_tmp

while [ $I -lt $1 ]
do
	echo "${ARG[$I]}" >> input_tmp
	I=$(( $I + 1 ))
done

cat input_tmp | sort | uniq | shuf > input

INPUT=$(cat input)

echo $INPUT

#./push_swap $(cat input) > output

#diff <(./push_swap $(cat input)) <(./push_swap $(cat input) | ./checker)

#./push_swap $(cat input)

echo "-------------  push swap -----------"

#echo "Instruction : " $(./push_swap $(cat input))
echo "Instruction len : " $(./push_swap $(cat input) | wc -l)

if [[ ! -f ./checker_linux ]];
then
	echo "did not find checker_linux in directory"
else
	echo -n "checker_linux : "
	./push_swap $(cat input) 2> /dev/null | ./checker_linux $(cat input)
fi

if [[ ! -f ./checker ]];
then
	echo "did not find bonus checker in directory"
else
	echo -n "bonus checker : "
	./push_swap $(cat input) 2> /dev/null | ./checker $(cat input)
fi

#rm input input_tmp
