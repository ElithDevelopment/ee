#!/bin/bash

if [ -e "/usr/bin/ee" ]; then
  echo "Error: Package 'ee' already exists."
  echo "Installing to '/usr/bin/_ee...'"
  echo "Program will be executable using '_ee'."
  sudo gcc -o "/usr/bin/_ee" ./src/main.c ./src/encrypt.c ./src/decrypt.c
  if [ $? -ne 0 ]; then
    echo "Error installing to '/usr/bin/_ee'."
    exit 1
  fi
else
  sudo gcc -o "/usr/bin/ee" ./src/main.c ./src/encrypt.c ./src/decrypt.c
  if [ $? -ne 0 ]; then
    echo "Error installing to '/usr/bin/ee'."
    exit 1
  fi
fi
