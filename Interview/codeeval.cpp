#include"codeeval.hpp"



bool isPrime(int x)
{
	for(int i=3;i<=sqrt(x);i+=2){
		if(x%i==0 && x!=i)
		{
			return false;
		}
	}
	return true;
}
void sumofprimes(int n)
{
	// returns the sum of first n primes
	int sum=2,cnt=1;
	int i=1;
	while(cnt<n)
	{
		i+=2;
		if(isPrime(i)){
			cnt++;
			sum+=i;
		}
		
	}
	std::cout<<sum<<std::endl;

}
void isPrimeArray(std::vector<int> &ary)
{
	//creates an array of prime numbers
	int n = ary.size();
	for(int i=2;i<n;i++)
		ary[i] = 1;
	for(int i=2;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ary[j]){
				if(j%i==0)
					ary[j]=0;
			}
		}

	}
	ary[2]=1,ary[3]=1,ary[5]=1,ary[7]=1;
}
bool isPalindrome(int n)
{
	int num = n;
	int rev = 0;
	int dig;
	while(n >0)
	{
		dig = n%10;
		rev =rev*10+dig;
		n /=10;
	}
	return num==rev;
}
void largestPalindromPrime(int n)
{
	std::vector<int> ary(n,0);
	isPrimeArray(ary);//generates the prime number array

	for(int i=n;i--;)
	{
		if(isPalindrome(i) && ary[i])
		{
			std::cout<<i<<std::endl;
			break;
		}

	}
}
void fizzbuzz()
{
	std::ifstream stream("C:/Users/sshivakumar/Desktop/data.txt");
	std::string line;
	int x,y,n;
	while(stream >> x >> y >> n)
	{
		for(int i=1;i<=n;i++)
		{
			if(i%x == 0 && i%y == 0)
				std::cout<<" FB";
			else if(i%x == 0)
				std::cout<<" F";
			else if(i%y == 0)
				std::cout<<" B";
			else
				std::cout<<" "<<i;
		}
		std::cout<<std::endl;
	}
}
void find_bounds(int *a,int size, int val)
{
	int beg = 0, end = size-1;
    // searching upper bound
    while(beg < end) {
        int mid = (beg+end)/2;
        if(!(a[mid] > val)) {
            beg = mid+1;
        } else {
            end = mid;
        }
    }
    int upper_bnd = beg;
    
    beg = 0, end = size-1;
    while(beg < end) {
        int mid = (beg + end)/2;
        if(a[mid] < val) {
            beg = mid+1;
        } else {
            end = mid;
        }
    }
    int lower_bnd = beg;
    
    printf("[%d; %d]\n", val, upper_bnd-lower_bnd);
}
void findFrequency()
{
	/*
	@Statement - Given a sorted array, find the number of occurances of a number in less than O(n)
	*/
	int array[7] = {1,1,2,3,3,4,5};
	int val = 4;

	find_bounds(array,7,val);// use binary search --O(logn)
}
void upper2lower()
{
	std::ifstream stream("C:/Users/sshivakumar/Desktop/data.txt");
	std::string line;
	while(getline(stream,line))
	{
		char *s = new char[line.length()];
		strcpy(s,line.c_str());
		for(unsigned int i=0;i<line.length();i++)
		{
			if(s[i]>=65 && s[i]<=90)
				s[i] = s[i]+32;
			std::cout<<s[i]<<std::endl;
		}
		
	}

}
void sumofdigits()
{
	std::ifstream stream("C:/Users/sshivakumar/Desktop/data.txt");
	std::string line;
	while(getline(stream,line))
	{
		int x = std::stoi(line.data());
		int digit=0;
		while(x)
		{
			digit += x%10;
			x/=10;

		}
		std::cout<<digit<<std::endl;
		
		
	}
}
int fibb(int x)
{
	if(x==0)
		return 0;
	if(x==1)
		return 1;
	return fibb(x-1)+fibb(x-2);

}
void fib()
{
	std::ifstream stream("C:/Users/sshivakumar/Desktop/data.txt");
	std::string line;
	while(getline(stream,line))
	{
		int x = std::stoi(line.data());
		std::cout<<fibb(x)<<std::endl;				
	}

}
void multable()
{
	for(int i=1;i<13;i++){
		for(int j=1;j<13;j++){
			printf("%4d",i*j);
		}
		std::cout<<std::endl;
	}
}
void sumofint()
{
	std::ifstream stream("C:/Users/sshivakumar/Desktop/data.txt");
	std::string line;
	int x;
	int sum=0;
	while(stream >> x )
	{
		sum+=x;
	}
	std::cout<<sum;
}
void filesize()
{
	std::streampos fsize=0;
	std::ifstream stream("C:/Users/sshivakumar/Desktop/data.txt");
	std::string line;

	fsize = stream.tellg();
	stream.seekg(0,std::ios::end);
	fsize = stream.tellg() - fsize;
	stream.close();

	std::cout<<fsize;
}
void removeduplicates()
{
	std::ifstream stream("C:/Users/sshivakumar/Desktop/data.txt");
	std::string line;
	std::vector<int> x;
	while(getline(stream,line))
	{
		int data = std::stoi(line.data());
		x.push_back(data);	
		
	}

}

void codeeval()
{
	//findFrequency();
	//fizzbuzz();
	//largestPalindromPrime(1000);
	//sumofprimes(1000);
	//upper2lower();
	//sumofdigits();
	//fib();
	//multable();
	//sumofint();
	filesize();
	//removeduplicates();
}