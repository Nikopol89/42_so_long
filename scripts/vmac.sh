#!/bin/bash

dir=${PWD##*/}

rsync -aE ../$dir rsync://nikopol@localhost:10922/.coding/

#ssh -t -p 10922 nikopol@localhost "cd $dir ; zsh --login"