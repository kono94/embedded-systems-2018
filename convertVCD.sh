#!/usr/bin/env bash
input=$2;
output_file="$1.vcd";
time=600000;

echo "\$date $(date) \$end
\$comment
  This file specifies one-bit input for tests.
  SIMAVR does only take micro seconds.
  input: $2
\$end
\$timescale 1us \$end
\$scope module logic \$end
\$var wire 1 c iogC_1 \$end
\$upscope \$end
\$enddefinitions \$end
\$dumpvars
xc
\$end" > "./$output_file"

counter=0
while read -n1 character; do
    counter=$((counter+1))
    echo "$character"
    if [[ "$character" = "1" ]]
    then
        printf "#$time\n1c\n#$((time+200000))\n0c\n" >> "./$output_file"
    fi
    if [[ "$character" = "0" ]]
    then
        printf "#$time\n1c\n#$((time+100000))\n0c\n" >> "./$output_file"
    fi
       if [[ "$character" = "-" ]]
    then
        printf "#$time\n0c\n#$((time+1000000))\n0c\n" >> "./$output_file"
    fi
      time=$((time+1000000));
done < <(echo -n "$2")

printf "#$(echo "1000000*(121-counter)" | bc -l)\n1c" >> "./$output_file"

echo "done"