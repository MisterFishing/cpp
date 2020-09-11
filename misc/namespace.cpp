#include <iostream>
using namespace std;

namespace ns1
{
    int x=1, y=2;
}

namespace ns2
{
    int x=11, y=22;
}

int main()
{
    cout << ns1::x << " " << ns1::y << endl; 
	cout << ns2::x << " " << ns2::y << endl;
    return 0;
}

----------

#include <iostream>
using namespace std;

namespace ns1
{
    int x=1, y=2;
}

namespace ns2
{
    int x=11, y=22;
}

int main()
{
    cout << ns1::x << " " << ns1::y << endl; 
	cout << ns2::x << " " << ns2::y << endl;
	
	using namespace ns1;
	cout << x << " " << y << endl;
	
    return 0;
}

----------

#include <iostream>
using namespace std;

namespace ns1
{
    int x=1, y=2;
	
	namespace ns2
	{
		int x=11, y=22;
	}
	
}


int main()
{
    cout << ns1::x << " " << ns1::y << endl; 
	cout << ns1::ns2::x << " " << ns1::ns2::y << endl;
	
	using namespace ns1;
	cout << x << " " << y << endl;
	
    return 0;
}

----------

#include <iostream>
using namespace std;

namespace ns1
{
    int x=1, y=2;
	
	namespace ns2
	{
		int x=11, y=22;
	}
	
}


int main()
{
	int x=11111, y=22222;
    cout << ns1::x << " " << ns1::y << endl; 
	cout << ns1::ns2::x << " " << ns1::ns2::y << endl;
	
	using namespace ns1;
	using namespace ns1::ns2;
	cout << x << " " << y << endl;
	
    return 0;
}

----------

#include <iostream>
using namespace std;

namespace ns1
{
    int x=1, y=2;
	
	namespace ns2
	{
		int x=11, y=22;
	}
	
}

namespace ns3
{
    int x=111, y=222;
	
	void swap(int x, int y)
	{
		int tmp;
		tmp=x;
		x=y;
		y=tmp;
	}
	
}

int main()
{
	int x=11111, y=22222;
    cout << ns1::x << " " << ns1::y << endl; 
	cout << ns1::ns2::x << " " << ns1::ns2::y << endl;
	
	using namespace ns1;
	using namespace ns1::ns2;
	using namespace ns3;
	
	cout << x << " " << y << endl;
	swap(x,y);
	cout << x << " " << y << endl;
	
    return 0;
}

