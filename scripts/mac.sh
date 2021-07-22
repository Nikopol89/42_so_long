#!/bin/bash

dir=${PWD##*/}

rsync -aE ../$dir jmartini@bendermac:./coding/

#ssh -t jmartini@bendermac "cd ./coding/$dir ; zsh --login"