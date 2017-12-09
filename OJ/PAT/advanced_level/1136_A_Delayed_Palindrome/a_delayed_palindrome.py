def get_rev(num):
	return int((str(num))[::-1])

def main():
	s = input()
	num = int(s)
	rnum = get_rev(num);

	for cnt in range(10):
		if num == rnum:
			break
		else:
			res = num + rnum
			print("%d + %d = %d" % (num, rnum, res))
			num = res
			rnum = get_rev(num)

	if num == rnum:
		print("%d is a palindromic number." % num)
	else:
		print("Not found in 10 iterations.")

main()