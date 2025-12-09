# Simple Docker Compilation Environment

This folder contains a minimal Docker-based Ubuntu environment for running Python scripts and compiling C/C++ code.

Use this when you want a clean Linux setup without installing compilers directly on your Mac.

---

## How to Build the Docker Image

Run this inside the folder that contains the Dockerfile:

```bash
docker build -t compilation-ubuntu .

How to Start the Container

This command opens an Ubuntu shell and mounts your Mac folder into /workspace:


docker run -it --name compilation-dev -v "$(pwd)":/workspace compilation-ubuntu

Inside the container, you will see your files under:
/workspace


How to Enter the Container Again Later

No need to rebuild or re-run the full command.

Just run:
docker start -ai compilation-dev