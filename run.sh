#!/usr/bin/env bash
echo "Running Container..."
docker run --name avr -v $(pwd):/app jortgies/simavr bash -c "cd /app; make development; echo 'Executing...'; ./development; echo ""; make clean"
echo "Deleting Container..."
docker rm avr