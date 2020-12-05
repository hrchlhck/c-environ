FROM gcc:latest

LABEL maintainer="Pedro Horchulhack <pedro.horchulhack@gmail.com"

RUN apt-get update -y && apt-get install cmake -y