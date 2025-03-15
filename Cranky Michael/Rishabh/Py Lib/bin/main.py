#!/usr/bin/python3
import os, sys
sys.path.append("/usr/lib")
import _kipr as k
#analog
def analog(port):
    k.analog(port)
#camera
def camera_open():
    k.camera_open
def camera_load_config(config):
    k.camera_load_config(config)
def camera_update():
    k.camera_update()
def get_channel_count():
    k.get_channel_count
def get_object_count(channel):
    k.get_object_count(channel)
def get_object_data(channel, obj):
    k.get_object_data(channel, obj)
def get_object_area(channel, obj):
    k.get_object_area(channel, obj)
def get_object_bbox(channel, obj):
    k.get_object_bbox(channel, obj)
def get_object_center(channel, obj):
    k.get_object_center(channel, obj)
def get_object_center_x(channel, obj):
    k.get_object_center_x(channel, obj)
def get_object_center_y(channel, obj):
    k.get_object_center_y(channel, obj)
def camera_close():
    k.camera_close()
#
def main():
    print ("Hello World")
    

main()
