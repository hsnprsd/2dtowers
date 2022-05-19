#!/bin/bash

set -e

make generate-input

WIDTH=50
HEIGHT=50

generate_input() {
	i=$1
	echo "${WIDTH} ${HEIGHT}" | ./generate-input ${RANDOM} > ./input/input${i}.txt
}
export -f generate_input

rm -rf ./input
mkdir ./input
for i in $(seq 1 100); do
	generate_input $i &
done
wait
