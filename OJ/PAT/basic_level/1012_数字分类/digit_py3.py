#!/usr/bin/env python3
# -*- coding: utf-8 -*-

us_input = []
us_input = input().split()
us_N = int(us_input[0])
us_input_len = len(us_input)

a1, a2, a3, a4, a5 = 0, 0, 0, 0, 0
multi = 1
cnt1, cnt2, cnt3, cnt4, cnt5 = 0, 0, 0, 0, 0

for i in range(1, us_input_len):
	a = int(us_input[i])
	if 0 == a%10:
		a1 += a
		cnt1 += 1
	if 1 == a%5:
		a2 += multi*a
		multi = -multi
		cnt2 += 1
	if 2 == a%5:
		a3 = a3 + 1
		cnt3 += 1
	if 3 == a%5:
		a4 = a4 + a
		cnt4 += 1
	if 4 == a%5:
		if a>a5:
			a5 = a
		cnt5 += 1

if 0 == cnt1:
	a1 = 'N'
if 0 == cnt2:
	a2 = 'N'
if 0 == cnt3:
	a3 = 'N'
if 0 == cnt4:
	a4 = 'N'
else:
	a4 = round(a4/cnt4, 1)
if 0 == cnt5:
	a5 = 'N'

print(a1, a2, a3, a4, a5)

