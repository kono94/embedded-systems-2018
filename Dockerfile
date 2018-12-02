FROM debian:sid

ENV HOME /root

RUN apt-get update
RUN apt-get -y install build-essential
RUN apt-get -y install elfutils libelf1 libelf-dev
RUN apt-get -y install libglib2.0-dev
RUN apt-get -y install gcc-avr gdb-avr avr-libc git simavr libsimavr-dev
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
CMD ["tail" ,"-f", "/dev/null"]