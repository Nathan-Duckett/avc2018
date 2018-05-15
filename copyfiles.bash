#!/bin/bash
$ip = 10.140.30.15
cd ../
scp -r avc2018-master pi@$ip /pi/home/Desktop
echo Files copied over