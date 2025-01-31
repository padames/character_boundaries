#!/usr/bin/env bash

#Prepare the credentials for git to ssh into the remote

eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519_padames
git pull
