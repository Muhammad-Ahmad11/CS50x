#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Header.h"

using namespace std;
class Date;
class obj;
class comment;
class users;
class Page;
class post;
class activity;

obj::obj() {
	id = 0;
}
int obj::getid() {
	return id;
}
void obj::setid(int x) {
	id = x;
};
Page::Page() {
	count = 0;
	likedpeople = new user * [20];
	posts = new activity * [20];
	postsids = new int[10];
	for (int i = 0; i < 20; i++) {
		likedpeople[i] = nullptr;
		posts[i] = nullptr;
	}
	for (int i = 0; i < 10; i++) {
		postsids[i] = 0;
	}

	name = "";
};
void Page::setid(int x) {
	obj::setid(x);

}
Page::Page(string names) {

	this->name = names;
};
void Page::setname(string a) {
	name = a;
}
string Page::getname() {
	return name;
}
void Page::setusers(user& obj) {
	static int x = 0;
	likedpeople[x] = &obj;
	x++;
}
activity* Page::getposts(int a) {
	return posts[a];
}
void Page::setposts(activity& obj) {
	static int x = 0;
	posts[x] = &obj;
	x++;
}
void Page::print() {
	cout << getname() << endl;
	cout << "----------------------------------------------" << endl;
	for (int i = 0; i < 10; i++) {
		if (posts[i] != nullptr) {
			posts[i]->print();
		}
	}
}
user::user() {
	countposts = 0;
	countfriends = 0;
	countpages = 0;
	firstname = "";
	lastname = "";
	pages = new Page * [10];
	friends = new user * [10];
	posts = new activity * [10];
	pagesids = new int[10];
	userids = new int[10];
	postsids = new int[10];
	activityx = 0;

	for (int i = 0; i < 10; i++) {
		pagesids[i] = 0;
		userids[i] = 0;
		postsids[i] = 0;
	}

	for (int i = 0; i < 10; i++) {
		pages[i] = nullptr;
		friends[i] = nullptr;
		posts[i] = nullptr;
	}


}
user::user(string ids, string lname, string fname) {
	this->firstname = fname;
	this->lastname = lname;
	pages = new Page * [10];
	for (int i = 0; i < 10; i++) {
		pages[i] = nullptr;
	}


}
void user::setnames(string a, string b) {
	firstname = a;
	lastname = b;

}
void user::Timeline() {
	for (int i = 0; i < 10; i++) {
		if (posts[i] != nullptr) {
			posts[i]->print();
			cout << "...(";
			cout << posts[i]->getsharedpostDate()->getday() << "/";
			cout << posts[i]->getsharedpostDate()->getmonth() << "/";
			cout << posts[i]->getsharedpostDate()->getyear() << ")";
			cout << endl;
		}

	}


}
string user::getnames() {
	cout << "        ";
	return firstname;
}

void user::setid(int x) {
	obj::setid(x);

}
void user::printfriends() {
	cout << "Friends List : " << endl;
	cout << endl;
	for (int i = 0; userids[i] > 0; i++) {
		cout << "u" << friends[i]->obj::getid() << "--  ";
		cout << friends[i]->firstname << "  " << friends[i]->lastname << endl;

	}

}
string user::getfname() {
	string fullname = firstname + " " + lastname;
	return fullname;
}
void user::printposts() {
	for (int i = 0; i < 10; i++) {
		if (posts[i] != nullptr) {
			posts[i]->print();

		}
	}

}
void user::printlikedpages() {
	cout << "Liked Pages : " << endl;
	cout << endl;
	for (int i = 0; pagesids[i] > 0; i++) {
		cout << "p" << pages[i]->obj::getid() << "--  ";
		cout << pages[i]->getname() << endl;

	}

}

