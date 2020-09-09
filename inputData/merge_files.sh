#!/bin/bash

for pulseHeight in {106..130..1}
do
	for row in {0..248..4}
	do
	
	cat	row${row}_VCASN_98_VPULSEHIGH_${pulseHeight}_0.bin_0.bin >> row_matrix_VCASN_98_VPULSEHIGH_${pulseHeight}_0.bin_0.bin

	done
done


