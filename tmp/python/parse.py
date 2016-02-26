# encoding = UTF-8
import sys
from decimal import *

#file = open(sys.argv[1], 'r')

lno = 1
is_vdo = 0
is_ado = 0

with open(sys.argv[1], 'r') as file:
	for lcontent in file: # lcontent = file.readline()
		if 'media_type=video' in lcontent:
			is_vdo = 1
			is_ado = 0
			lno = lno + 1
			continue

		if 'media_type=audio' in lcontent:
			is_vdo = 0
			is_ado = 1
			lno = lno + 1
			continue

		if is_vdo == 1:
			if 'pkt_pts_time' in lcontent: 
				for x in lcontent.split('pkt_pts_time='):
					print(lno),
					print(": "),
					print(x)

		lno = lno + 1

file.close()
