def f(x):
	if(x>1):
		return x*f(x)
else:
		return x

# Boilerplat
if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)

