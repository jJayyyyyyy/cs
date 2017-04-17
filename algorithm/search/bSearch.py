#!/usr/bin/env python3

def b_search(arr, left, right, key):
	while left <= right:
		mid = (left + right) // 2
		if key < arr[mid]:
			right = mid - 1
		elif key > arr[mid]:
			left = mid + 1
		else:
			return mid
	return -1


def rb_search(arr, left, right, key):
	if left <= right:
		mid = (left + right) // 2
		if key < arr[mid]:
			return rb_search(arr, left, mid-1, key)
		elif key > arr[mid]:
			return rb_search(arr, mid+1, right, key)
		else:
			return mid
	else:
		return -1

a = sorted( [11, 22, 55, 44, 33, 66] )

print( b_search(a, 0, len(a)-1, 22) )
print( rb_search(a, 0, len(a)-1, 33) )
