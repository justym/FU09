#!/bin/bash
for i in {50000,100000,150000,200000,250000,300000}; do
    for j in {1,2,3,4,5}; do
        ./out ${i}
    done
done
