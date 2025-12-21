# Ubuntu Dev Container (macOS + Docker)

Run an Ubuntu shell on macOS using Docker. Works for quick Python runs and C/C++ builds.

## 0) Clone the repo
```bash
git clone <your-repo-url>
cd Project---compiler
```

## 1) First-time setup
- Install Docker Desktop for Mac and start it.
- From this folder, build the image:
  ```bash
  docker build -t compilation-ubuntu .
  ```
- Launch the container the first time (bind-mounts this folder into `/workspace`):
  ```bash
  docker run -it --name compilation-dev -v "$(pwd)":/workspace compilation-ubuntu
  ```

## 2) Start it again later
Reuse the same container (keeps your shell history and packages added inside it):
```bash
docker start -ai compilation-dev
```

## 3) Run code inside Ubuntu
Inside the container shell:
- Python: `python3 test.py`
- C: `gcc -o app main.c && ./app`
- C++: `g++ -std=c++17 -o app main.cpp && ./app`
Your macOS files stay in `/workspace`.

### Build and run the compiler (inside the container)
```bash
cd /workspace/Project
bison -d -o proj.tab.c proj.y
flex -o lex.yy.c proj.l
gcc -o proj lex.yy.c proj.tab.c -lfl
./proj < sample.txt
./proj < test.txt
```

## Native macOS build (no Docker)
```bash
brew install flex bison
cd Project
bison -d -o proj.tab.c proj.y
flex -o lex.yy.c proj.l
gcc -o proj lex.yy.c proj.tab.c -ll
./proj < sample.txt
./proj < test.txt
```

## 4) Reset (fresh container)
If the container breaks or you want a clean slate:
```bash
docker stop compilation-dev  # if running
docker rm compilation-dev
docker rmi compilation-ubuntu  # optional: rebuild next time
```
Then repeat the first-time setup. Files in your project folder remain on macOS. 
