#!/bin/bash

set -e

make main
make naive

rm -rf main-output
rm -rf naive-output
mkdir main-output
mkdir naive-output

test_num=$(ls ./input | wc -l)

do_test() {
	i=$1
	./main <./input/input${i}.txt >./main-output/output${i}.txt
	./naive <./input/input${i}.txt >./naive-output/output${i}.txt
	if ! diff ./main-output/output${i}.txt ./naive-output/output${i}.txt; then
		echo "wrong answer on test ${i}!"
		exit 1
	fi
	echo "passed test ${i}"
}
export -f do_test

parallel -k do_test ::: $(seq 1 ${test_num})
