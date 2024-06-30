# Keybot

Keybot is a simple CLI program that simulates keystrokes from a text file.

## Index
[Usage](#markdown-header-usage)

[Installation](#markdown-header-installation)

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

## Installation

```bash
mkdir build
cd build
cmake ..
cmake --build .
./keybot
```
