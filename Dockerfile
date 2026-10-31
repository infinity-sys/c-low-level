# C Programming For Low Level Developers: Linux x86-64 lab
FROM ubuntu:24.04
RUN apt-get update && apt-get install -y --no-install-recommends \
      gcc clang lld binutils make gdb file \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /work
CMD ["bash"]
