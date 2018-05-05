#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<fstream>
using namespace std;
#define pi 3.14149265358979323846
class user{
private:
    string username;
    string username1;
    string password;
    string password1;
public:
    string name;
    int lt;
    int lg;
    int login();
    int signup();
    };
int user::login()
{
    int a=0;
    string line;
    ifstream user("user.txt");
    cout <<"\nEnter Username: ";
    cin >> username;
    cout <<"\nEnter Password: ";
    int LEN=0;
    password ="";
    char c;
    do
    {
        int c = getch();
        switch (c)
            {
                case 0:
                getch();
                break;
                case '\b':
                if (password.length())
                {
                    cout << "\b \b";
                    password.erase( password.end() -1 );
                    LEN--;
                }
                break;
                default:
                if (isalnum( c ) || ispunct( c ))
                {
                    cout << "*";
                    password.push_back( c );
                }
            LEN++;
            }
        }
    while (LEN<5);
    while(!user.eof())
    {   user>>username1;
        user>>password1;
        user.ignore();
        if((username == username1) && (password == password1))
        {
            cout <<"\nLogin Successfully!"<< endl;
            a=1;
            break;
        }
    }
    if(a==1)
        return true;
    else
        return false;
}
int user::signup()
{
    cout<<"\nEnter your Username\t";
    cin>>username1;
    cout<<"\nEnter your password\t";
    cin>>password1;
    ofstream users;
    users.open("User.txt",ios::app);
    users<<"\n"<<username1<<" "<<password1;
    users.close();
}
class city : public user{
public:
    double distance(double,double,double,double);
    void create_details();
    void display_details();
}c;
struct node
	{
		string name;
		string name1;
		int lt1,lt2;
		int data;
		struct node *left;
		struct node *right;
		struct node *root;
	};
	struct node *newNode(string name);
	struct node *insertNode(struct node* node, string name);
	struct node *seach(struct node* node, string name);

struct node *newNode(string name)
{
    struct node *node = (struct node *) malloc (sizeof(struct node));
    node->name = name;
    node->left = node->right = NULL;
    return node;
}


struct node *insert(struct node *node,int data)
{
    if(node==NULL)
    {
        struct node *temp;
        temp=new struct node;
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(data >(node->data))
    {
        node->right = insert(node->right,data);
    }
    else if(data < (node->data))
    {
        node->left = insert(node->left,data);
    }
    return node;
    }


struct node *search(struct node *node,int data)
{
int data1;
int lt1,lt2;
if(node!=NULL)
{
if(data==node->data)
{
 ifstream read;
 read.open("city.txt");
 read>>data1,lt1,lt2;
 if(data==data1)
 {
 c.display_details();
 }
 read.close();
}
else if((data) < (node->data))
 search(node->left,data);
else
 search(node->right,data);
}
else
printf("\n CITY DOESN'T EXIST");
}

void city::create_details()
{
    ofstream write;
    write.open("city.txt",ios::app);
	cout<<"\n Name ";
	cin>>name;
	cout<<"\n Latitude ";
	cin>>lt;
	cout<<"\n Longitude ";
	cin>>lg;
    write<<name<<","<<lt<<","<<lg<<"\n";
	write.close();
}

void city::display_details()
{
	cout<<"NAME : "<<name;
	cout<<"LATITUDE : "<<lt;
	cout<<"LONGITUDE : "<<lg;
}

double city::distance(double lt,double lg,double lt1,double lg1)
{
    double theta,dist;
	double deg2rad(double);
	double rad2deg(double);
	theta=lg-lg1;
	dist=sin(deg2rad(lt))*sin(deg2rad(lt1))+cos(deg2rad(lt))*cos(deg2rad(lt1))*cos(deg2rad(theta));
	dist=acos(dist);
	dist=rad2deg(dist);
	dist=dist*60*1.1515;
	dist=dist*1.609344;
	return dist;
}
double deg2rad(double deg){
return (deg*pi/180);
}
double rad2deg(double rad){
return (rad*180/pi);
}
int main()
{
    struct node *root=NULL;
    int lt,lg,lt1,lg1;
    user us;
    int choice;
    while(1)
    {
        login:
        cout<<"Enter your choice";
        cout<<"\n1.LOGIN\n2.SIGN UP\n3.EXIT";
        cin>>choice;
        switch(choice)
        {
            case 1:if(us.login());
                    while(1)
                    {

                        int ch;
                        int code;
                        cout<<"\n Enter your choice";
                        cout<<"\n1.Create\t2.Search and display\t3.Distance between two cities\t4.Exit";
                        cin>>choice;
                        switch(choice)
                        {
case 1:
cout<<"CHENNAI  21         \t";
cout<<"KANCHIPURAM  22     \t";
cout<<"VELLORE 15         \t";
cout<<"DHARMAPURI 12      \t";
cout<<"THIRUVANNAMALAI 16 \t";
cout<<"ERODE 2            \t";
cout<<"COIMBATORE 1       \t";
cout<<"SALEM 13           \t";
cout<<"NAMMAKAL 14        \t";
cout<<"KARUR 5            \t";
cout<<"DINDIGUL 4         \t";
cout<<"THENI 3            \t";
cout<<"THIRICHIRAPALLI 8  \t";
cout<<"MADURAI 6          \t";
cout<<"VIRUDHUNAGAR 7     \t";
cout<<"RAMANATHAPURAM 11  \t";
cout<<"THOOTHUKUDI 10     \t";
cout<<"KANYAKUMARI 9      \t";
cout<<"VILUPURAM 18       \t";
cout<<"CUDDALORE 19       \t";
cout<<"NAGAPATINAM 20     \t";
cout<<"PERAMBALUR 17      \n;";


                                   cout<<"\nEnter the city to be inserted";
                                   cin>>code;
                                   c.create_details();
                                    root=insert(root,code);
                                   break;
                            case 2:cout<<"\n Enter the code of the city to be searched";
                                   cin>>code;
                                   root=search(root,code);
                                   break;
                            case 3:cout<<"Enter city1 Latitude and Longitude";
                                   cin>>lt>>lg;
                                   cout<<"Enter city2 Latitude and Longitude";
                                   cin>>lt1>>lg1;
                                   cout<<c.distance(lt,lg,lt1,lg1)<<"KM\n";
                                   break;
                            case 4:goto login;
                                   break;
                        }
                    }
                    break;
            case 2:us.signup();goto login;
                    break;
            case 3:return 0;
        }
    }
}
