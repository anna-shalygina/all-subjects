#!/bin/bash
case "$1" in
    build)
        mkdir -p ./Build
        g++ "$2" -o ./Build/program
        ;;
    run)
        mkdir -p ./Build
        g++ "$2" -o ./Build/program
        ./Build/program
        ;;
    clean)
        rm -rf ./Build
        ;;
esac
