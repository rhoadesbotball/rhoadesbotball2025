#!/usr/bin/python3
import os, sys
sys.path.append("/usr/lib")
import _kipr as k

def main():
    print ("Hello World\n")
    k.motor(0,100)
    k.motor(3,100)
    k.msleep(1000)
    

main()
