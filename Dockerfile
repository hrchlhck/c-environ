FROM gcc:latest

LABEL maintainer="Pedro Horchulhack <pedro.horchulhack@gmail.com"

WORKDIR /opt/

ADD Makefile /opt/Makefile

RUN apt-get update -y && apt-get install cmake -y
