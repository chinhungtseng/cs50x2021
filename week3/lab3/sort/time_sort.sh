#!/bin/bash
#
# Usage: ./time_sort.sh [size]
#
# Example: ./time_sort.sh 50000
#
#         File            sort1           sort2           sort3
# ----------------------------------------------------------------
# sorted50000.txt         0m0.007s        0m0.012s        0m4.818s
# reversed50000.txt       0m9.048s        0m0.011s        0m4.802s
# random50000.txt         0m12.604s       0m0.071s        0m4.703s
set -Eeuo pipefail


# Set default size to 10000, if not specified size.
if [[ $# -eq 1 ]]; then
    size=$1
else
    size=10000
fi


# Get the program execute time, and extract realtime field.
function time_sort() {
    local realtime
    realtime=$((time ./${al} $1 >/dev/null 2>&1) 2>&1 | \
               grep real | sed "s/real\t//")
    echo $realtime
}


sorted="sorted${size}.txt    "
reversed="reversed${size}.txt"
random="random${size}.txt    "

# Sort programs
algorithm=(sort1 sort2 sort3)


for al in ${algorithm[@]}; do
    sorted=${sorted}"\t"$(time_sort "sorted${size}.txt")
    reversed=${reversed}"\t"$(time_sort "reversed${size}.txt")
    random=${random}"\t"$(time_sort "random${size}.txt")
done

# print the result to console.
echo
echo -e "\tFile\t\tsort1\t\tsort2\t\tsort3"
echo -e "----------------------------------------------------------------"
echo -e "$sorted"
echo -e "$reversed"
echo -e "$random"
