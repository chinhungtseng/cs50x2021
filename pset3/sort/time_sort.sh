#!/bin/bash
#
# Usage: ./time_sort.sh [size]
#
# Example: ./time_sort.sh 50000
#
# -----------sort1-----------
# sorted50000.txt  0m0.008s
# reversed50000.txt  0m9.032s
# random50000.txt  0m12.586s
#
# -----------sort2-----------
# sorted50000.txt  0m0.012s
# reversed50000.txt  0m0.012s
# random50000.txt  0m0.079s
#
# -----------sort3-----------
# sorted50000.txt  0m4.733s
# reversed50000.txt  0m4.798s
# random50000.txt  0m4.777s

set -Eeuo pipefail


algorithm=(sort1 sort2 sort3)

if [[ $# -eq 1 ]]; then
    size=$1
else
    size=10000  # Default size
fi

declare -a test_files
test_files+=("sorted${size}.txt")
test_files+=("reversed${size}.txt")
test_files+=("random${size}.txt")


for al in ${algorithm[@]}; do
    echo "-----------${al}-----------"
    for F in ${test_files[@]}; do
        (time ./${al} ${F} >/dev/null 2>&1) 2>&1 \
            | grep real | sed "s/real/${F}/" | column -t
    done
    echo
done



