#include<iostream>
#include<ostream>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

struct Box 
{
    int l, b, h;

    Box() {}
    Box(int l, int b, int h)
    {
        this->l = l;
        this->b = b;
        this->h = h;
    }
    Box(Box &src)
    {
        this->l = src.l;
        this->h = src.h;
        this->b = src.b;
    }
    
    int getLength() {return l;}
    int getBreadth() {return b;}
    int getHeight() {return h;}
    long long CalculateVolume() {return (long long) l * b * h;}
    
    bool operator< (Box& b)
    {
        if (this->l < b.l)
            return true;
        else if (this->l == b.l && this->b < b.b)
            return true;
        else if (this->l == b.l && this->b == b.b && this->h < b.h)
            return true;
        return false;
    }
    
    
};
ostream& operator<<(ostream& out, Box& b)
{
    out << b.l << " " << b.b << " " << b.h ;
    return out;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}