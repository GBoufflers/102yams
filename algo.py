#!/usr/bin/python
#-*- coding: utf-8 -*-

import math

def     algo_suite(num, chiff, de):
    if chiff < 5:
        raise Exception
    i = 0
    j = 0
    copy = list(set(num))
    if (chiff == 6):
        while i < len(copy):
            if copy[i] > 1 and copy[i] <= 6:
                j += 1
        i += 1
    if (chiff == 5):
        while i < len(copy):
            if copy[i] > 0 and copy[i] <= 5:
                j += 1
            i += 1
    print j
    if j == 0:
        ret = round(float((1 / math.pow(6, 5)) * math.factorial(5) * 100), 2)
    else:
        ret = round(float((1 / math.pow(6, 5 - j)) * math.factorial(5 -j) * 100), 2)
    print ret    

def algo(nums, chiff, de):
    i = 0
    de_ini = de
    while (i < len(nums)):
        if nums[i] == chiff:
            de -= 1
        if de == 0:
            break
        i += 1
    pourcent = float(math.factorial(5 - de_ini + de) / (math.factorial(de) * math.factorial((5 -de_ini + de) - de)))
    tmp = float((math.factorial(5 - de_ini + de) / (math.factorial(de) * math.factorial((5 -de_ini + de) - de)) - 1))
    mul = math.pow(6, 5 - de_ini + de)
    if de == 1:
        tmp = 0
    while de > 0:
        pourcent = pourcent * 1/6
        de -= 1
    pourcent = pourcent - tmp / mul
    pourcent = round(pourcent * 100, 2)
    print pourcent
    return pourcent

def algo_full(nums, chiff1, chiff2):
    i = 0
    de1 = 2
    de2 = 3
    while (i < len(nums)):
        if nums[i] == chiff1:
            de1 -= 1
        if de1 == 0:
            break
        i += 1
    i = 0
    while (i < len(nums)):
        if nums[i] == chiff2:
            de2 -= 1
        if de2 == 0:
            break
        i += 1
    if de1 > de2:
        pourcent = float(math.factorial(5 - (2 - de1) - (3 - de2)) / (math.factorial(de1) * math.factorial(5 - (2 - de1) - (3 - de2) - de1)))
    else:
        pourcent = float(math.factorial(5 - (2 - de1) - (3 - de2)) / (math.factorial(de2) * math.factorial(5 - (2 - de1) - (3 - de2) - de2)))
    de = de1 + de2
    while de > 0:
        pourcent = pourcent * 1/6
        de -= 1

    pourcent = round(pourcent * 100, 2)
    print pourcent
    return pourcent
