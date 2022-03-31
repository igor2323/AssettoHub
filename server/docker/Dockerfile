FROM ubuntu:20.04

COPY . /root/server/

RUN apt -y update && \
    apt -y upgrade && \
    apt -y install build-essential && \
    apt -y install gcc-snapshot gcc g++ && \
    apt -y install qt5-qmake && \
    apt -y install qt5-default 

RUN cd /root/server/
RUN qmake echoServer.pro && \
    make && \
    ./echoServer


