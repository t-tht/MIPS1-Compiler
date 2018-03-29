def a(x):
	return x+1
def b(x):
	return a(x+1)
def main():
	return b(2)+a(2)

# Boilerplat
if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)

