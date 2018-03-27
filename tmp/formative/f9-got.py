def function(b,a):
	if(a<b):
		a=a-1
		if(a>b):
			b=b+3
			if(a==b):
				return a*b
		return b
	return 13
def main():
	return function(0,0)+function(2,1)+function(3,4)+function(7,6)

# Boilerplat
if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)

