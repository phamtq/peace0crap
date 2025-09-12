# peace0crap

![image](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![image](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

## Overview
This program downloads a distro image and check the validity and integrity without having to run a bunch of commands from the CLI. 

I thought of creating this program after reading about a hack that occurred on [February 20th, 2016](https://blog.linuxmint.com/?p=2994) that resulted in a modified Linux Mint image with a backdoor. A lot of folks either don't have the time to verify the files or they don't know how to. And like the hacker (Peace) involved in this incident said in a [ZDnet article](https://www.zdnet.com/article/hacker-hundreds-were-tricked-into-installing-linux-mint-backdoor/): 

> Who the f**k checks those anyway?

With this program, hopefully the answer is you.

## Usage

All you do is run the program with the `-d` flag and the code for a particular distro. The current version supports the following distros:

| Distro | code |
| --- | --- |
| Fedora 42 | fedora-42 |
| Arch Linux | arch |

## Installation

You'll need to install the following program and libraries from your package manager. I've listed a few of them below depending on your flavor of Linux.

| Distro | Command |
| --- | --- |
| Fedora (41+) | `sudo dnf install gnupg2 gpgme` |
| Arch Linux | `sudo pacman -Sy gnupg gpgme` |

## Feedback and Contributing

I'm open to any suggestions once the program is up and running along with any bugs you find.

## Attributions, References, Thank You's 
https://github.com/banesullivan/README  
https://github.com/alexandresanlim/Badges4-README.md-Profile?tab=readme-ov-file  
