#!/usr/bin/env bash
count=$#
sum=0
for num in "$@"; do
    sum=$((sum + num))
done

if [ $count -gt 0 ]; then
   average=$((sum / count))
   echo "amount of args: $count"
   echo "sum: $sum"
   echo "average: $average"
else
   echo "no args"
   exit 1
fi