void user::HOmepage(int day, int m, int y) {

	cout << "=======================" << endl;
	int cid = 7;

	for (int i = 0; i < 10; i++) {
		if (posts[i] != nullptr)
		{
			int d = posts[i]->getsharedpostDate()->getday();
			int month = posts[i]->getsharedpostDate()->getmonth();
			int year = posts[i]->getsharedpostDate()->getyear();
			if (d == day || d == (day - 1) && month == m && year == y)
			{
				posts[i]->print();
				cout << d << " /" << month << "/" << year << "\n";
				cout << endl << endl;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (friends[i] != nullptr) {
			for (int j = 0; j < 10; j++)
				if (friends[i]->posts[j] != nullptr)
				{
					int d = friends[i]->posts[j]->getsharedpostDate()->getday();

					int month = friends[i]->posts[j]->getsharedpostDate()->getmonth();

					int year = friends[i]->posts[j]->getsharedpostDate()->getyear();
					if (d == day || d == (day - 1) && month == m && year == y)
					{
						friends[i]->posts[j]->print();
						cout << d << " /" << month << "/" << year << "\n";
						cout << endl << endl;
					}
				}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (pages[i] != nullptr) {
			for (int j = 0; j < 10; j++)
				if (pages[i]->getposts(j) != nullptr)
				{
					int d = pages[i]->getposts(j)->getsharedpostDate()->getday();
					int month = pages[i]->getposts(j)->getsharedpostDate()->getmonth();
					int year = pages[i]->getposts(j)->getsharedpostDate()->getyear();
					if ((d == day || d == (day - 1)) && month == m && year == y)
					{
						pages[i]->getposts(j)->print();
						cout << d << " /" << month << "/" << year << "\n";
						cout << endl << endl;
					}
				}
		}
	}


}


void user::setposts(activity& obj) {


	posts[activityx] = &obj;
	activityx++;

}
string user::getlname() {
	return lastname;
}
void user::setfriends(user& obj) {


	friends[countfriends] = &obj;
	countfriends++;

}
void user::setpages(Page& obj) {


	pages[countpages] = &obj;
	countpages++;
}









Date::Date()
{
	month = 0;
	day = 0;
	year = 0;
}
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
void Date::setday(int d)
{
	day = d;
}
int Date::getday()
{
	return day;
}
void Date::setmonth(int m)
{
	month = m;
}
int Date::getmonth()
{
	return month;
}
void Date::setyear(int y)
{
	year = y;
}
int Date::getyear()
{
	return year;
}
void Date::print() {
	cout << day << "/" << month << "/" << year << endl;
}

comment::comment()
{

	users = nullptr;
	pagename = nullptr;
	count = 0;

	des = "";
}
comment::comment(string des, user** users)
{
	this->des = des;
	users = nullptr;
	page = nullptr;
}
void comment::setid(int id)
{
	obj::setid(id);
}
void comment::setdes(string des)
{
	this->des = des;
}
string comment::getdes()
{
	return des;
}
void comment::setusers(user& obj)
{

	users = &obj;

}


void comment::setpagename(Page& obj) {
	page = &obj;

}
void comment::print()
{
	if (users != nullptr) {
		cout << users->getfname() << ":  ";
	}
	else if (page != nullptr) {
		cout << page->getname() << ":  ";
	}
	cout << getdes() << endl;

}


Post::Post()
{
	countlikedpeople = 0;
	countlikedpages = 0;
	countcomments = 0;
	count = 0;
	description = "";
	likedpostsbyuser = new user * [5];
	likedpostbypage = new Page * [5];
	sharedpostbyuser = nullptr;
	sharedpostbypage = nullptr;
	for (int i = 0; i < 5; i++) {
		likedpostbypage[i] = nullptr;
		likedpostsbyuser[i] = nullptr;
	}
	commids = new int[10];
	commid = new comment * [12];
	for (int i = 0; i < 12; i++)
	{
		commid[i] = nullptr;
	}
	for (int i = 0; i < 10; i++) {
		commids[i] = 0;
	}
}
Post::Post(string des, user** likedposts)
{

	description = des;
	likedposts = new user * [11];

	for (int i = 0; i < 11; i++)
	{
		likedposts[i] = new user[4];
	}



}
void Post::setusercommentid(comment& obj)
{

	commid[countcomments] = &obj;
	countcomments++;

}
void Post::setlikedpost(Page& obj) {


	likedpostbypage[countlikedpages] = &obj;
	countlikedpages++;
}
void Post::setlikedpost(user& obj) {

	likedpostsbyuser[countlikedpeople] = &obj;
	countlikedpeople++;
}
void Post::setdate(Date& d) {
	shareddate = &d;
}
void Post::setsharedpost(user& obj) {
	sharedpostbyuser = &obj;
}
void Post::setsharedpost(Page& obj) {
	sharedpostbypage = &obj;
}
user* Post::getsharedpostbyuser() {
	return sharedpostbyuser;
}
Date* Post::getsharedpostDate() {
	return shareddate;
}
Page* Post::getsharedpostbypage() {
	return sharedpostbypage;
}


void Post::setdes(string des)
{
	this->description = des;
}


void Post::setid(int x) {
	obj::setid(x);

}
string Post::getdescription()
{
	return description;
}
void Post::printdate() {
	shareddate->print();
}
void Post::print2()
{
	for (int i = 0; i < 12; i++) {
		if (commid[i] != nullptr) {
			commid[i]->print();
		}
	}
}
void Post::likes() {
	cout << "Post liked by : " << endl;
	for (int i = 0; i < 5; i++) {
		if (likedpostbypage[i] != nullptr) {
			cout << likedpostbypage[i]->getname();
			cout << endl;
		}
		if (likedpostsbyuser[i] != nullptr) {
			cout << "        " << likedpostsbyuser[i]->getfname();
			cout << endl;
		}

	}

}
void Post::print() {


	cout << "''";
	cout << getdescription();
	cout << "''";
	cout << endl;

	cout << "Comment section:" << endl;
	for (int i = 0; i < 12; i++) {
		if (commid[i] != nullptr) {
			commid[i]->print();
		}
	}

}

activity::activity() {
	type = 0;
	value = "";
}
void activity::setvalue(string des)
{
	value = des;
}
int activity::gettype() {

	return type;

}
string activity::getvalue() {
	return value;
}

void activity::settype(int x) {
	type = x;
}
void activity::search(string name, activity* posts, user* u, Page* pages, comment* arr_comm) {
	int userids[10] = { 0 };
	int pageids[10] = { 0 };
	int found = -1;
	string description;
	cout << "Search for : " << name << endl;;
	cout << endl;
	for (int i = 0; i < 20; i++) {
		found = -1;
		string description = u[i].getfname();
		found = description.find(name);

		if (found == -1) {

		}
		else {
			cout << "p" << u[i].obj::getid() << "--  ";
			cout << u[i].getfname() << endl;
		}
	}

	string pagename;


	for (int i = 0; i < 11; i++) {
		found = -1;
		description = posts[i].getdescription();
		found = description.find(name);
		if (found == -1) {

		}
		else {

			posts[i].print();
		}

	}

	for (int i = 0; i < 12; i++) {
		found = -1;
		pagename = pages[i].getname();
		found = pagename.find(name);
		if (found == -1) {

		}
		else {
			cout << "p" << pages[i].obj::getid() << "--  ";
			cout << pages[i].getname() << endl;
		}

	}
}
void activity::run(activity* posts, user* u, Page* page, comment* arr_com, int noofcomms) {
	cout << "\n\n******************************Welcome******************************\n\n";
	cout << "Please select the current user for this application first to continue:\n ";
	for (int i = 0; i < 20; i++)
	{
		cout << i << "." << u[i].getfname() << endl;
	}
	int id = 0;
	do
	{
		cout << "\nEnter id no.:";
		cin >> id;
	} while (id < -1 && id > 20);

	cout << "Comand : " << "   " << "set users(u" << id << ")" << endl;
	cout << u[id].getfname() << " succesfully set as current user" << endl;
	int m = 9;
	int y = 2021;
	int day = 13;
	int choice = 0;
    cout << endl;
	do {
		cout << "Enter 1 for  viewing friends of current user\n";
		cout << "Enter 2 for viewing liked pages\n";
		cout << "Enter 3 for view the likes of any post you want\n";
		cout << "Enter 4 if you want to like any post\n";
		cout << "Enter 5 for viewing timeline liked\n";
		cout << "Enter 6 for viewing any page\n";
		cout << "Enter 7 for viewing homepage\n";
		cout << "Enter 8 to comment on any post\n";
		cout << "Enter 9 to view any post\n";
		cout << "Enter 10 to share any post\n";
		cout << "Enter 11 to search any word in any post you want to find that post\n";
		cout << "Enter -1 to exit\n";
		cin >> choice;
		if (choice == 1) {
			cout << "Command" << "    " << "view Friends " << endl;//id=7 so we will write (id-1)=6 as array start from 0
			int user_id = 0;
			do {
				cout << "Enter user id whose friends you want to view:";
				cin >> user_id;
			} while (user_id < -1 && user_id > 20);
			u[user_id].printfriends();
			cout << "\n--------------------------------------------------------------\n\n";
		}
		else if (choice == 2) {
			cout << "command" << "   " << "view Pages liked " << endl;
			int user_id = 0;
			do {
				cout << "Enter user id :";
				cin >> user_id;
			} while (user_id < -1 && user_id > 20);
			u[user_id].printlikedpages();
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		else if (choice == 3) {
			cout << "command" << "   " << "view Post likes " << endl;
			int post_id = 0;
			do {
				cout << "Enter post id whose likes you want to view from 0 to 10:";
				cin >> post_id;
			} while (post_id < -1 && post_id > 11);
			posts[post_id].likes();
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		else if (choice == 4) {
			cout << "command" << "   " << "Like post" << endl;
			int post_id = 0;
			do {
				cout << "Enter post id which you want to like:";
				cin >> post_id;
			} while (post_id < -1 && post_id > 11);
			posts[post_id].setlikedpost(u[id]);
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		else if (choice == 5) {
			cout << "command" << "   " << "view Timeline liked " << endl;
			u[id].Timeline();
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		else if (choice == 6) {
			cout << "command" << "      " << "view Page" << endl;
			int page_id = 0;
			do {
				cout << "Enter page_id for page you want to view:";
				cin >> page_id;
			} while (page_id < -1 && page_id > 12);
			page[page_id].print();
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		else if (choice == 7) {
			cout << "command" << "    " << "view Homepage" << endl;
			u[id].HOmepage(day, m, y);
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		else if (choice == 8) {
			cout << "command" << "    " << "comment post" << endl;
			cout << "choose the post you want to comment: " << endl;
			for (int i = 0; i < 11; i++) {
				cout << "post_id= " << i << "  ";
				posts[i].print();
			}
			int post_id = 0;
			do {
				cout << "Enter post id:";
				cin >> post_id;
			} while (post_id < -1 && post_id > 11);
			cin.ignore();
			cout << "Enter your comment: ";
			string description = "";
			getline(cin, description);
			arr_com[noofcomms].setdes(description);
			arr_com[noofcomms].setid(noofcomms + 1);
			arr_com[noofcomms].setusers(u[id]);
			posts[post_id].setusercommentid(arr_com[noofcomms]);
			noofcomms++;
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
			cout << "command" << "      " << "view Post" << endl;
			posts[post_id].print();
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		else if (choice == 9) {
			cout << "command" << "      " << "view Post" << endl;
			int post_id = 0;
			do {
				cout << "Enter post id:";
				cin >> post_id;
			} while (post_id < -1 && post_id > 11);
			posts[post_id].print();
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		else if (choice == 10) {
			cout << "command" << "  " << "sharepost" << endl;
			int post_id = 0;
			do {
				cout << "Enter post id you want to share from 0 to 10:";
				cin >> post_id;
			} while (post_id < -1 && post_id > 11);
			u[0].setposts(posts[4]);
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
			cout << "command" << "  " << "View posts" << endl;
			u[0].printposts();
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		else if (choice == 11) {

			cout << "command" << "  " << "search()" << endl;
			cout << "Enter keyword by which you want to search any post";
			string word = "";
			cin >> word;
			activity::search(word, posts, u, page, arr_com);
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		else {
			cout << "Exited";
			break;
		}
	} while (choice != -1);


}
void activity::print() {

	if (getsharedpostbyuser() != nullptr) {

		cout << getsharedpostbyuser()->getnames() << "  " << getsharedpostbyuser()->getlname() << " ";
	}
	if (getsharedpostbypage() != nullptr) {
		cout << getsharedpostbypage()->getname() << " ";
	}
	int t = activity::gettype();
	if (t == 1)
		cout << "is feeling";
	else if (t == 2)
		cout << "Thinking about ";
	else if (t == 3)
		cout << "is Making";
	else if (t == 4)
		cout << "is celebrating";
	else if (t == 0)
		cout << " shared ";
	cout << activity::getvalue() << endl;

	Post::print();

}


Page:: ~Page() {
	delete[] postsids;
	postsids = nullptr;
	delete[] likedpeople;
	likedpeople = nullptr;
	delete[]posts;
	posts = nullptr;

};
Post ::~Post() {
	delete[]commids;
	commids = nullptr;
	delete[]likedpostsbyuser;
	likedpostsbyuser = nullptr;
	delete[]likedpostbypage;
	likedpostbypage = nullptr;
	sharedpostbyuser = nullptr;
	sharedpostbypage = nullptr;
	shareddate = nullptr;
}
user::~user() {

	delete[] pagesids;
	pagesids = nullptr;
	delete[] postsids;
	postsids = nullptr;
	delete[] userids;
	userids = nullptr;
	delete[] friends;
	friends = nullptr;
	delete[] posts;
	posts = nullptr;
	delete[] pages;
	pages = nullptr;
}
comment::~comment() {

	users = nullptr;
	delete[]pagename;
	pagename = nullptr;
}

