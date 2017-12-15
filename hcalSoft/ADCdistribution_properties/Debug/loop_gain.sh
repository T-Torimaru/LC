#!/bin/bash

echo $1

for r in `cat $1`
do

./gain_ledcalib /nfs/dust/ilc/user/ebrianne/AHCAL_TestbeamJuly2015/LED/20150705/RootFiles/$r n

echo "LED $r done"

done
