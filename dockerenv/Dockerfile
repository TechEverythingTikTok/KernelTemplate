FROM debian:12

# Setup enviroment
RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y gcc make nasm xorriso grub-pc-bin grub-common && \
    rm -rf /var/lib/apt/lists/*

VOLUME /root/env
WORKDIR /root/env
