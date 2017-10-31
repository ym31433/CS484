#!/bin/bash

for i in `seq 1 10`;
do
	qsub batch_script.run
done
