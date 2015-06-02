class StudentCount
{
	static int nCount;
public:
	static int GetnCount();
public:
	StudentCount();
	~StudentCount();
private:
	int nAge;
};

StudentCount::StudentCount()
{
	nCount ++;
}

StudentCount::~StudentCount()
{
	nCount --;
}

int StudentCount::nCount = 0;

int StudentCount::GetnCount()
{
	return nCount;
}
