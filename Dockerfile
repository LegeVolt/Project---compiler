FROM ubuntu:22.04

# Basic tools + compilers + Python
RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    flex \
    bison \
    cmake \
    gdb \
    python3 \
    python3-pip \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Work directory inside the container
WORKDIR /workspace

# Start with a shell
CMD ["/bin/bash"]
