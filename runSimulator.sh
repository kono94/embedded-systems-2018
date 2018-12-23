#!/usr/bin/env bash
echo "Stopping potential existing 'avr' container..."
docker stop avr
echo "Removing it..."
docker rm avr
echo "Running Container..."
docker run --name avr -v $(pwd):/app jortgies/simavr bash -c "cd /app; make simulate-main; echo 'Executing...';echo ""; make clean"
echo "Deleting Container..."
docker rm avr