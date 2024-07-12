# Keybot

Keybot is a simple CLI program that simulates keystrokes from a text file.

- Table of contents
  - [Usage](#usage)
  - [Requirements](#requirements)
  - [X11 Installation](#x11-installation)
  - [Build](#build)
## Usage
You can use the following options:
```bash
keybot <files> <countdown> <interval between keys> <interval between lines>
```
| Option | Description |
|-|-|
|files| files to read and write on keyboard (supports glob)|
|coundown| countdown, gives you time to place your mouse correctly in a text label|
|interval between keys|  time (ms) between key press|
|interval between lines| time (ms) between each line|

Example:
```bash
keybot *.txt 5 20 3000
  #all .txt files
  #5 seconds countdown
  #20 ms of delay between keys
  #3000 ms of delay between lines
```

Alternatively you can just type ./keybot and the program will ask you the options in a friendlier way.

## Requirements
* ``Linux`` This program was made for Linux, if you try to compile on Windows you will have problems with X11.
* ``X11`` Unix windows. See [X11 Installation](#x11-installation).
## Build
Here are the steps to compile this program.
```bash
git clone https://github.com/sop4s/keybot.git
cd keybot
mkdir build
cd build
cmake ..
cmake --build .
./keybot
```
If you have any problems compiling, check the [requirements](#requirements).

## X11 Installation
Generally X11 is installed by default.

### Ubuntu / Debian
```bash
sudo apt install libx11-dev libxtst-dev libxext-dev
```
### Fedora
```bash
sudo dnf install libX11-devel libXtst-devel libXext-devel
```
### Arch linux
```bash
sudo pacman -S libx11 libxtst libxext
```
