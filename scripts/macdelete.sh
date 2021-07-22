#!/bin/bash

dir=${PWD##*/}

rsync -aE --delete ../$dir jmartini@bendermac:./coding/

#ssh -t jmartini@bendermac "cd ./coding/$dir ; zsh --login"