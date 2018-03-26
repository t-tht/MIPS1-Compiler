def f():
	return 10
def main():
	return f(f()

# Boilerplat
if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)

