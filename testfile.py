def a():
	return 10
def b():
	return 1
def main():
	return a()+b()

# Boilerplat
if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)

