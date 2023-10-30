#!/usr/bin/python3
"""utf-8 validation"""


def validUTF8(data):
    """determines if a given dataset represents a valid UTF-8 ENCODING"""
    byte = 0

    for i in data:
        if byte == 0:
            if (i & 0b10000000) == 0:
                byte = 0
            elif (i & 0b11100000) == 0b11000000:
                byte = 1
            elif (i & 0b11110000) == 0b11100000:
                byte = 2
            elif (i & 0b11111000) == 0b11110000:
                byte = 3
            else:
                return False
        else:
            if (i & 0b11000000) != 0b10000000:
                return False
            byte -= 1

    return byte == 0
